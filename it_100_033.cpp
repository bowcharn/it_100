/*
��Ŀ�����������ͷָ���һ�����ָ�룬��O(1)ʱ��ɾ���ý�㡣
������Ķ������£�

struct ListNode
{
      int        m_nKey;
      ListNode*  m_pNext;
};

�������������£�

void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted);

����������һ����Ϊ������Google�����⣬����Ч�������ǵı�̻�������
���ܿ������ǵķ�Ӧ�ٶȣ�����Ҫ���ǣ����ܿ������Ƕ�ʱ�临�Ӷȵ���⡣


���㷨û�и�������......
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