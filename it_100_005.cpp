/*
��Ŀ������n�����������������С��k����

��������1��2��3��4��5��6��7��8��8�����֣�����С��4������Ϊ1��2��3��4��

�������������򵥵�˼·Ī���ڰ������n����������
����������ǰ���k����������С��k������ֻ������˼·��ʱ�临�Ӷ�ΪO(nlogn)��
��������Ѱ�Ҹ���Ľ��˼·��

���ǿ���ѡ���ò�ͬ�Ķ�������ʵ���������������
��������ÿ�ζ���Ҫ�ҵ�k�������е�������֣����Ǻ������뵽�����ѡ�
�������У�������ֵ���Ǵ��������������������ֵ��
��������ÿ�ο�����O(1)�õ����е�k�������е����ֵ��
����ҪO(logk)ʱ�����ɾ���Լ��������.

����������multiset
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