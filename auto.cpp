#include <iostream>

int main(int argc, char* argv[]) {
	// auto remove top-level const, but keeps low-level const
	int i = 0;
	const int x = 100, x_ref = x;
	
	// a is int
	auto a = x;
	a++;
	std::cout << "a=" << a << std::endl;

	// b is int
	auto b = x_ref;
	b = b + 2;
	std::cout << "b=" << b << std::endl;

	// p1 is int*
	auto p1 = &i;
	*p1 = 1;
	std::cout << "i=" << i << std::endl;

	int arr[] = {1, 2, 3};
	// auto changes array to pointer
	auto p = arr;
	*p = 100;
	for (size_t i = 0; i < 3; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// p2 is const int*
	auto p2 = &x;
	// you get a error here
	*p2 = 101;
	return 0;
}
