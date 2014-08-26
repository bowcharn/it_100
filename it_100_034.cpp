/*
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
*/

#include <iostream>


// 假设一定有一位是1
unsigned int find_first_bit_one (int num)
{
  unsigned int idx = 0;
  while((num & 1) == 0  &&(idx < 32))
    {
      num = num >> 1;
      ++idx;
    }

  return idx;
}

bool is_bit_one(int num, unsigned int bit_idx)
{
  num = num >> bit_idx;
  return (num & 1);
}

void find_two_num_appear_once(int ary[], int n, int & num1, int& num2)
{
  if(n < 2) return;
  
  int res_xor = 0;
  for(int  i = 0;  i < n; i++)
    res_xor ^= ary[i];

  unsigned int first_bit_idx  = find_first_bit_one(res_xor);

  num1 = num2 = 0;
  for(int  i = 0;  i < n; i++)
    {
      if(is_bit_one(ary[i] , first_bit_idx))
	num1 ^= ary[i];
      else
	num2 ^= ary[i];
    }
}


int main()
{
  int ary[] = {32,23,23,4,5,5,4,2};
  int num1 , num2;
  find_two_num_appear_once(ary, 8, num1, num2);
  std::cout<<num1 << " "<<num2<<std::endl;

  return 0;
}
