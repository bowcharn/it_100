/*
��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
�����е����Կո��������Ϊ������������ź���ͨ��ĸһ������

�������롰I am a student.�����������student. a am I����
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


string reverse_sentence(const string input_str)
{
	istringstream in(input_str);
	vector<string> as_stack;
	string get_str;
	while(in>>get_str)
	{
		//cout<<get_str<<endl;
		as_stack.push_back(get_str);
	}
	
	string res_str;
	vector<string>::reverse_iterator  itr = as_stack.rbegin();
	for(itr; itr != as_stack.rend() -1; itr++)
		res_str += (*itr + ' ');
	res_str += *(as_stack.rend()-1);
	
	return res_str;
		
}

int main(){
	string str("---I am a bad boy!!!");
	string res_str = reverse_sentence(str);
	cout<<res_str<<endl;
	return 0;
}