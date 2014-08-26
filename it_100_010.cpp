/*
题目：输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，
使得它们的和正好是输入的那个数字。要求时间复杂度是O(n)
。如果有多对数字的和等于输入的数字，输出任意一对即可。

例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
*/

#include <iostream>

bool find_two_num_sum(int ary[], int n, int spe_sum, int &num1, int &num2)
{
  if(ary == NULL || n <= 0) return false;
  
  int front = 0;
  int tail = n -1;

  while(front < tail)
    {
      int sum = ary[front] + ary[tail];
      
      if(sum == spe_sum)
	{
	  num1= ary[front];
	  num2 = ary[tail];
	  return true;
	}
      else if(sum > spe_sum)
	tail--;
      else
	front++;
    }
  return false;

}

int main()
{
  int ary[] = {1,2 ,4, 7, 11, 15};
  int num1, num2;
  bool res = find_two_num_sum(ary, 6, 9, num1, num2);
  if(res)
    std::cout<<num1<<" "<<num2<<std::endl;
  else
    std::cout<<"No result\n";
  return 0;
}
