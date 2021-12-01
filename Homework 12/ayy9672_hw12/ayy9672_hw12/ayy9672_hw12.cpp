//Hey sorry - I realized that my initial submission didn't save properly. I know it's 2 minutes passed deadline now so if you can't take this submission just take my original one thanks...

/*
You can copy and paste this entire block as an input directly into the program to test it
1010 $123.11 Y
1002 -$123.20 N
1003 $123.15 Y
1006 $124.31 N
1005 123.16 Y
1034 $.99 Y
1235 $1.11 N
-1
1000
500
200
300
-1
*/

//Program is written so checks can take negative numbers, and will also take dollar formats other than $123.00 (e.g., 123 or -$1 works)

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

class Money {
public:
	//Constructors
	Money(long dollars, int cents);
	Money(long dollars);
	Money();

	//Accessors
	double getValue() const;

	//Mutators
	void setValue(long all_cents);

	//Overloads
	friend Money operator +(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount1);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend bool operator <(const Money& amount1, const Money& amount2);

	friend std::ostream& operator<<(std::ostream& os, const Money& money);
	friend std::istream& operator>>(std::istream& is, Money& amount);
	
private:
	long all_cents;
};

Money::Money(long dollars, int cents) : all_cents(dollars * 100 + cents) {};
Money::Money(long dollars) : all_cents(dollars * 100) {};
Money::Money() : all_cents(0) {};

double Money::getValue() const {
	return (double)(all_cents / 100) + (double)(all_cents % 100) / 100;
}

void Money::setValue(long all_cents) {
	this->all_cents = all_cents;
}

Money operator +(const Money& amount1, const Money& amount2) {
	Money temp;
	temp.all_cents = amount1.all_cents + amount2.all_cents;
	return temp;
}

Money operator -(const Money& amount1, const Money& amount2) {
	Money temp;
	temp.all_cents = amount1.all_cents - amount2.all_cents;
	return temp;
}

Money operator -(const Money& amount1) {
	Money temp;
	temp.all_cents = -amount1.all_cents;
	return temp;
}

bool operator ==(const Money& amount1, const Money& amount2) {
	return amount1.all_cents == amount2.all_cents;
}

bool operator <(const Money& amount1, const Money& amount2) {
	return amount1.all_cents < amount2.all_cents;
}

std::ostream& operator<<(std::ostream& os, const Money& amount) {
	if (amount.all_cents >= 0)
		os << "$" << std::fixed << std::setprecision(2) << amount.getValue();
	else
		os << "-$" << std::fixed << std::setprecision(2) << amount.getValue() * -1;
	return os;
}

int stripDigits(std::string s) {
	int res = 0;
	int j = 0;
	for (int i = s.length() - 1; i >= 0; --i) {
		if (s[i] >= '0' && s[i] <= '9') {
			res += (s[i] - '0') * pow(10, j);
			j++;
		}
	}
	return res;
}

std::istream& operator>>(std::istream& is, Money& amount) {
	std::string temp;
	//std::getline(is, temp);
	is >> temp;
	int nxtIdx = temp.find('.');
	if (nxtIdx == -1)
		amount.all_cents = (stripDigits(temp)) * 100;
	else {
		amount.all_cents = stripDigits(temp.substr(0, nxtIdx)) * 100 + stripDigits(temp.substr(nxtIdx, std::string::npos));
	}
	if (temp[0] == '-')
		amount.all_cents *= -1;

	return is;
}

class Check {
public:
	//Constructors
	Check() : id(0), amount(0), cashed(false){};
	Check(int checkID, Money checkAmount, bool checkCashed) : id(checkID), amount(checkAmount), cashed(checkCashed) {};

	//Accessors
	int getID() const { return id; }
	Money getAmount() const { return amount; }
	bool getCashed() const { return cashed; }

	//Mutators
	void setAmount(long all_cents);
	void setCashed(bool cashed);

	//Overloads
	friend std::ostream& operator<<(std::ostream& os, const Check& chq);
	friend std::istream& operator>>(std::istream& is, Check& chq);

private:
	int id;
	Money amount;
	bool cashed;
};

void Check::setAmount(long all_cents) {
	amount.setValue(all_cents);
}

void Check::setCashed(bool cashed) {
	this->cashed = cashed;
}

Money calculateDeposits(std::vector<Money> deposits) {
	Money total;
	for (int i = 0; i < deposits.size(); ++i)
		total = total + deposits[i];
	return total;
}

Money calculateChecks(std::vector<Check> checks) {
	std::vector<Money> temp;
	
	for (int i = 0; i < checks.size(); ++i) {
		temp.push_back(checks[i].getAmount());
	}
	return calculateDeposits(temp);
}

std::ostream& operator<<(std::ostream& os, const Check& chq) {
	os << chq.id << " " << chq.amount << " ";
	if (chq.cashed)
		os << "Cashed";
	else
		os << "Not Cashed";
	return os;
}

std::istream& operator>>(std::istream& is, Check& chq) {
	char chqCashed;
	is >> chq.id;
	if (chq.id == -1)
			return is;

	is >> chq.amount >> chqCashed;
	if (chqCashed == 'Y' || chqCashed == 'y')
		chq.cashed = 1;
	else if (chqCashed == 'N' || chqCashed == 'n')
		chq.cashed = 0;
	return is;
}

int main() {
	std::vector<Money> userDeposits;
	std::vector<Check> userChecks;
	std::vector<Check> cashedChecks;
	std::vector<Check> uncashedChecks;

	Money userBalance;
	Money bankBalance;
	
	std::cout << "Please enter an ID, the amount and whether each check is cashed using Y or N e.g.,(1010 $123 Y) . Use a new line for each check. Use -1 to indicate end of input.\n";
	while (true) {
		Check temp;
		std::cin >> temp;
		if (temp.getID() == -1)
			break;

		userChecks.push_back(temp);
	}

	std::sort(userChecks.begin(), userChecks.end(), [](const Check& lhs, const Check& rhs) {
		return lhs.getID() < rhs.getID();
		});
	
	for (int i = 0; i < userChecks.size(); ++i) {
		if (userChecks[i].getCashed())
			cashedChecks.push_back(userChecks[i]);
		else
			uncashedChecks.push_back(userChecks[i]);
	}

	std::cout << "Please enter your current balance:\n";
	std::cin >> userBalance;

	std::cout << "Please enter the number of cash deposits separated by a new line. Use -1 to indicate end of input\n";
	while (true) {
		Money temp;
		std::cin >> temp;
		if (temp.getValue() == -1)
			break;

		userDeposits.push_back(temp);
	}

	std::cout << "\nYour old balance is: " << userBalance << "\n\n";

	bankBalance = userBalance - calculateChecks(cashedChecks) + calculateDeposits(userDeposits);
	std::cout << "Cashed checks:\n";
	for (int i = 0; i < cashedChecks.size(); ++i)
		std::cout << cashedChecks[i] << "\n";
	std::cout << "\nThe bank balance is " << bankBalance << "\n";

	userBalance = userBalance - calculateChecks(userChecks) + calculateDeposits(userDeposits);
	
	std::cout << "\nUncashed checks:\n";
	for (int i = 0; i < uncashedChecks.size(); ++i)
		std::cout << uncashedChecks[i] << "\n";
	std::cout << "\nYour new balance is: " << userBalance << "\n";

	std::cout << "Difference between bank balance and new balance is: " << userBalance - bankBalance;
	
	return 0;
}