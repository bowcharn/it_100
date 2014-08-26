/*
题目：输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。
如果是返回true，否则返回false。
例如输入5、7、6、9、11、10、8，由于这一整数序列是如下树的后序遍历结果：

         8
       /  \
      6    10
    / \    / \
   5   7   9  11

因此返回true。

如果输入7、4、6、5，没有哪棵树的后序遍历的结果是这个序列，因此返回false。

分析：这是一道trilogy的笔试题，主要考查对二元查找树的理解。
*/

#include <iostream>

using namespace std;

bool is_array_tree_post_order(int ary[], int n)
{
	if(ary == NULL || n <= 0) return false;
	
	int last_ele = ary[n -1];
	bool result = false;
	
	int left_idx = 0;
	int right_idx = 0;
	for(left_idx = 0; left_idx < n -1; left_idx++)
		if(ary[left_idx] > last_ele)
			break;
	for(right_idx = n -2 ; right_idx >= 0; right_idx--)
		if(ary[right_idx] < last_ele)
			break;
			
	int diff = left_idx - right_idx;
	if(diff == 1)
	{
		//cout<<"enter into ...\n";
		result = true;
	}
	else if(diff > 1)
	{
		int first_ele = ary[right_idx + 1];
		for(int i = right_idx+1;  i <= left_idx-1; i++)
			if(ary[i] != first_ele)
			 return false;
	}
	else
		return false;
	
	int left_n = left_idx;
	int right_n = (n-1) - (right_idx+1);
	if(left_n >= 1)
		result &= is_array_tree_post_order(ary, left_n);
	if(right_n >= 1)
		result &= is_array_tree_post_order(ary+right_idx +1, right_n);
		
	return result;
}

int main()
{
	int ary[] = {5,7,6,9,8,11,10};
	
	cout<<(is_array_tree_post_order(ary, 7)? ("true"): ("false"))<<endl;
	
	return 0;
}