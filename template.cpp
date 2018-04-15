#include <iostream>
#include <string>

using namespace std;

template <typename T>
void foo(const T &t) {
	cout << "end " << t << endl;
}

template <typename T, typename... Args>
void foo(const T &t, Args & ... args) {
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
	cout << t << endl;
	foo(args...);
	return;
}

template <typename T>
T& print_single(T &t) {
	return t;
}

template <typename... Args>
void print(Args & ... args) {
	foo(print_single(args)...);
}

void test_template_parameter_packet() {
	int i = 0;
	float b = 3.2f;
	string s("test");
	cout << "1 paramter" << endl;
	foo(i);
	cout << "1+1 paramters" << endl;
	foo(i, b);
	cout << "1+2 paramters" << endl;
	foo(i, b, s);
	cout << "expand" << endl;
	print(i, b, s);
}

int main(int argc, char* argv[]) {
	test_template_parameter_packet();
	return 0;
}
