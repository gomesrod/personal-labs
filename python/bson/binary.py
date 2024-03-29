# Copyright 2009-2012 10gen, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

try:
    from uuid import UUID
except ImportError:
    # Python2.4 doesn't have a uuid module.
    pass

from bson.py3compat import PY3, binary_type

"""Tools for representing BSON binary data.
"""

BINARY_SUBTYPE = 0
"""BSON binary subtype for binary data.

This is the default subtype for binary data.

.. versionadded:: 1.5
"""

FUNCTION_SUBTYPE = 1
"""BSON binary subtype for functions.

.. versionadded:: 1.5
"""

OLD_BINARY_SUBTYPE = 2
"""Old BSON binary subtype for binary data.

This is the old default subtype, the current
default is :data:`BINARY_SUBTYPE`.

.. versionadded:: 1.7
"""

OLD_UUID_SUBTYPE = 3
"""Old BSON binary subtype for a UUID.

:class:`uuid.UUID` instances will automatically be encoded
by :mod:`bson` using this subtype.

.. versionadded:: 2.1
"""

UUID_SUBTYPE = 4
"""BSON binary subtype for a UUID.

This is the new BSON binary subtype for UUIDs. The
current default is :data:`OLD_UUID_SUBTYPE` but will
change to this in a future release.

.. versionchanged:: 2.1
   Changed to subtype 4.
.. versionadded:: 1.5
"""

JAVA_LEGACY = 5
"""Used with :attr:`pymongo.collection.Collection.uuid_subtype`
to specify that UUIDs should be stored in the legacy byte order
used by the Java driver.

:class:`uuid.UUID` instances will automatically be encoded
by :mod:`bson` using :data:`OLD_UUID_SUBTYPE`.

.. versionadded:: 2.3
"""

CSHARP_LEGACY = 6
"""Used with :attr:`pymongo.collection.Collection.uuid_subtype`
to specify that UUIDs should be stored in the legacy byte order
used by the C# driver.

:class:`uuid.UUID` instances will automatically be encoded
by :mod:`bson` using :data:`OLD_UUID_SUBTYPE`.

.. versionadded:: 2.3
"""

ALL_UUID_SUBTYPES = (OLD_UUID_SUBTYPE, UUID_SUBTYPE, JAVA_LEGACY, CSHARP_LEGACY)

MD5_SUBTYPE = 5
"""BSON binary subtype for an MD5 hash.

.. versionadded:: 1.5
"""

USER_DEFINED_SUBTYPE = 128
"""BSON binary subtype for any user defined structure.

.. versionadded:: 1.5
"""


class Binary(binary_type):
    """Representation of BSON binary data.

    This is necessary because we want to represent Python strings as
    the BSON string type. We need to wrap binary data so we can tell
    the difference between what should be considered binary data and
    what should be considered a string when we encode to BSON.

    Raises TypeError if `data` is not an instance of :class:`str`
    (:class:`bytes` in python 3) or `subtype` is not an instance of
    :class:`int`. Raises ValueError if `subtype` is not in [0, 256).

    .. note::
      In python 3 instances of Binary with subtype 0 will be decoded
      directly to :class:`bytes`.

    :Parameters:
      - `data`: the binary data to represent
      - `subtype` (optional): the `binary subtype
        <http://bsonspec.org/#/specification>`_
        to use
    """

    def __new__(cls, data, subtype=BINARY_SUBTYPE):
        if not isinstance(data, binary_type):
            raise TypeError("data must be an "
                            "instance of %s" % (binary_type.__name__,))
        if not isinstance(subtype, int):
            raise TypeError("subtype must be an instance of int")
        if subtype >= 256 or subtype < 0:
            raise ValueError("subtype must be contained in [0, 256)")
        self = binary_type.__new__(cls, data)
        self.__subtype = subtype
        return self

    @property
    def subtype(self):
        """Subtype of this binary data.
        """
        return self.__subtype

    def __getnewargs__(self):
        # Work around http://bugs.python.org/issue7382
        data = super(Binary, self).__getnewargs__()[0]
        if PY3 and not isinstance(data, binary_type):
            data = data.encode('latin-1')
        return data, self.__subtype

    def __eq__(self, other):
        if isinstance(other, Binary):
            return ((self.__subtype, binary_type(self)) ==
                    (other.subtype, binary_type(other)))
        # We don't return NotImplemented here because if we did then
        # Binary("foo") == "foo" would return True, since Binary is a
        # subclass of str...
        return False

    def __ne__(self, other):
        return not self == other

    def __repr__(self):
        return "Binary(%s, %s)" % (binary_type.__repr__(self), self.__subtype)


class UUIDLegacy(Binary):
    """UUID wrapper to support working with UUIDs stored as legacy
    BSON binary subtype 3.

    .. doctest::

      >>> import uuid
      >>> from bson.binary import Binary, UUIDLegacy, UUID_SUBTYPE
      >>> my_uuid = uuid.uuid4()
      >>> coll = db.test
      >>> coll.uuid_subtype = UUID_SUBTYPE
      >>> coll.insert({'uuid': Binary(my_uuid.bytes, 3)})
      ObjectId('...')
      >>> coll.find({'uuid': my_uuid}).count()
      0
      >>> coll.find({'uuid': UUIDLegacy(my_uuid)}).count()
      1
      >>> coll.find({'uuid': UUIDLegacy(my_uuid)})[0]['uuid']
      UUID('...')
      >>>
      >>> # Convert from subtype 3 to subtype 4
      >>> doc = coll.find_one({'uuid': UUIDLegacy(my_uuid)})
      >>> coll.save(doc)
      ObjectId('...')
      >>> coll.find({'uuid': UUIDLegacy(my_uuid)}).count()
      0
      >>> coll.find({'uuid': {'$in': [UUIDLegacy(my_uuid), my_uuid]}}).count()
      1
      >>> coll.find_one({'uuid': my_uuid})['uuid']
      UUID('...')

    Raises TypeError if `obj` is not an instance of :class:`~uuid.UUID`.

    :Parameters:
      - `obj`: An instance of :class:`~uuid.UUID`.
    """

    def __new__(cls, obj):
        if not isinstance(obj, UUID):
            raise TypeError("obj must be an instance of uuid.UUID")
        # Python 3.0(.1) returns a bytearray instance for bytes (3.1 and
        # newer just return a bytes instance). Convert that to binary_type
        # for compatibility.
        self = Binary.__new__(cls, binary_type(obj.bytes), OLD_UUID_SUBTYPE)
        self.__uuid = obj
        return self

    def __getnewargs__(self):
        # Support copy and deepcopy
        return (self.__uuid,)

    @property
    def uuid(self):
        """UUID instance wrapped by this UUIDLegacy instance.
        """
        return self.__uuid

    def __repr__(self):
        return "UUIDLegacy('%s')" % self.__uuid
