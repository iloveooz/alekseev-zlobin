#include <iostream>

class parent {
public:
	void parent_method() {
		std::cout << "parent_method()" << '\n';
	}
};

class child : public parent {
public:
	void child_method() {
		std::cout << "child_method()" << '\n';
	}
};

int main () {
	parent *p = new child();
	p->parent_method();

	((child *)p)->child_method();
	system("pause");
	return 0;
}
