/*
题目：输入n个整数，输出其中最小的k个。

例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。

分析：这道题最简单的思路莫过于把输入的n个整数排序，
这样排在最前面的k个数就是最小的k个数。只是这种思路的时间复杂度为O(nlogn)。
我们试着寻找更快的解决思路。

我们可以选择用不同的二叉树来实现这个数据容器。
由于我们每次都需要找到k个整数中的最大数字，我们很容易想到用最大堆。
在最大堆中，根结点的值总是大于它的子树中任意结点的值。
于是我们每次可以在O(1)得到已有的k个数字中的最大值，
但需要O(logk)时间完成删除以及插入操作.

本例中用了multiset
*/


#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;


typedef multiset<int, greater<int> > int_heap;


void find_k_least_elements(const vector<int>& input_nums, 
							int_heap& output_nums, int k)
{
	size_t sz = input_nums.size();
	if(sz < k ) return;
	for(int i = 0; i < sz; i++){
		if(output_nums.size() < k)
			output_nums.insert(input_nums[i]);
		else
		{
			if(*(output_nums.begin()) > input_nums[i])
				{
					output_nums.erase(output_nums.begin());
					output_nums.insert(input_nums[i]);
				}
		}
	}
}


int main()
{
	vector<int> input_nums {1,23, 345, 546, 5,23, 456,56,6732};
	int_heap output_nums;
	find_k_least_elements(input_nums, output_nums, 5);
	for(int_heap::reverse_iterator itr = output_nums.rbegin();
		itr != output_nums.rend(); itr++)
		cout<<*itr<<" ";
	cout<<endl;
	
	return 0;
}