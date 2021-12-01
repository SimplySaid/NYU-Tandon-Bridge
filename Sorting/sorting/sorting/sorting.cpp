/*
#include <iostream>
#include <string>

class Vehicle {
protected:
	std::string name;
	double velocity;
	int fuel;
	int maxFuel;
public:
	Vehicle() : name(""), velocity(0), fuel(0), maxFuel(0) {};
	Vehicle(std::string newName, double newVelocity, int newFuel, int newMaxFuel) : name(newName), velocity(newVelocity), fuel(newFuel), maxFuel(newMaxFuel) {};

	double getVelocity() const { return velocity; }
	std::string getName() const { return name; }
	int getFuel() const { return fuel; }
	int getMaxFuel() const { return maxFuel; }

	void setVelocity(double v) { velocity = v; }
	void setName(std::string n) { name = n; }
	void setFuel(int f) { fuel = f; }
	void setMaxFuel(int mf) { maxFuel = mf; }
};

class Car : public Vehicle {
private:
	std::string type;
public:
	Car() : Vehicle(), type("") {};
	Car(std::string newName, double newVelocity, int newFuel, int newMaxFuel, std::string newType) : Vehicle(newName, newVelocity, newFuel, newMaxFuel), type(newType) {};
};

int main() {
	return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <string>
//using namespace std;

/*
template <class T>
class AVLNode {
public:
	T data;
	AVLNode* lchild;
	AVLNode* rchild;
public:
	AVLNode() : lchild(nullptr), rchild(nullptr) {};
	AVLNode(T d) : lchild(nullptr), rchild(nullptr), data(d) {};

	T getData() const { return data; }
	void setData(T d) { data = d; }
};

template <class T>
class AVL {
	friend class AVLNode<T>;
private:
	AVLNode<T>* root;
public:
	AVL() {
		root = nullptr;
	};
	void insert(T e);
};

template <class T>
void AVL<T>::insert(T e) {
	if (root == nullptr)
		root = new AVLNode<T>(e);

	AVLNode<T>* currNodePtr = root;
	if (currNodePtr->lchild == nullptr && currNodePtr->rchild == nullptr) {
		if (e > currNodePtr->data) {
			currNodePtr->lchild = new AVLNode<T>(e);
			return;
		}
		else {
			currNodePtr->rchild = new AVLNode<T>(e);
			return;
		}
	}
	else if (currNodePtr->lchild == nullptr)
		currNodePtr = currNodePtr->rchild;
	else if (currNodePtr->rchild == nullptr)
		currNodePtr = currNodePtr->lchild;
	else {
		if (e > currNodePtr->data)
			currNodePtr= currNodePtr->lchild;
		else
			currNodePtr = currNodePtr->rchild;
	}
	currNodePtr = new AVLNode<T>(e);
}

int main() {
	AVL<int>* test = new AVL<int>();
	test->insert(5);
	test->insert(4);

	std::cout << "test";
}
*/

/*
template <class T>
class AVLTree {
public:
	class AVLTreeNode {
	public:
		AVLTreeNode* lchild;
		AVLTreeNode* rchild;
		AVLTreeNode* parent;
		T data;
	public:
		AVLTreeNode() : lchild(nullptr), rchild(nullptr), parent(nullptr), data(NULL) {};
		AVLTreeNode(AVLTreeNode* newParent, T newData) : lchild(nullptr), rchild(nullptr), parent(newParent), data(newData) {};
	};
	AVLTreeNode* root;
public:
	AVLTree() : root(new AVLTreeNode(nullptr, NULL)) {};

	AVLTreeNode* insert(AVLTreeNode* node, T e) {
		if (node == NULL) {
			std::cout << "test 2";
			return node = new AVLTreeNode(nullptr, e);
		}

		if (e < node->data)
			node->lchild = insert(node->lchild, e);
		else
			node->rchild = insert(node->rchild, e);
	}
};



int main() {
	AVLTree<int>* tree = new AVLTree<int>();
	tree->root->data = 0;
	tree->insert(nullptr, 1);
	tree->insert(nullptr, 2);

	std::cout << "test";
	return 0;
}
*/

/*
class Base {
public:
	Base() {}
	virtual void f() {
		std::cout << "BASE ";
	}
};
class Derived : public Base {
public:
	Derived() : Base() {}
	virtual void f() {
		std::cout << "DERIVED ";
	}
};
int main() {
	std::vector<Base> base_objs;
	std::cout << "\n---------------------------\n";
	Base obj1 = Derived();
	Derived obj2 = Derived();
	Base obj3 = Base();
	std::cout << "\n---------------------------\n";
	base_objs.push_back(obj1);
	base_objs.push_back(obj2);
	base_objs.push_back(obj3);
	for (Base base_obj : base_objs) {
		base_obj.f();
	}
	obj1.f();
	obj2.f();
	obj3.f();
	return 0;
}
*/

/*
class Person {
private:
	std::string name;
	int age;
public:
	virtual void move();
};

void Person::move() {
	return;
}
*/

/*
class A {
private:
	int x;
	int y;
public:
	A() : x(0), y(0) {
		std::cout << "Default constructor" << std::endl;
	}
	A(int x, int y) : x(x), y(y) {
		std::cout << "Constructor with two values" << std::endl;
	}
	A(const A& other) {
		std::cout << "Copy Constructor" << std::endl;
		x = other.x;
		y = other.y;
	}
};
int main() {
	A a(1, 2);
	A b = a;
	return 0;
}
*/

class Sorting {
	virtual void sort(std::vector<int> &v) = 0;
	virtual std::string worst_case_runtime() = 0;
};

class SelectionSort : public Sorting {
public:
	void sort(std::vector<int> &v) {
		for (int i = 0; i < v.size() - 1; ++i) {
			int tempMin = i;
			for (int j = i + 1; j < v.size(); ++j) {
				if (v[j] < v[tempMin])
					tempMin = j;
			}
			int temp = v[i];
			v[i] = v[tempMin];
			v[tempMin] = temp;
		}
	}

	std::string worst_case_runtime() { return "O(n^2)"; }
};

class QuickSort : public Sorting {
	void sort(std::vector<int> &v) {

	}

	std::string worst_case_runtime() { return "O(n^2)"; }
};

class MergeSort : public Sorting {
	void sort(std::vector<int> &v) {

	}

	std::string worst_case_runtime() { return "O(n log n)"; }
};

int main() {
	SelectionSort s;
	std::vector<int> test = { 1, 3, 5, 2, -1 };

	s.sort(test);

	for (int i = 0; i < test.size(); ++i)
		std::cout << test[i] << " ";

	return 0;
}