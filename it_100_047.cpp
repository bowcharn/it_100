/*
题目：数组中有一个数字出现的次数超过了数组长度的一半，找出这个数字。

分析：这是一道广为流传的面试题，包括百度、微软和Google在内的多家公司
都曾经采用过这个题目。要几十分钟的时间里很好地解答这道题，
除了较好的编程能力之外，还需要较快的反应和较强的逻辑思维能力。

注：其实以下程序中的解法也能够寻找“某个数组中出现最多的元素”
*/

#include <iostream>

bool gInputInvalid = false;

int more_than_half_num(int arr[], int n)
{
  if(arr == NULL && n <= 0)
    {
      gInputInvalid = true;
      return -1;
    }

  gInputInvalid = false;
  
  int result = arr[0];
  int times = 1;
  for(int i = 1; i < n; i++)
    {
      if(times == 0)
	{
	  result = arr[i];
	  times = 1;
	}
      else if( result == arr[i])
	times++;
      else
	times--;
    }

  // verify the input array is invalid:确实有个数字超过了一半
  times = 0;
  for(int i = 0 ; i < n; i++)
    if(arr[i] == result)
      times++;

  if(times < (n /2) +1)
    {
      gInputInvalid = true;
      std::cout<<"entered error.."<<times<<std::endl;
      return 0;
    }
    
  return result;
}

int main()
{
  int arr[7] = {3, 4,5,3,3,4,3};
  int res  = more_than_half_num(arr, 7);
  if(!gInputInvalid)
    std::cout<<"result :: "<< res <<std::endl;
  else
    std::cout<<"Invalid input or no result..\n";

  return 0;
}
