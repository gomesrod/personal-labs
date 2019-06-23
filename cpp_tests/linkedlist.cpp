#include <iostream>
#include <string>

template <class T>
class LinkedList
{
	public:
		LinkedList();

		void add(T elem);
		T get(int index);
		void remove(int index);
		int count();

	private:
		struct LinkedListItem
		{
			T value;
			LinkedListItem * next;
		};

		LinkedListItem* first_;
		LinkedListItem* last_;
		int count_;
};

int main()
{
	using std::string;
	using std::cout;
	using std::endl;

	LinkedList<string> listStr;
	cout << "Count: " << listStr.count() << endl;

	listStr.add("primeiro");
	listStr.add("segundo");
	listStr.add("terceiro");
	cout << "Count after add: " << listStr.count() << endl;

	cout << ":::: Listing elements ::::::" << endl;
	for (int i = 0; i < listStr.count(); i++) {
		cout << listStr.get(i) << endl;
	}
	cout << ":::: End" << endl;


	LinkedList<int> listInt;
	cout << "Count: " << listInt.count() << endl;

	listInt.add(101010);
	listInt.add(202020);
	listInt.add(303030);
	cout << "Count after add: " << listInt.count() << endl;

	cout << ":::: Listing elements ::::::" << endl;
	for (int i = 0; i < listInt.count(); i++) {
		cout << listInt.get(i) << endl;
	}
}

template <class T>
LinkedList<T>::LinkedList()
{
	count_ = 0;
}

template <class T>
void LinkedList<T>::add(T elem)
{
	LinkedListItem* newItem = new LinkedListItem;
	newItem->value = elem;

	if (count_ == 0) {
		first_ = newItem;
	} else {
		last_->next = newItem; // Put as the next to the previously last element.
	}

	last_ = newItem;       // Take place as the last.
	count_++;
}

template <class T>
T LinkedList<T>::get(int index)
{
	if (index > count_ - 1) {
		throw "OutOfBounds";
	}

	LinkedListItem* item = first_;


	for (int i = 1; i <= index; i++) {
		item = item->next;
	}

	return item->value;
}

template <class T>
void LinkedList<T>::remove(int index)
{

}

template <class T>
int LinkedList<T>::count()
{
	return count_;
}

