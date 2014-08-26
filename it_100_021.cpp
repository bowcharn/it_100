/*
��Ŀ�������ַ���������ת���������ַ���ǰ������ɸ��ַ��ƶ����ַ�����β����
����ַ���abcdef����ת2λ�õ��ַ���cdefab����ʵ���ַ�������ת�ĺ�����
Ҫ��ʱ��Գ���Ϊn���ַ��������ĸ��Ӷ�ΪO(n)�������ڴ�ΪO(1)��


ע����������ᡷ�ڶ���---->B���⣨�ж��ֽⷨ��
*/

#include <iostream>
#include <cstring>

using namespace std;

void reverse_string(char* pbegin, char* pend);


char* left_rotate_string(char* str, unsigned int idx)
{
	int str_size = strlen(str);
	
	if(idx == 0 || idx == str_size) return str;
	
	char* pstart = str;
	char* pmiddle = str + idx - 1;
	char* ptail = str + str_size - 1;
	
	reverse_string(str, pmiddle);
	reverse_string(pmiddle+1, ptail);
	reverse_string(pstart, ptail);
	
	return pstart;
}

void reverse_string(char* pbegin, char* pend)
{
	if(pbegin != NULL && pend != NULL)
	{
		char to_swap;
		while(pbegin < pend)
		{
			to_swap = *pbegin;
			*pbegin = * pend;
			*pend = to_swap;
			
			pbegin++;
			pend--;
		}
	}
}


int main()
{
	char str_to_rotate[] = "abcdefghijk";
	cout<<"Before rotated >>>" << str_to_rotate<<endl;
	cout<<"After rotated >>>>"<<left_rotate_string(str_to_rotate, 5)<<endl;
	return 0;
}