#pragma once
#pragma once
using namespace std;
#include <vector>
class MergeStort
{
public:
	vector<int> v;
	vector<int> Sort(vector<int> nums);
private:
	vector<int> merge(vector<int> left, vector<int> right);
};
vector<int> MergeStort::Sort(vector<int> nums)
{
	nums.shrink_to_fit();
	vector<int> left, right;
	if (nums.size() <= 1)
		return nums;
	for (int x = 0; x < nums.size(); x++)
	{
		if (x % 2 == 0)
		{
			right.push_back(nums[x]);
		}
		else
		{
			left.push_back(nums[x]);
		}
	}

	vector<int> rightSorted = Sort(right);
	vector<int> leftSorted = Sort(left);

	return merge(rightSorted, leftSorted);

}
vector<int> MergeStort::merge(vector<int> left, vector<int> right)
{
	vector<int> result;
	while (right.size() > 0 && left.size() > 0)
	{
		if (left.front() <= right.front())
		{
			result.insert(result.end(), left.front());
			left.erase(left.begin());
		}
		else
		{
			result.insert(result.end(), right.front());
			right.erase(right.begin());
		}
	}
	while (right.size() > 0)
	{
		result.insert(result.end(), right.front());
		right.erase(right.begin());
	}
	while (left.size() > 0)
	{
		result.insert(result.end(), left.front());
		left.erase(left.begin());
	}
	return result;
}

