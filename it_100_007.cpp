/*
题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。

例如输入“I am a student.”，则输出“student. a am I”。
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