#include <iostream>
#include <string>

using namespace std;

class cls {
public:
	cls() :val(0), str("null"){
	}

	cls(const cls &peer): val(peer.val), str(peer.str){
		cout << "copy constructor" << endl;
	}

	cls& operator= (const cls& peer) {
		this->val = peer.val;
		this->str = peer.str;
		cout << "assign" << endl;
	}

private:
	int val;
	string str;
};

int main(int argc, char* argv[]) {
	cls c1;
	cout << "c1 done" << endl;
	cls c2(c1);
	cout << "c2 done" << endl;
	cls c3 = c2;
	cout << "c3 done" << endl;
	cls c4;
	c4 = c3;
	return 0;
}
