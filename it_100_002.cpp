/*
	��Ŀ������ջ�����ݽṹ��Ҫ�����һ��min�������ܹ��õ�ջ����СԪ�ء�
	Ҫ����min��push�Լ�pop��ʱ�临�Ӷȶ���O(1)��
����������google��һ�������⡣


ע�����˼·��ȷ����д�������벻��һ�����ѵ����顣�������ע��һЩϸ���������������мӷ֡�������������Ĵ������������µĹ�����

��         ��ģ����ʵ�֡�������˵�Ԫ������ֻ��int���ͣ�ģ�彫�ܸ����Թٴ�����ӡ��

��         �����汾��top�������ںܶ����У�����Ҫ�ṩconst�ͷ�const�汾�ĳ�Ա���ʺ�����

��         min������assert���Ѵ���д�ľ�����ȫ��ÿ�������˾�Գ���Ա��Ҫ��

��         ���һЩע�͡�ע�ͼ�����ߴ���Ŀɶ��ԣ��������Ӵ����������ֶ���Ϊ��

��֮��������ʱ���ʱ�����������Ѵ���д��Ư��һЩ��˵���������еļ���С����������Լ������õ����ǵ�Offer��
*/

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

template <typename T>
class CStackWithMin
{
public:
	CStackWithMin() {};
	virtual ~CStackWithMin() {};
	
	const T& top() const;
	T& top();
	
	void push(const T& value);
	void pop();
	
	T& min();
	const T& min() const;
	
private:
	std::stack<T> data;
	std::stack<T> min_data;
};

template <typename T>
T& CStackWithMin<T>::top()
{
	return data.top();
}


template <typename T>
const T& CStackWithMin<T>::top() const
{
	return data.top();
}

template <typename T>
void CStackWithMin<T>::push(const T& value)
{
	data.push(value);
	
	if(data.size() == 1)
	min_data.push(value);
	else
	{
		if(value < min_data.top())
		min_data.push(value);
		else
		min_data.push(min_data.top());
	}

}

template <typename T>
void CStackWithMin<T>::pop()
{
	assert(data.size() > 0);
	
	
	data.pop();
	min_data.pop();
}

template <typename T>
T& CStackWithMin<T>::min()
{	
	assert(data.size() > 0);
	assert(min_data.size() > 0);
	
	return min_data.top();
}

template <typename T>
const T& CStackWithMin<T>::min() const
{
     assert(data.size() > 0);
	assert(min_data.size() > 0);
	
	return min_data.top();
}




int main()
{
	CStackWithMin<int> test_stack;
	
	//cout<<test_stack.min()<<endl;
	
	test_stack.push(3);
	cout<<test_stack.min()<<endl;
	
	test_stack.push(4);
	cout<<test_stack.min()<<endl;
	
	test_stack.push(2);
	cout<<test_stack.min()<<endl;
	
	test_stack.push(1);
	cout<<test_stack.min()<<endl;
	
	test_stack.pop();
	cout<<test_stack.min()<<endl;
	
	test_stack.pop();
	cout<<test_stack.min()<<endl;
	
	test_stack.push(0);
	cout<<test_stack.min()<<endl;
	
	return 0;
}

