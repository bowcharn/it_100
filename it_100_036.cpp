/*
��Ŀ�����������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou������ɾ��֮��
�ĵ�һ���ַ�����ɡ�Thy r stdnts.����

Ӧ�ã� Ԫ��ɾ��+hash


*/

#include <iostream>
#include <cstring>

using namespace std;

void delete_chars(char* source_str, const char*  to_delete_str)
{
	if(source_str == NULL || to_delete_str == NULL)
		return;
		
	const char* delele_ptr = to_delete_str;
	int hash_table[256];
	memset(hash_table, 0, sizeof(hash_table));
	
	
	while(*delele_ptr != '\0')
		hash_table[*(delele_ptr++)]++;
	
	char *pslow;
	char *pfast;
	pslow = pfast = source_str;
	while(*pfast != '\0')
	{
		if(hash_table[*pfast] == 0)
		{
			*pslow = *pfast;
			++pslow;
			
		}
		
		pfast++;
	}
	*pslow = '\0';
}


int main()
{
	//char source_str[] = "They are students.";
	//char to_delete_str[] = "aeiou";
	
	char source_str[] = "1234443535";
	char to_delete_str[] = "45";
	
	delete_chars(source_str, to_delete_str);
	
	cout<<source_str<<endl;
	
	return 0;
}