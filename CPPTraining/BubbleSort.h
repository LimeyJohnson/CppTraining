#pragma once
#include <vector>
using namespace std;
class BubbleSort
{
public:
	vector<int> Sort(vector<int> ar);
private:
	void Swap(int& a, int& b);
};

vector<int> BubbleSort::Sort(vector<int> ar)
{
	ar.shrink_to_fit();
	int size = ar.size();
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < (size - x); y++)
		{
			if (ar[x] < ar[y]) Swap(ar[x], ar[y]);
		}
	}
	return ar;
}
void BubbleSort::Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}