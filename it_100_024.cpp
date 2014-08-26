/*
��Ŀ�����������������С�����һ�����б�ʾջ��push˳��
�ж���һ��������û�п����Ƕ�Ӧ��pop˳��Ϊ�˼������
���Ǽ���push���е����������������ǲ���ȵġ�

���������push������1��2��3��4��5����ô4��5��3��2��1���п�����һ��popϵ�С�
��Ϊ���������µ�push��pop���У�
push 1��push 2��push 3��push 4��pop��push 5��pop��pop��pop��pop��
�����õ���pop���о���4��5��3��2��1��
������4��3��5��1��2�Ͳ�������push����1��2��3��4��5��pop���С�

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