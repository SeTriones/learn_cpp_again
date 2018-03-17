#include <iostream>

class my_class {
public:
	my_class(int _val): val(_val) {
	};
	
	void add(int x) {
		this->val += x;
	}

	void print1() {
		std::cout << this->val << std::endl;
	};

	void print2() const {
		std::cout << this->val << std::endl;
	}

private:
	int val;
};

int main(int argc, char* argv[]) {
	my_class c1(100);
	c1.add(1);
	c1.print1();
	c1.print2();
	const my_class c2 = c1;
	c2.print2();
	// expected a compile error here
	c2.print1();
	return 0;
}
