/*************************************************************************
	> File Name: Heap.cpp
	> Author:    xjf
	> Mail:      doo_magic@126.com
	> Created Time: 2016年05月10日 星期二 15时52分21秒
 ************************************************************************/

#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

class Heap
{
public:
	Heap()
	{}
	Heap(int* a, int size)
	{
		assert(a);
		for(int i = 0; i< size; i++)
		{
			_h.push_back(a[i]);
		}
		for(int i = (_h.size()-2)/2; i >= 0; i--)
		{
			_AdjustDown(i);
		}
		
	}
public:
	void Display()
	{
		assert(!_h.empty());
		for(int i = 0; i<_h.size(); i++)
		{
			cout<<_h[i]<<" ";
		}
		cout<<endl;
	}
protected:
	void _AdjustDown(int parent)
	{
		int child = parent*2+1;
		while(child < _h.size())
		{
			if(child+1 < _h.size() && _h[child] < _h[child+1])
			{
				child++;
			}
			if(_h[parent] < _h[child])
			{
				swap(_h[parent], _h[child]);
				parent = child;
				child = parent*2+1;
			}
			else
			{
				break;
			}
		}
	}
private:
	vector<int> _h;
};
void Test()
{
	int arr[10] = {10, 16, 18, 12, 11, 13, 15, 17, 14, 19};
	Heap hp(arr, 10);
	hp.Display();
}

int main()
{
	Test();
	return 0;
}
