/*
题目：给定链表的头指针和一个结点指针，在O(1)时间删除该结点。
链表结点的定义如下：

struct ListNode
{
      int        m_nKey;
      ListNode*  m_pNext;
};

函数的声明如下：

void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted);

分析：这是一道广为流传的Google面试题，能有效考察我们的编程基本功，
还能考察我们的反应速度，更重要的是，还能考察我们对时间复杂度的理解。


该算法没有给出测试......
*/


void DeleteNode(node* pListHead, node* pToBeDeleted)
{
	if(!pListHead || !pToBeDeleted)
		return;
	
	if(pToBeDeleted -> next != NULL)
	{
		pToBeDeleted->data = pToBeDeleted->next->data;
		node* tempNext = pToBeDeleted->next;
		pToBeDeleted->next = tempNext->next;
		delete tempNext;
		tempNext = NULL;
	}
	else
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}