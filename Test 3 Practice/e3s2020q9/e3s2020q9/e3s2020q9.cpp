#include <iostream>
#include <list>

template <class T>
std::list<T> getSmallerThanValue(std::list<T> l, int v) {
	std::list<T> res;
	while (!l.empty()) {
		if (l.front() <= v)
			res.push_back(l.front());
		l.pop_front();
	}
	return res;
}


int main() {
	std::list<int> test = {5, 3, 1, 22, 11, 1, 2, 3, 4, 5, 10, 20, 25, 30, 35 };
	std::list<int> res;
	res = getSmallerThanValue(test, 12);

	for (auto v : res)
		std::cout << v << " ";

	return 0;
}