/*
题目：输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和
。求所有子数组的和的最大值。要求时间复杂度为O(n)。

例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，
和最大的子数组为3, 10, -4, 7, 2，因此输出为该子数组的和18。
注：这里假设如果输入的都为负数或者最大的和也为负数，那么结果为0，
也就是为空自数组的时候和是最大的。
*/

#include <iostream>

using namespace std;

#define max(x, y) ((x > y) ? (x) : (y))

int find_maxsum_of_subarray(int ary[], int n)
{
  int sum = 0;
  int max_sum_here = 0;
  for(int i =0 ; i < n; i++)
    {
      max_sum_here = max(max_sum_here + ary[i] , 0);
      sum = max(sum, max_sum_here);
    }

  return sum;
}

int main()
{
  int ary[] = {1, -2, 3, 10, -4, 7, 2, -5};

  std::cout<<"Max sum ::: "<<find_maxsum_of_subarray(ary, 8)<<std::endl;
  
  return 0;
}
