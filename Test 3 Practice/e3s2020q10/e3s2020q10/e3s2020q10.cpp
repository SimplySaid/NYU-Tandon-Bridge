#include <iostream>

class Exam {
public:	
	virtual int const getResults() = 0;
	
	void setPoints(int pts) { points = pts; }
	void addPoints(int pts) { points += pts; }
	void subtractPoints(int pts) { points -= pts; }
	
	virtual void printResults() = 0;
protected:
	int points;
};

class WrittenExam : public Exam {
	int const getResults() {
		return points + 1;
	}

	void printResults() {
		std::cout << "You get +1 point for a written exam. Your total score is: " 
	}
};

class PracticalExam : public Exam {
	int const getResults() {
		return -points - 1;
	}
};

int main() {
	return 0;
}