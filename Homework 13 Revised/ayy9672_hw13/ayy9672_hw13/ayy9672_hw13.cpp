#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>

class World;
class Organism;
class Ant;
class Doodlebug;

class Organism {
public:
	Organism() : organismWorld(), loc(std::make_pair(0, 0)), timeTillBreed(0), currTurn(0) {};
	Organism(World* newWorld, std::pair<int, int> newLoc, int newTimeTillBreed, int newCurrTurn) : organismWorld(newWorld), loc(newLoc), timeTillBreed(newTimeTillBreed), currTurn(newCurrTurn) {};

	virtual std::string name() const = 0;
	virtual void move();
	virtual ~Organism() = default;
	std::pair<int, int> getAdjacentCell(int dir);
	bool validCoordinate(std::pair<int, int> moveLoc);
protected:
	World* organismWorld;
	std::pair <int, int> loc;
	int timeTillBreed;
	int currTurn;
};

class Ant : public Organism {
public:
	Ant(World* newWorld, std::pair<int, int> newLoc, int newCurrTurn) : Organism(newWorld, newLoc, 3, newCurrTurn) {};
	std::string name() const { return "Ant"; }
	void move();
	void breed();
};

class Doodlebug : public Organism {
public:
	Doodlebug(World* newWorld, std::pair<int, int> newLoc, int newCurrTurn) : Organism(newWorld, newLoc, 8, newCurrTurn) { timeTillStarve = 3; }
	std::string name() const { return "Doodlebug"; }
	void move();
	void starve();
	void breed();
	std::vector<std::pair <int, int>> getNearbyAnts();
private:
	int timeTillStarve;
};

class World {
	friend class Organism;
	friend class Ant;
	friend class Doodlebug;
public:
	World() : map(20, std::vector <Organism*>(20)), rows(20), cols(20), globalTurn(0) {};
	World(int newRows, int newCols, int startingAnts, int startingDoodleBugs);

	int getGlobalTurn() const { return globalTurn; }
	void display();
	void simulateTurn();
private:
	std::vector<std::vector<Organism*>> map;
	int rows;
	int cols;
	int globalTurn;
};

std::pair<int, int> Organism::getAdjacentCell(int dir) {
	std::pair <int, int> newLoc = loc;
	if (dir == 1)
		newLoc.first += 1;
	else if (dir == 2)
		newLoc.first -= 1;
	else if (dir == 3)
		newLoc.second += 1;
	else if (dir == 4)
		newLoc.second -= 1;
	return newLoc;
}

bool Organism::validCoordinate(std::pair<int, int> moveLoc) {
	return (moveLoc.first >= 0 && moveLoc.first < organismWorld->rows) && (moveLoc.second >= 0 && moveLoc.second < organismWorld->cols);
}

void Organism::move() {
	if (currTurn != organismWorld->getGlobalTurn() - 1) { return; }
	currTurn++;
	timeTillBreed--;
	std::pair <int, int> randomLoc = getAdjacentCell(rand() % 4 + 1);
	if (validCoordinate(randomLoc) && organismWorld->map[randomLoc.first][randomLoc.second] == nullptr) {
		organismWorld->map[loc.first][loc.second] = nullptr;
		delete organismWorld->map[randomLoc.first][randomLoc.second];
		organismWorld->map[randomLoc.first][randomLoc.second] = this;
		loc = randomLoc;
	}
}

void Ant::breed() {
	if (timeTillBreed != 0) { return; }
	//std::vector<int> randomDirs{ 1,2,3,4 };
	for (int i = 1; i <= 4; ++i) {
		std::pair<int, int> randomLoc = getAdjacentCell(i);
		if (validCoordinate(randomLoc) && organismWorld->map[randomLoc.first][randomLoc.second] == nullptr) {
			organismWorld->map[randomLoc.first][randomLoc.second] = new Ant(organismWorld, randomLoc, this->currTurn);
			timeTillBreed = 3;
			return;
		}
	}
}

void Ant::move() {
	Organism::move();
	Ant::breed();
}

std::vector<std::pair <int, int>> Doodlebug::getNearbyAnts() {
	std::vector<std::pair <int, int>> nearbyAnts;
	for (int i = 1; i <= 4; ++i) {
		std::pair <int, int> tempLoc = getAdjacentCell(i);
		if (!validCoordinate(tempLoc)) { continue; }
		if (organismWorld->map[tempLoc.first][tempLoc.second] != nullptr && organismWorld->map[tempLoc.first][tempLoc.second]->name() == "Ant")
			nearbyAnts.push_back(tempLoc);
	}
	return nearbyAnts;
}

void Doodlebug::breed() {
	if (timeTillBreed != 0) { return; }
	//std::vector<int> randomDirs{ 1,2,3,4 };
	for (int i = 1; i <= 4; ++i) {
		std::pair<int, int> randomLoc = getAdjacentCell(i);
		if (validCoordinate(randomLoc) && organismWorld->map[randomLoc.first][randomLoc.second] == nullptr) {
			organismWorld->map[randomLoc.first][randomLoc.second] = new Doodlebug(organismWorld, randomLoc, this->currTurn);
			timeTillBreed = 8;
			return;
		}
	}
}

void Doodlebug::starve() {
	organismWorld->map[loc.first][loc.second] = nullptr;
	delete this;
}

void Doodlebug::move() {
	std::vector<std::pair<int, int>> nearbyAnts = getNearbyAnts();
	if (nearbyAnts.size() == 0) {
		if (currTurn != organismWorld->getGlobalTurn() - 1) { return; }
		Organism::move();
		timeTillStarve--;
	}
	else {
		if (currTurn != organismWorld->getGlobalTurn() - 1) { return; }
		int randomIdx = rand() % nearbyAnts.size();
		organismWorld->map[loc.first][loc.second] = nullptr;
		delete organismWorld->map[nearbyAnts[randomIdx].first][nearbyAnts[randomIdx].second];
		organismWorld->map[nearbyAnts[randomIdx].first][nearbyAnts[randomIdx].second] = this;
		loc = nearbyAnts[randomIdx];
		timeTillBreed--;
		timeTillStarve = 3;
		currTurn++;
	}
	if (timeTillStarve == 0) {
		starve();
		return;
	}
	Doodlebug::breed();
}

World::World(int newRows, int newCols, int startingAnts, int startingDoodleBugs) : map(newRows, std::vector <Organism*>(newCols)), rows(newRows), cols(newCols), globalTurn(0) {
	while (startingDoodleBugs > 0) {
		std::pair<int, int> randCord = std::make_pair(rand() % 20, rand() % 20);
		if (map[randCord.first][randCord.second] == nullptr) {
			map[randCord.first][randCord.second] = new Doodlebug(this, randCord, 0);
			startingDoodleBugs--;
		}
	}
	while (startingAnts > 0) {
		std::pair<int, int> randCord = std::make_pair(rand() % 20, rand() % 20);
		if (map[randCord.first][randCord.second] == nullptr) {
			map[randCord.first][randCord.second] = new Ant(this, randCord, 0);
			startingAnts--;
		}
	}
};

void World::simulateTurn() {
	globalTurn++;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (map[i][j] == nullptr) { continue; }
			if (map[i][j]->name() == "Doodlebug")
				map[i][j]->move();
		}
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (map[i][j] == nullptr) { continue; }
			if (map[i][j]->name() == "Ant")
				map[i][j]->move();
		}
	}
}

void World::display() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (map[i][j] == nullptr)
				std::cout << "-";
			else if (map[i][j]->name() == "Ant")
				std::cout << "o";
			else if (map[i][j]->name() == "Doodlebug")
				std::cout << "X";
			std::cout << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	srand(time(0));

	World simulation(20, 20, 100, 5);
	
	std::string input;
	simulation.display();
	while (true) {
		std::getline(std::cin, input);
		if (input == "-1")
			break;

		simulation.simulateTurn();
		simulation.display();
		std::cout << "\n\n";
	}

	simulation.display();
}