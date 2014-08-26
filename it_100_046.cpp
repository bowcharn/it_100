/*
题目：输入一个字符串，输出该字符串中对称的子字符串的最大长度。
比如输入字符串“google”，由于该字符串里最长的对称子字符串是“goog”，因此输出4。

分析：可能很多人都写过判断一个字符串是不是对称的函数，这个题目可以看成
是该函数的加强版。

注意：该程序参考网址：http://blog.csdn.net/hackbuteer1/article/details/6686263

算符名称：manacher
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