/*
 ��Ŀ������һ����ʾ�������ַ������Ѹ��ַ���ת���������������
 ���������ַ���"345"�����������345��
 
����������⾡�ܲ��Ǻ��ѣ�ѧ��C/C++����һ�㶼��ʵ�ֻ������ܣ�����ͬ����Ա
�������д���Ĵ����кܴ����𣬿���˵������ܹ��ܺõط�Ӧ������Ա��˼ά��
���ϰ�ߣ�����Ѿ�������΢�����ڵĶ�ҹ�˾���������⡣������������¿�
֮ǰ�Լ��ȱ�д���룬�ٱȽ��Լ�д�Ĵ��������Ĳο���������Щ��ͬ��


ע�⣺���ó���ʵ�ֵķ�ʽ��c������atoi�����ǲ�һ���ģ� ���������Ե�ʱ�������
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
