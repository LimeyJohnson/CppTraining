#pragma once
using namespace std;
#include <vector>
class QuickSort
{
public:
	vector<int> v;
	vector<int> Sort(vector<int> nums);
private:
	void quicksort(int hi, int low);
	int partition(int hi, int low);
	void Swap(int& a, int& b);
};
vector<int> QuickSort::Sort(vector<int> nums)
{
	v.shrink_to_fit();
	v = nums;
	quicksort(v.size() -1 ,0);
	return v;
}
void QuickSort::quicksort(int hi, int low)
{
	if (low < hi)
	{
		int part = partition(hi, low);
		quicksort(hi, part + 1);
		quicksort(part - 1, low);
	}
}
int QuickSort::partition(int hi, int low)
{
	int pivot = v[hi];
	int i = low;
	for (int x = low; x < hi; x++)
	{
		if (v[x] <= pivot)
		{
			Swap(v[i], v[x]);
			i++;
		}
	}
	Swap(v[i], v[hi]);
	return i;
}
void QuickSort::Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}