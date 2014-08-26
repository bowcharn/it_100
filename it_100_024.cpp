/*
题目：输入两个整数序列。其中一个序列表示栈的push顺序，
判断另一个序列有没有可能是对应的pop顺序。为了简单起见，
我们假设push序列的任意两个整数都是不相等的。

比如输入的push序列是1、2、3、4、5，那么4、5、3、2、1就有可能是一个pop系列。
因为可以有如下的push和pop序列：
push 1，push 2，push 3，push 4，pop，push 5，pop，pop，pop，pop，
这样得到的pop序列就是4、5、3、2、1。
但序列4、3、5、1、2就不可能是push序列1、2、3、4、5的pop序列。

*/

#include <iostream>
#include <stack>

using namespace std;

bool is_possible_pop_order(const int * ppush, const int * ppop, int length)
{
	if(ppush == NULL || ppop == NULL || length == 0) 
		return false;

	std::stack<int> st;
	const int * plocalpush = ppush;
	const int * plocalpop = ppop;
	bool is_possible = false;
	
	while( plocalpop - ppop < length)
	{
		while(st.empty() || st.top() != *plocalpop)
		{
		
			if(!plocalpush) break;
			
			st.push(*plocalpush);
			
			if(plocalpush - ppush < length -1)
				++plocalpush;
			else
				plocalpush = NULL;
		}
		
		if(st.top() != *plocalpop) break;
		
		st.pop();
		plocalpop++;
	}
	
	if(st.empty() && plocalpop - ppop == length)
		is_possible = true;
	
	return is_possible;
}


int main()
{
	int ppush[] = {1,2 ,3 ,4 ,5 };
	int ppop1[] = {4, 5 ,3, 2, 1};
	int ppop2[] = {4, 3 ,5, 1, 2};
	int ppop3[] = { 3 , 5 , 4,  2  ,1};
	
	cout<<"one-->"<<
		(is_possible_pop_order(ppush, ppop1, 5) ? ("Possible") : ("Non-Possible"))
		<<endl;
	cout<<"two-->"<<
		(is_possible_pop_order(ppush, ppop2, 5) ? ("Possible") : ("Non-Possible"))
		<<endl;
	cout<<"three-->"<<
		(is_possible_pop_order(ppush, ppop3, 5) ? ("Possible") : ("Non-Possible"))
		<<endl;
	
	return 0;
}