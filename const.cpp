#include <iostream>

int main(int argc, char* argv[]) {
	// const reference cna be binded to literal value/expression/non-const values
	int x = 44;
	const int &a = x;
	const int &r = 44;
	const int &b = x * x;

	// top-level const and low-level const
	// top-level
	int *const ptr1 = &x;
	// low-level
	const int* ptr2 = &x;
	const int &ref = x;

	return 0;
}
