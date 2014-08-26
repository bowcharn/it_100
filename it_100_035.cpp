/*题目：两个单向链表，找出它们的第一个公共结点。

链表的结点定义为：

struct ListNode
{
      int         m_nKey;
      ListNode*   m_pNext;
};

分析：这是一道微软的面试题。微软非常喜欢与链表相关的题目，
因此在微软的面试题中，链表出现的概率相当高。
*/



//节点的定义
struct node
{
  int           data;
  struct node*  next;
};


//求一个没有带环的单向链表的长度
int length(node* head)
{
  node* current = head;
  int count = 0;
  while(current!=NULL)
    {
      count++;
      current = current->next;
    }
  return count;
}

//如果两个无环链表的有交点，则输出第一个相交的节点指针，否则输出的为NULL
node* find_first_common_node(node* pFirstListHead, node* pSecondListHead)
{
	if(pFirstListHead == NULL || pSecondListHead == NULL) 
		return NULL;
	
	int first_len = length(pFirstListHead);
	int second_len = length(pSecondListHead);
	
	node* plonglist = pFirstListHead;
	node* pshortlist = pSecondListHead;
	int len_diff = abs(first_len - second_len);
	if(second_len > first_len)
	{
		plonglist  = pSecondListHead;
		pshortlist = pFirstListHead;
	}
	
	//让较长的链表的指针先走len_diff步
	for(int i = 0 ; i < len_diff; i++)
		plonglist = plonglist->next;
	
	while(plonglist != NULL
	      &&pshortlist != NULL
		  &&plonglist != pshortlist)
	{
		plonglist = plonglist->next;
		pshortlist = pshortlist->next;
	}
	
	return (plonglist!=NULL && pshortlist != NULL) ? plonglist : NULL;
}