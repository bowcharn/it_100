struct ComplexNode
{
    int m_nValue;
    ComplexNode* m_pNext;
    ComplexNode* m_pSibling;
};

void clone_nodes (ComplexNode* list_head)
{
	ComplexNode* phead = list_head;
	while(list_head!=NULL)
	{
		ComplexNode* pcloned = new ComplexNode();
		pcloned->m_nValue = phead->m_nValue;
		pcloned->m_pNext = phead->m_pNext;
		pcloned->m_pSibling = NULL;
		
		phead ->m_pNext = pcloned;
		
		phead = pcloned->m_pNext;
	}
}


void connect_clones_sibling_nodes(ComplexNode* list_head)
{
	ComplexNode* phead = list_head;
	while(phead != NULL)
	{
		ComplexNode* psibling = phead->m_pSibling;
		if(psibling)
			phead->m_pNext->m_pSibling = psibling->m_pNext;
		
		phead = phead->m_pNext->m_pNext;
	}
}


ComplexNode* reconnect_nodes(ComplexNode* list_head){
	ComplexNode* phead = list_head;
	ComplexNode* pclone_head = NULL;
	ComplexNode* pclone_node = NULL;
	if(phead != NULL)
	{
		pclone_head = pclone_node =phead ->m_pNext;
		phead ->m_pNext = pclone_head->m_pNext;
		phead = phead->m_pNext;
	}
	
	while(phead != NULL)
	{
		pclone_node->m_pNext = phead->m_pNext;
		pclone_node = pclone_node->m_pNext;
		
		phead->m_pNext = pclone_node->m_pNext;
		phead = phead -> m_pNext;
	}
	
	return pclone_head;
}