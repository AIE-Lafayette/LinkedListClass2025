#include "LinkedList.h"


int main()
{
	LinkedList<int> list1 = LinkedList<int>();

	list1.pushBack(1);
	list1.pushBack(2);
	list1.pushBack(3);

	list1.insert(4, 3);

	list1.print();

	return 0;
}