#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int add(int a, int b) {
	std::cout << "add" << endl;
	return a + b;
}

struct addObj {
	int operator()(int a, int b) {
		std::cout << "addObj" << endl;
		return a + b;
	}
};

int another_add(int a, int b) {
	std::cout << "another_add" << endl;
	return a + b;
}

using add_func = int(*)(int, int);

int main(int argc, char* argv[]) {
	auto l = [](int a, int b) {
		std::cout << "lambda" << std::endl;
		return a + b;
	};
	std::vector<std::function<int(int, int)>> lst;
	lst.push_back(add);
	lst.push_back(addObj());
	lst.push_back(l);
	add_func my_func = &another_add;
	lst.push_back(my_func);
	for (size_t i = 0; i < lst.size(); i++) {
		int val = lst[i](1, 2);
		std::cout << val << std::endl;
	}
	return 0;
}
