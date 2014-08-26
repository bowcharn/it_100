/*��Ŀ���������������ҳ����ǵĵ�һ��������㡣

����Ľ�㶨��Ϊ��

struct ListNode
{
      int         m_nKey;
      ListNode*   m_pNext;
};

����������һ��΢��������⡣΢��ǳ�ϲ����������ص���Ŀ��
�����΢����������У�������ֵĸ����൱�ߡ�
*/



//�ڵ�Ķ���
struct node
{
  int           data;
  struct node*  next;
};


//��һ��û�д����ĵ�������ĳ���
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

//��������޻�������н��㣬�������һ���ཻ�Ľڵ�ָ�룬���������ΪNULL
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
	
	//�ýϳ��������ָ������len_diff��
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