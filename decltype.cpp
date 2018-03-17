#include <iostream>

int main(int argc, char* argv[]) {
	int x = 100;
	int *ptr = &x;
	// m is a reference to x
	// because *ptr is a left value
	decltype(*ptr) m = x;
	m = 101;
	std::cout << x << std::endl;


	// mm is a reference to x
	// because (x) is a left value expression, but x is a variable
	decltype((x)) mm = x;
	mm++;
	std::cout << x << std::endl;
	return 0;
}
