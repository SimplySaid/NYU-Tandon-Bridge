#include <iostream>
#include <vector>


std::vector<int> findMinAndMax(std::vector<int> nums, int left, int right) {
	if (right - left == 0)
		return std::vector<int> (nums[left], nums[left]);

	if (right - left == 1) {
		if (nums[left] >= nums[right])
			return std::vector<int> {nums[right], nums[left]};
		return std::vector<int> {nums[left], nums[right]};
	}
	std::vector<int> temp;

	if (findMinAndMax(nums, left, left + ((right - left) / 2))[0] <= findMinAndMax(nums, left + ((right - left) / 2), right)[0])
		temp.push_back(findMinAndMax(nums, left, left + ((right - left) / 2))[0]);
	else
		temp.push_back(findMinAndMax(nums, left + ((right - left) / 2), right)[0]);

	if (findMinAndMax(nums, left, left + ((right - left) / 2))[1] >= findMinAndMax(nums, left + ((right - left) / 2), right)[1])
		temp.push_back(findMinAndMax(nums, left, left + ((right - left) / 2))[1]);
	else
		temp.push_back(findMinAndMax(nums, left + ((right - left) / 2), right)[1]);

	return temp;
}


int main() {
	std::vector <int> test = { -10, 7, 1, 5, 2, 5, 111 };
	std::vector <int> res;

	res = findMinAndMax(test, 0, test.size() - 1);
	std::cout << "Min: " << res[0] << " | Max " << res[1];

	return 0;
}