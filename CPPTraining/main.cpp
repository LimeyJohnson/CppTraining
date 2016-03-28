#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "splitbuffer.h"
#include "linkedlist.h"
#include "netmethod.h"
#include "Node.h"
#include "BinaryTree.h"
#include "StringNode.h"
#include "List.h"
#include "HashMap.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
using namespace std;


int find(int x){
    int count=0;
    while(x>0){
        if(x&0x1)count++;
        x = x>>1;
    }
    return count;

}
void testSplitBuffer()
{
	SplitBuffer* sb = new SplitBuffer(20);
	sb->Add("I want to add a lot of text here to show that even the new buffer should be overrun creating the need to double the buffer more than once. ");
	sb->SetPoint(0);
	cout<< sb->toString()<<endl;
	sb->Add("To test this part of the code I am going to add this sentence before the other sentence so that the buffer really has to work hard to figure out what is going on. ");
	sb->SetPoint(0);
	sb->Add("To be or not to be that is the question. I never understood why that was the question, it seemed a bit like a tautology to me. The thing we need to be sure of is that we still manage to overrun the buffer one more time, or this string trying to overrun the other string just isn't going to work.");
	sb->SetPoint(41);
	sb->Add("This setence needs to come right after to be or not to be sentence. ");
	cout<< sb->toString()<<endl ;
	delete sb;
}
void testLinkedList()
{
//	LinkedList<char> ll('A');
//	ll.add('n');
//	ll.add('d');
//	ll.add('z');
//	ll.add('r');
//	ll.add('e');
//	ll.add('w');
//	ll.remove(3);
//	cout<<ll.size()<<endl;
//	cout<<ll.at(3)<<endl;
//	cout<<ll.toString()<<endl;
//Lookup LU
//cout<<LU.printAddress("nwrpca.org")<< " is the address for " << "nwrpca.org" <<endl;
//cout<<LU.printAddress("learn.nwrpca.org")<< " is the address for "<< "learn.nwrpca.org" <<endl;
LinkedList<string> list("Batman");
}
int testNetMethods()
{
	NetMethods nm;
	nm.a_accept("2000");
	return 1;
}
void TestBinaryTree()
{
	BinaryTree tree;
	tree.Add(5, "A");
	tree.Add(4, "B");
	tree.Add(6, "C");
	tree.Add(3, "D");
	tree.Add(7, "E");
	tree.Add(2, "F");
	tree.Add(8, "G");
	tree.Add(9, "H");
	tree.Add(1, "I");
	cout << tree.Search(7) << " , " << tree.Search(9)<< endl;
	
}
void TestList()
{
	List<int> l(10);
	for (int x = 0; x < 2000000; x++)
	{
		l.append(x);
	}
	for (int y = 0; y < l.length(); y++)
	{
		//cout << l.at(y) << endl;
		if (l.at(y) != y) cout << "Failed test on " << y << endl;
	}

	List<string> s(2);
	s.append("Andrew"); s.append("is "); s.append("name "); s.append("My ");
	for (int i = (s.length() - 1); i >= 0; i--)
	{
		cout << s.at(i);
	}
	cout << endl;
}
void TestHash()
{
	IntHashMap<int, int> maps;
	for (int x = 0; x < 10000; x++)
	{
		maps.Insert(x, x);
	}
	cout << maps[10] << endl;
	cout << maps[99] << endl;
	cout << maps[123] << endl;
}
vector<int>  GenerateRandomArray(int size)
{
	srand(time(NULL));
	vector<int> nums(size);
	for (int x = 0; x < size; x++)
	{
		nums[x] = rand() % 1000000;
	}
	return nums;
}
void TestBubbleSort(vector<int> nums)
{
	BubbleSort sorter;
	vector<int> result = sorter.Sort(nums);
	
	//for (unsigned int x = 0; x < result.size(); x++)
	//{
	//	cout << result[x] << endl;
	//}
}
void TestQuickSort(vector<int> nums)
{
	QuickSort sorter;
	vector<int> result = sorter.Sort(nums);

	//for (int x = 0; x < result.size(); x++)
	//{
	//	cout << result[x] << endl;
	//}
}
void TestMergeSort(vector<int> nums)
{
	MergeStort sorter;
	vector<int> result = sorter.Sort(nums);
	/*for (int x = 0; x < result.size(); x++)
	{
		cout << result[x] << endl;
	}*/
}
int main(){
    //find(20);
    //testLinkedList();
	//TestBinaryTree();
	//TestList();
	//TestHash();
	int size = 10000;
	vector<int> bubbleNums = GenerateRandomArray(size);
	vector<int> quickNums(bubbleNums);
	vector<int> mergeNums(bubbleNums);
	unsigned int start = clock();
	TestBubbleSort(bubbleNums);
	unsigned int middle = clock();
	TestQuickSort(quickNums);
	unsigned int middle2 = clock();
	TestMergeSort(mergeNums);
	unsigned int end = clock();

	cout << "BubbleSort: " << middle - start << endl;
	cout << "QuickSort: " << middle2 - middle;
	cout << "MergeSort: " << end - middle2;
	return 0;

}
