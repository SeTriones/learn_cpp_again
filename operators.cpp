#include <iostream>
#include <string.h>

using namespace std;

class cls {
	friend cls operator+(const cls &a, const cls &b);
	friend cls operator-(const cls &a, const cls &b);
	friend ostream& operator<<(ostream &os, const cls &a);
public:
	cls() {
		memset(arr, 0, sizeof(arr));
	}

	cls(int array[3]) {
		memcpy(arr, array, sizeof(arr));
	}

	cls& operator=(const cls &a) {
		memcpy(arr, a.arr, sizeof(arr));
	}

	cls& operator++() {
		for (size_t i = 0; i < 3; i++) {
			arr[i]++;
		}
	}

	cls operator++(int) {
		cls ret = *this;
		for (size_t i = 0; i < 3; i++) {
			ret.arr[i]++;
		}
		return ret;
	}

	int& operator[](size_t idx) {
		return this->arr[idx];
	}

	const int& operator[](size_t idx) const {
		return this->arr[idx];
	}
private:
	int arr[3];
};

cls operator+(const cls &a, const cls &b) {
	cls ret;
	for (size_t i = 0; i < 3; i++) {
		ret.arr[i] = a.arr[i] + b.arr[i];
	}
	return ret;
}

cls operator-(const cls &a, const cls &b) {
	cls ret;
	for (size_t i = 0; i < 3; i++) {
		ret.arr[i] = a.arr[i] - b.arr[i];
	}
	return ret;
}

ostream& operator<<(ostream &os, const cls &a) {
	for (size_t i = 0; i < 2; i++) {
		os << a[i] << " ";
	}
	os << a[2] << std::endl;
	return os;
}

int main(int argc, char* argv[]) {
	int aa[3] = {100, 100, 100};
	int bb[3] = {5, 5, 5};
	cls a(aa);
	cls b(bb);
	std::cout << a + b;
	cls tmp;
	tmp = a - b;
	std::cout << tmp;
	cls x = tmp++;
	std::cout << tmp;
	std::cout << x;
	x = ++tmp;
	std::cout << tmp;
	std::cout << x;
	x[0] = 23;
	std::cout << x;
	return 0;

}
