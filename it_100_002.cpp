/*
	题目：定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
	要求函数min、push以及pop的时间复杂度都是O(1)。
分析：这是google的一道面试题。


注：如果思路正确，编写上述代码不是一件很难的事情。但如果能注意一些细节无疑能在面试中加分。比如我在上面的代码中做了如下的工作：

·         用模板类实现。如果别人的元素类型只是int类型，模板将能给面试官带来好印象；

·         两个版本的top函数。在很多类中，都需要提供const和非const版本的成员访问函数；

·         min函数中assert。把代码写的尽量安全是每个软件公司对程序员的要求；

·         添加一些注释。注释既能提高代码的可读性，又能增加代码量，何乐而不为？

总之，在面试时如果时间允许，尽量把代码写的漂亮一些。说不定代码中的几个小亮点就能让自己轻松拿到心仪的Offer。
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

