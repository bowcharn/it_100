/*
��Ŀ���õݹ�ߵ�һ��ջ����������ջ{1, 2, 3, 4, 5}��1��ջ����
�ߵ�֮���ջΪ{5, 4, 3, 2, 1}��5����ջ����
*/

#include <iostream>
#include <stack>
#include <deque>

using namespace std;


template <typename T>
void add_to_stack_bottom(std::stack<T>& st, T t)
{
	if(st.empty())
		st.push(t);
	else
	{
		T top = st.top();
		st.pop();
		add_to_stack_bottom(st, t);
		st.push(top);
	}
}



template <typename T>
void reverse_stack(std::stack<T>& st)
{
	if(!st.empty())
	{
		T top = st.top();
		st.pop();
		reverse_stack(st);
		add_to_stack_bottom(st, top);
	}
}



template <typename T>
void print_stack(std::stack<T>& st)
{
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

	
int main()
{
	std::deque<int> deq {5,4,3,2,1};
	std::stack<int> st(deq);
	reverse_stack<int>(st);
	print_stack<int>(st);
	
	return 0;
}