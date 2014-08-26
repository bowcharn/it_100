/*
��Ŀ����һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
�������������2006��google��һ�������⡣
*/
#include <iostream>
#include <cstring>

using namespace std;


char find_first_not_repeat_char(char* str)
{
  if(!str) return 0;

  const unsigned int hash_size = 256;
  unsigned int hash_table[hash_size];

  memset(hash_table, 0, sizeof(int) * hash_size);
  
  char* single_char_ptr = str;
  while(*single_char_ptr != '\0')
    hash_table[*(single_char_ptr++)]++;

  single_char_ptr = str;
  while(*single_char_ptr != '\0')
    {
      if(hash_table[*single_char_ptr] == 1) 
	return *single_char_ptr;

      single_char_ptr++;
    }
}

int main()
{
  char str[] = "aasdasasddfex";
  cout<<"first--->::"<<find_first_not_repeat_char(str);
}
