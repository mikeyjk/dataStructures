#include <iostream>

using namespace std;

int main()
{
	struct node
	{
		int info = 4;
		node* l = nullptr;
		node* r = nullptr;
	};

	node* test;

	node*& ref = test;

	cout << "test ptr: " << test << endl;
	cout << "test->info: " << test->info << endl;
	cout << "test->l: " << test->l << endl;
	cout << "test->r: " << test->r << endl;

	cout << "ref ptr: " << ref << endl;
	cout << "ref->info: " << ref->info << endl;
	cout << "ref->l: " << ref->l << endl;
	cout << "ref->r: " << ref->r << endl;

	return(1);
}
