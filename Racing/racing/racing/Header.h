#include <iostream>
#include <string>

class Car {
public:
	Car() : name("Unknown"), topSpeed(0), acceleration(0), cost(0), weight(0) {};
	Car(std::string name, int topSpeed, int acceleration, int cost, int weight) {};
	
	//Accessors
	std::string getName() {};
	int getTopSpeed() {};
	int getAccleration() {};
	int getCost() {};
	int getWeight() {};

	//Mutators
	void setTopSpeed(int topSpeed) {};
	void setAccleration(int acceleration) {};
	void setCost(int cost) {};
	void setWeight(int weight) {};

private:
	const std::string name;
	int topSpeed;
	int acceleration;
	int cost;
	int weight;
};