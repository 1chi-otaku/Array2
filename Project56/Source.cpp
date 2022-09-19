#include <iostream>
#include "Array.h"
using namespace std;
int main() {
	srand(time(NULL));
	Array<int> obj(2, 8);
	obj.Random();
	obj.Multiply(6);
	obj.Print();
	Array<int> obj2 = obj;

	cout << endl;
	obj2.Print();






	return 0;
}