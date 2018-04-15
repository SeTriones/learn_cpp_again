#include <iostream>
#include <string>

using namespace std;

template <typename T, typename... Args>
void foo(const T &t, Args & ... args) {
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
	return;
}

void test_template_parameter_packet() {
	int i = 0;
	float b = 3.2f;
	string s("test");
	foo(i);
	foo(i, b);
	foo(i, b, s);
}

int main(int argc, char* argv[]) {
	test_template_parameter_packet();
	return 0;
}
