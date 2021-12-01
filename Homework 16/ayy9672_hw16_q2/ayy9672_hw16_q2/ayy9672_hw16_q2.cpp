#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Queue {
private:
	std::vector<T> data;
	int sIdx;
	int eIdx;
public:
	Queue() : sIdx(0), eIdx(0) {};

	void enqueue(T);
	void dequeue();
	T front();
	bool empty();

	void printQueue();
};

template <typename T>
bool Queue<T>::empty() {
	return sIdx >= eIdx;
}

template <typename T>
void Queue<T>::enqueue(T e) {
	data.push_back(e);
	eIdx++;
}

template <typename T>
void Queue<T>::dequeue() {
	if (sIdx + 1 >= eIdx) {
		sIdx = 0;
		eIdx = 0;
		data.clear();
	}
	else
		sIdx++;
}

template <typename T>
T Queue<T>::front() {
	if (!empty())
		return data[sIdx];
	else
		std::cout << "Queue is empty";
}

template <typename T>
void Queue<T>::printQueue() {
	for (int i = sIdx; i < eIdx; ++i)
		std::cout << data[i] << " ";
	std::cout << "\n";
}

int main() {
	Queue<int> intTest;
	
	intTest.enqueue(0);
	intTest.enqueue(1);
	intTest.enqueue(2);
	intTest.enqueue(3);

	intTest.dequeue();
	intTest.dequeue();
	intTest.dequeue();
	//intTest.dequeue();
	//intTest.dequeue();

	intTest.printQueue();
	intTest.front();

	Queue<std::string> strTest;

	strTest.enqueue("test1");
	strTest.enqueue("test2");
	strTest.enqueue("test3");
	strTest.enqueue("test4");

	strTest.printQueue();

	std::cout << strTest.front() << "\n";
	strTest.dequeue();
	std::cout << strTest.front() << "\n";

	strTest.printQueue();
	strTest.dequeue();
	strTest.dequeue();
	strTest.dequeue();
	strTest.dequeue();

	strTest.enqueue("zzz");

	strTest.printQueue();

	return 0;
}