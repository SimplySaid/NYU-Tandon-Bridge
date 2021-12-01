#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <time.h>

class Organism {
protected:
	int breedCooldown;
	int turn;
	int rank;

public:
	//Constructors
	Organism() : breedCooldown(0), turn(0), rank(0) {};
	Organism(int newBreedCooldown, int newRank) : breedCooldown(newBreedCooldown), turn(0), rank(newRank) {};
	~Organism() {};

	//Accesors
	int getBreedCooldown() const {return breedCooldown;}
	int getTurn() const { return turn; }
	int getRank() const { return rank; }
	virtual std::string name() const = 0 {};
	//Mutators
	
	virtual void move(Organism* tarLocOrganism);
	virtual void breed() { this->breedCooldown = 3; }
};

void Organism::move(Organism* tarLocOrganism) {
	turn++;
}

class Ant : public Organism {
public:
	Ant() : Organism(3, 1) {};
	void move(Organism* tarLocOrganism);
	void breed() {this->breedCooldown = 3;}
	std::string name() const { return "Ant"; }
private:
};

void Ant::move(Organism* tarLocOrganism) {
	Organism::move(tarLocOrganism);
	if (tarLocOrganism != nullptr) {
		breedCooldown--;
	}
}

class Doodlebug : public Organism {
public:
	Doodlebug() : Organism(8, 2) {};
	int starveCooldown;
	void move(Organism* tarLocOrganism);
	void breed() { this->breedCooldown = 8; }
	std::string name() const { return "Doodlebug"; }
private:
};

void Doodlebug::move(Organism* tarLocOrganism) {
	Organism::move(tarLocOrganism);
	if (tarLocOrganism != nullptr && tarLocOrganism->name() == "Ant") {
		starveCooldown = 3;
		breedCooldown--;
	}
	else
		starveCooldown--;
}

class World {
public:
	//Constructor
	World() : map(20, std::vector <Organism*>(20)), rows(20), cols(20), worldTurn(0) {};
	World(int newRows, int newCols, int startingAnts, int startingDoodleBugs);

	//Accessors
	std::vector<std::vector<Organism*>> getMap() const { return map; }
	Organism* getOrganism(int row, int col) const;

	//Mutators
	void setOrganism(Organism* o, int row, int col);

	//Functions
	std::pair<int, int> getAdjacentCell(int dir, std::pair<int, int> currLoc);
	bool validMoveLocation(Organism* o, std::pair<int, int> tarLoc);
	void display();
	void move();
private:
	std::vector<std::vector<Organism*>> map;
	int rows;
	int cols;
	int worldTurn;
};

World::World(int newRows, int newCols, int startingAnts, int startingDoodleBugs) : map(newRows, std::vector <Organism*>(newCols)), rows(newRows), cols(newCols), worldTurn(0) {
	while (startingDoodleBugs > 0) {
		std::pair<int, int> randomCoordinate = std::make_pair(rand() % 20, rand() % 20);
		if (map[randomCoordinate.first][randomCoordinate.second] == nullptr) {
			map[randomCoordinate.first][randomCoordinate.second] = new Doodlebug();
			startingDoodleBugs--;
		}
	}
	while (startingAnts > 0) {
		std::pair<int, int> randomCoordinate = std::make_pair(rand() % 20, rand() % 20);
		if (map[randomCoordinate.first][randomCoordinate.second] == nullptr) {
			map[randomCoordinate.first][randomCoordinate.second] = new Ant();
			startingAnts--;
		}
	}
};

void World::display() {
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			if(map[i][j] == nullptr)
				std::cout << "-";
			else if(map[i][j]->name() == "Ant")
				std::cout << "o";
			else if (map[i][j]->name() == "Doodlebug")
				std::cout << "X";
			std::cout << " ";
		}
		std::cout << "\n";
	}
}

std::pair<int, int> World::getAdjacentCell(int dir, std::pair<int, int> currLoc) {
	if (dir == 1)
		currLoc.first += 1;
	else if (dir == 2)
		currLoc.first -= 1;
	else if (dir == 3)
		currLoc.second += 1;
	else if (dir == 4)
		currLoc.second -= 1;
	
	if ((currLoc.first >= 0 && currLoc.first < rows) && (currLoc.second >= 0 && currLoc.second < cols))
		return currLoc;
	return std::make_pair(-1, -1);
}

bool World::validMoveLocation(Organism* o, std::pair<int, int> tarLoc) {
	if (tarLoc.first == -1)
		return false;
	else if (map[tarLoc.first][tarLoc.second] == nullptr)
		return true;
	else return o->getRank() > map[tarLoc.first][tarLoc.second]->getRank();
}

void World::move() {
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			if (map[i][j] != nullptr && map[i][j]->name() == "Doodlebug" && (map[i][j]->getTurn() == worldTurn)) {
				std::pair<int, int> randomCell = getAdjacentCell(rand() % 4 + 1, std::make_pair(i, j));
				if (validMoveLocation(map[i][j], randomCell)) {
					map[i][j]->move(map[randomCell.first][randomCell.second]);
					map[randomCell.first][randomCell.second] = map[i][j];
					map[i][j] = nullptr;
					int d = 1;
					while (map[randomCell.first][randomCell.second]->getBreedCooldown() == 0 && d <= 4) {
						std::pair<int, int> breedCell = getAdjacentCell(d, randomCell);
						if (breedCell.first != -1 && map[breedCell.first][breedCell.second] == nullptr) {
							map[breedCell.first][breedCell.second] = new Doodlebug();
							map[randomCell.first][randomCell.second]->breed();
							break;
						}
						d++;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			if (map[i][j] != nullptr && map[i][j]->name() == "Ant" && (map[i][j]->getTurn() == worldTurn)) {
				std::pair<int, int> randomCell = getAdjacentCell(rand() % 4 + 1, std::make_pair(i, j));
				if (validMoveLocation(map[i][j], randomCell)) {
					map[i][j]->move(map[randomCell.first][randomCell.second]);
					map[randomCell.first][randomCell.second] = map[i][j];
					map[i][j] = nullptr;
					int d = 1;
					while (map[randomCell.first][randomCell.second]->getBreedCooldown() == 0 && d <= 4) {
						std::pair<int, int> breedCell = getAdjacentCell(d, randomCell);
						if (breedCell.first != -1 && map[breedCell.first][breedCell.second] == nullptr) {
							std::cout << "test";
							map[breedCell.first][breedCell.second] = new Ant();
							map[randomCell.first][randomCell.second]->breed();
							break;
						}
						d++;
					}
				}

			}
		}
	}
	worldTurn++;
}

Organism* World::getOrganism(int row, int col) const {
	return map[row][col];
}

void World::setOrganism(Organism* o, int row, int col) {
	delete map[row][col];
	map[row][col] = o;
}

int main() {
	srand(time(0));

	World test(20, 20, 100, 5);
	test.display();
	std::cout << "\n\n";

	for (int i = 0; i < 10; ++i) {
		test.move();
		test.display();
		std::cout << "\n\n";
	}
	return 0;
}
