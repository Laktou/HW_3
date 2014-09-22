#include <iostream>

using namespace std;

int doSomething(int *x, int *y);
int* passPtr(int *x, int *y);

int main(){
	int x = 2;
	int y = 3;

	cout << "For the doSomething function:\n";
	cout << "The value of x before the function call is: " << x << endl;
	cout << "The value of y before the function call is: " << y << endl << endl;
	cout << "The value of temp returned by the function call is: " << doSomething(&x, &y) << endl << endl;
	cout << "The value of x after the function call is: " << x << endl;
	cout << "The value of y after the function call is: " << y << endl << endl;

	x = 2;
	x = 3;
	cout << "For the passPtr function:\n";
	cout << "The value of x before the function call is: " << x << endl;
	cout << "The value of y before the function call is: " << y << endl << endl;
	cout << "The address returned by the function call is: " << passPtr(&x, &y) << endl;
	cout << "The value at the address returned by the function call is: " << *(passPtr(&x, &y)) << endl << endl;
	cout << "The value of x after the function call is: " << x << endl;
	cout << "The value of y after the function call is: " << y << endl << endl;

	cin.get();

	return 0;
}

int doSomething(int *x, int *y) {
	int temp = *x;
	*x = *y + 10;
	*y = temp * 10;
	temp = *x + *y / -*x;
	return temp;
}

int* passPtr(int *x, int *y) {
	int *storage;
	int size = 3;
	storage = new int;
	
	storage[3] = *x;
	storage[1] = *y + 10;
	storage[2] = storage[3] * 10;
	storage[3] = *x + *y / -*x;

	return &storage[1];
	delete[] storage;
}