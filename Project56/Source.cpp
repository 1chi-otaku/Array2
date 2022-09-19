#include <iostream>
#include "Array.h"
using namespace std;
int main() {
	srand(time(NULL));
	Array<int> obj(2, 8);
	
	obj.Random();
	obj.Print();
	cout << endl;
	Array<int> obj2(obj-1);
	obj2.Print();
	cout << endl;
	Array<int> obj4(obj + 1);
	obj4.Print();
	cout << endl;
	Array<int> obj3(obj/10);
	obj3.Print();
	cout << endl;
	Array<int> obj5(obj * 10);
	obj5.Print();
	cout << endl;
	obj.Print();





	return 0;
}