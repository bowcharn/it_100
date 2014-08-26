/*
题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后
的第一个字符串变成”Thy r stdnts.”。

应用： 元素删除+hash


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