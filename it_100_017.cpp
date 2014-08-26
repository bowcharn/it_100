/*
 题目：输入一个表示整数的字符串，把该字符串转换成整数并输出。
 例如输入字符串"345"，则输出整数345。
 
分析：这道题尽管不是很难，学过C/C++语言一般都能实现基本功能，但不同程序员
就这道题写出的代码有很大区别，可以说这道题能够很好地反应出程序员的思维和
编程习惯，因此已经被包括微软在内的多家公司用作面试题。建议读者在往下看
之前自己先编写代码，再比较自己写的代码和下面的参考代码有哪些不同。


注意：：该程序实现的方式和c语言中atoi函数是不一样的， 所以在面试的时候问清楚
*/

#include <iostream>
#include <cstdlib>
#include <limits>  
using namespace std;


enum convert_status {valid = 0, invalid};
int g_status = valid;

int strtoint(const char * str)
{
	g_status = invalid;
	long long num = 0;

	if(str != NULL)
	{
		bool sign = false;
		const char* digit_ptr = str;
		if(digit_ptr[0] == '-')
		{
			digit_ptr++;
			sign = true;
		}
		
		while(*digit_ptr != '\0')
		{
			if(*digit_ptr >='0' && *digit_ptr <= '9')
			{
				num = num*10 + (*digit_ptr - '0');

				if(num > numeric_limits<int>::max())
				{
					num = 0;
					break;
				}
				digit_ptr++;
			}
			else
			{
				num = 0;
				break;
			}
		}

		if(*digit_ptr == '\0')
		{
			g_status = valid;
			if(sign)
				num = 0 - num;
		}	      
	}

	return static_cast<int>(num);
}

int main()
{
	char str1[] = "23423";
	char str2[] = "83948598";
	char str3[] = "  234";
	char str4[] = "345sdfs";

	int num1 = strtoint(str1);
	cout<<((g_status == valid)? num1 : -1)<<endl; 

	int num2 = strtoint(str2);
	cout<<((g_status == valid)? num2 : -1)<<endl; 

	int num3 = strtoint(str3);
	cout<<((g_status == valid)? num3 : -1)<<endl; 

	int num4 = strtoint(str4);
	cout<<((g_status == valid)? num4 : -1)<<endl; 

	return 0;
}
