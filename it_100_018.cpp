/*
用两个栈实现队列
*/

template<typename T> class CQueue
{
public:
      CQueue() {}
      ~CQueue() {}

      void appendTail(const T& node);  // append a element to tail
      void deleteHead();               // remove a element from head 

private:
     stack<T> m_stack1;
     stack<T> m_stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
  m_stack1.push(node);
}

template <typename T>
void CQueue<T>::deleteHead()
{
	if(m_stack2.size() <= 0)
	{
		size_t s1_size = m_stack1.size();
		while(s1_size--)
		{
			m_stack2.push(m_stack1.top());
			m_stack1.pop();
		}
	}
	
	assert(m_stack2.size());
	
	m_stack2.pop();
}