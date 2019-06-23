print(dir())


import mypackage.utilities

print(dir())

from mypackage.utilities import sumlists

print(dir())

print(mypackage.utilities.sumlists.__doc__)
print()

lst = sumlists([1,2,3,4,5], [90,80,70,60,50])
print(lst)
