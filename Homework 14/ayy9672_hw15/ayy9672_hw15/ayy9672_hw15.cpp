#include <iostream>
#include <fstream>
#include <string>

template <typename T>
class LinkedList {
public:
	LinkedList() : length(0), head(nullptr), tail(nullptr) {};
	~LinkedList();
	
	T getElement(int index) const;
	void addElement(T e);
	void removeElement(int index);
	void setElementAtIdx(T e, int idx);
	void sort(); //Bubble Sort cause lazy
	void swap(int i, int j);
	int getLength() const { return length; }

private:
	struct node {
		T data;
		node* next;
		node* prev;
	};
	int length;
	node* head;
	node* tail;
};

template <typename T>
LinkedList<T>::~LinkedList() {
	node* next = head;
	node* curr = nullptr;
	while (next != nullptr) {
		curr = next;
		next = next->next;
		delete curr;
	}
}

template <typename T>
T LinkedList<T>::getElement(int idx) const {
	node* currNodePtr = head;
	for (int i = 0; i < idx; ++i)
		currNodePtr = currNodePtr->next;
	return currNodePtr->data;
}

template <typename T>
void LinkedList<T>::addElement(T e) {
	node* newNode = new node();
	newNode->data = e;
	newNode->next = nullptr;
	if (head != nullptr) {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else {
		head = newNode;
		tail = newNode;
	}
	length++;
}

template <typename T>
void LinkedList<T>::setElementAtIdx(T e, int idx) {
	node* currNodePtr = head;
	for (int i = 0; i < idx; ++i)
		currNodePtr = currNodePtr->next;
	currNodePtr->data = e;
}

template <typename T>
void LinkedList<T>::removeElement(int idx) {
	node* currNodePtr = head;
	if (idx == 0) {
		head = currNodePtr->next;
		if (head == nullptr)
			tail = nullptr;
	}
	else {
		for (int i = 0; i < idx; ++i)
			currNodePtr = currNodePtr->next;
		node* temp = currNodePtr->prev;
		temp->next = currNodePtr->next;

		if (idx = length - 1)
			tail = currNodePtr->prev;

		temp = nullptr;
	}
	length--;
	delete currNodePtr;
	currNodePtr = nullptr;
}

template <typename T>
void LinkedList<T>::swap(int j, int k) {
	node* n1 = head;
	node* n2 = head;
	node* currNodePtr = head;
	for (int i = 0; i <= std::max(j, k); ++i) {
		if (i == j)
			n1 = currNodePtr;
		if (i == k)
			n2 = currNodePtr;
		currNodePtr = currNodePtr->next;
	}
	std::swap(n1->data, n2->data);
}

template <typename T>
void LinkedList<T>::sort() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length - i - 1; ++j) {
			if (getElement(j) < getElement(j + 1)) {
				swap(j, j+1);
			}
		}
	}
}

class Employee {
public:
	Employee() : id(0), payRate(0), name("NA"), hoursWorked(0) {};
	Employee(int newId, double newPayRate, std::string newName, int newHoursWorked) : id(newId), payRate(newPayRate), name(newName), hoursWorked(newHoursWorked) {};

	void printEmployeeInformation() { std::cout << name << ", $" << hoursWorked * payRate; }
	int getId() const { return id; }
	int getHoursWorked() const { return hoursWorked; }
	void setHoursWorked(int newHoursWorked) { hoursWorked = newHoursWorked; }
	bool operator <(const Employee& rhs) { return payRate * hoursWorked < rhs.payRate* rhs.hoursWorked; }
	bool operator >(const Employee& rhs) { return payRate * hoursWorked > rhs.payRate* rhs.hoursWorked; }

private:
	int id;
	double payRate;
	std::string name;
	int hoursWorked;
};

void openInputFile(std::ifstream& inFile) {
	std::string fileName;
	do
	{
		std::getline(std::cin, fileName);
		inFile.open(fileName);
		if (!inFile)
			std::cout << "File not found\n";
	} while (!inFile);
	inFile.clear();
}

int main() {
	LinkedList<Employee>* employeeList = new LinkedList<Employee>;
	
	std::cout << "Please enter employee file name:\n";
	std::ifstream employeeInputFile;
	openInputFile(employeeInputFile);

	
	int empId, payrollEmpId, payrollHoursWorked;
	double linePayRate;
	std::string lineString;
	
	while (employeeInputFile >> empId >> linePayRate) {
		std::getline(employeeInputFile, lineString);
		lineString.erase(0, 1);
		employeeList->addElement(Employee(empId, linePayRate, lineString, 0));
	}

	std::cout << "Please enter payroll file name:\n";
	std::ifstream payrollInputFile;
	openInputFile(payrollInputFile);
	while (payrollInputFile >> payrollEmpId >> payrollHoursWorked) {
		for (int i = 0; i < employeeList->getLength(); ++i) {
			if (employeeList->getElement(i).getId() == payrollEmpId) {
				Employee temp = employeeList->getElement(i);
				temp.setHoursWorked(temp.getHoursWorked() + payrollHoursWorked);
				employeeList->setElementAtIdx(temp, i);
				break;
			}
		}
	}

	employeeList->sort();

	std::cout << "*********Payroll Information********\n";
	for (int i = 0; i < employeeList->getLength(); ++i) {
		employeeList->getElement(i).printEmployeeInformation();
		std::cout << "\n";
	}
	std::cout << "*********End payroll**************";

	delete employeeList;

	return 0;
}

