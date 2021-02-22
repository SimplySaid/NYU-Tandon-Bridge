#include <iostream>
#include <iomanip>

int main(){
	double firstItem, secondItem, taxRate, discountedPrice;
	char clubCard;

	//Take user input for item prices, club card 
	std::cout << "Enter price of first item: ";
	std::cin >> firstItem;

	std::cout << "Enter price of second item: ";
	std::cin >> secondItem;

	std::cout << "Does customer have a club card? (Y/N): ";
	std::cin >> clubCard;

	std::cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	std::cin >> taxRate;

	//Determine the cheaper of the two items and discounts that item by 50%
	if (firstItem >= secondItem) {
		discountedPrice = firstItem + (secondItem * .5);
	}
	else {
		discountedPrice = secondItem + (firstItem * .5);
	}

	//Calculate discount if member has club card
	if (clubCard == 'Y' || clubCard == 'y') {
		discountedPrice *= .9;
	}

	//Print out base price, price after discounts and total price
	std::cout << std::fixed;
	std::cout << "Base price: " << std::setprecision(2) << firstItem + secondItem << std::endl;
	std::cout << "Price after discounts: " << std::setprecision(2) << discountedPrice << std::endl;
	std::cout << "Total price: " << std::setprecision(2) << discountedPrice * (1.0 + (taxRate / 100.0)) << std::endl;

	return 0;
}