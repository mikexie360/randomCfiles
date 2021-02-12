#include <iostream>
#include <string>
#include "linkedList.h"

int main()
{
	std::cout << "Create list" << std::endl;
	linkedList<int> list;

	std::cout << "Print empty list" << std::endl;
	list.print();

	std::cout << "insert_after(12)" << std::endl;
	list.insert_after(nullptr, 12);

	std::cout << "Print list" << std::endl;
	list.print();

	std::cout << "insert_after(12, 13)" << std::endl;
	list.insert_after(list.find(12), 13);

	std::cout << "Print list" << std::endl;
	list.print();

	std::cout << "insert_after(12, 14)" << std::endl;
	list.insert_after(list.find(12), 14);

	std::cout << "Print list" << std::endl;
	list.print();

	std::cout << "insert_before(12, 15)" << std::endl;
	list.insert_before(list.find(12), 15);

	std::cout << "Print list" << std::endl;
	list.print();

	std::cout << "insert_before(12, 16)" << std::endl;
	list.insert_before(list.find(12), 16);

	std::cout << "Print list" << std::endl;
	list.print();

	// Pause system
	system("pause");

	return 0;
}