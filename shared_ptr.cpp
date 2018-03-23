#include <iostream>
#include <memory>

using namespace std;

class cls {
public:
	cls() {
		idx = -1;
		cout << "default idx " << idx << endl;
	}

	cls(int i) {
		idx = i;
		cout << "idx " << idx << endl;
	}

	~cls() {
		cout << "clear idx " << idx << endl;
	}
private:
	int idx;	
};

int main(int argc, char* argv[]) {
	shared_ptr<cls> p1 = make_shared<cls>(100);
	shared_ptr<cls> p2 = p1;
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;
	return 0;
}
