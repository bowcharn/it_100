/*
��Ŀ������һ���ַ�����������ַ����жԳƵ����ַ�������󳤶ȡ�
���������ַ�����google�������ڸ��ַ�������ĶԳ����ַ����ǡ�goog����������4��

���������ܺܶ��˶�д���ж�һ���ַ����ǲ��ǶԳƵĺ����������Ŀ���Կ���
�Ǹú����ļ�ǿ�档

ע�⣺�ó���ο���ַ��http://blog.csdn.net/hackbuteer1/article/details/6686263

������ƣ�manacher
*/

#include <iostream>
#include <cstring>

# define MIN(x,y)   ((x)<(y)? (x):(y))

using namespace std;

int get_longest_symmetrical_length(char* pstring)
{
	int str_len = strlen(pstring);
	char* aux_str = new char[2*str_len + 2];
	int * p = new int[2*str_len + 2];
	
	for(int i = 0; i <str_len; i++)
	{
		aux_str[2*(i+1)-1] = '#';
		aux_str[2*(i+1) ] = pstring[i];
	}
	
	aux_str[2 * str_len + 1] = '#';
	aux_str[0] = '>';
	
	char* ptr = aux_str;
	for(int i= 0; i < 2*str_len +2; i++)
	cout<<*(ptr++);
	cout<<endl;
	
	
	int n = 2*str_len +2;
	int maxId= 0, id = 0 , maxL = 0;
	for(int i = 1; i < n; i++)
	{
		if(maxId > i)
			p[i] = MIN(p[2 * id - i], maxId - i);
		else
			p[i] = 1;
		
		while(aux_str[i + p[i] ] == aux_str[ i - p[i]] )
			p[i]++;
			
		if(p[i] + i > maxId)
		{
			maxId = p[i] + i;
			id = i;
		}
		
		if(p[i] > maxL) maxL = p[i];
	}
	
	for(int i=0; i < n; i++)
		cout<<p[i];
	cout<<endl;
	return maxL - 1;
	
}


int main()
{
	char str1[] = "abaab";
	char str2[] = "aaaa";
	char str3[] = "aaaaa";
	char str4[] = "a";
	char str5[] = "";
	char str6[] = "google";
	
	int res = get_longest_symmetrical_length(str1);
	cout<<"longest symmetrical substring length--->"<<res<<endl;
	
	res = get_longest_symmetrical_length(str2);
	cout<<"longest symmetrical substring length--->"<<res<<endl;
	
	res = get_longest_symmetrical_length(str3);
	cout<<"longest symmetrical substring length--->"<<res<<endl;
	
	res = get_longest_symmetrical_length(str4);
	cout<<"longest symmetrical substring length--->"<<res<<endl;
	
	res = get_longest_symmetrical_length(str5);
	cout<<"longest symmetrical substring length--->"<<res<<endl;
	
	res = get_longest_symmetrical_length(str6);
	cout<<"longest symmetrical substring length--->"<<res<<endl;
	
	return 0;
}