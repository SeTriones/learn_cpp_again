#include <iostream>
#include <iterator>

void print_array(int arr[10]) {
	for (size_t i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	// another name
	using my_array = int[10];
	typedef int my_array2[10];

	int arr1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int arr2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	// arr_ptr is pointer to int array with capacity 10
	int (*arr_ptr)[10] = &arr1;
	(*arr_ptr)[1] = 2;
	print_array(arr1);
	arr_ptr = &arr2;
	(*arr_ptr)[1] = 3;
	print_array(arr2);

	// arr_ref is reference to int array with capacity 10
	int (&arr_ref)[10] = arr1;
	arr_ref[2] = 4;
	print_array(arr1);

	int *a = std::begin(arr2);
	int *b = std::end(arr2);
	for (int *ptr = a; ptr != b; ptr++) {
		std::cout << *ptr << " ";
	}
	std::cout << std::endl;
	return 0;
}
