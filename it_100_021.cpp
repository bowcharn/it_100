/*
题目：定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。
如把字符串abcdef左旋转2位得到字符串cdefab。请实现字符串左旋转的函数。
要求时间对长度为n的字符串操作的复杂度为O(n)，辅助内存为O(1)。


注：《编程珠玑》第二章---->B问题（有多种解法）
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