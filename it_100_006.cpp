/*
��Ŀ������һ���������飬�жϸ������ǲ���ĳ��Ԫ�������ĺ�������Ľ����
����Ƿ���true�����򷵻�false��
��������5��7��6��9��11��10��8��������һ�����������������ĺ�����������

         8
       /  \
      6    10
    / \    / \
   5   7   9  11

��˷���true��

�������7��4��6��5��û���Ŀ����ĺ�������Ľ����������У���˷���false��

����������һ��trilogy�ı����⣬��Ҫ����Զ�Ԫ����������⡣
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