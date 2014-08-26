/*
  题目：一个数组中有三个数字a、b、c只出现一次，其他数字都出现了两次。
  请找出三个只出现一次的数字。

 You can do this in a similar way to the simpler cases of one and two different 
 values.

We need two integers for each bit of the numbers (e.g. 32 bits).
 For each number, if that bit is zero, XOR the first integer with it. 
If it isn't, XOR the second integer with it.

Also, keep count of how many times you find a 1 or 0 in each position
 (we only need to check if this is even or odd, so keep a boolean).

After iterating through, our pairs of integers will be one of the following.
 The first number here represents an even count, the second an odd.

0, a^b^c
a^b, c
a^c, b
b^c, a
For each pair, check the even count integer. If it is zero, then we know
 the other integer is a^b^c, since no two of our results will be equal. 
Otherwise, we've found a value at the odd count integer.

注：参考思路网址
http://stackoverflow.com/questions/3003021/find-three-numbers-appeared-only-once
*/

#include <iostream>

int*  find_three_once_num(int arr[], int n)
{
  int xors[32][2] = {{0}};
  bool counts[32] = {true};
  for(int i = 0; i < n; i++)
    for(int j =0; j < 32; j++)
      {
	xors[j][(arr[i] & (1 << j)) >> j] ^= arr[i];
	counts[j] ^= ((arr[i] & (1 << i))) == (1 << j);
      }

  for(int i = 0; i < 32; i++)
    for(int j =0 ; j < 2; j = j+2)
	std::cout<<xors[i][j]<<" "<<xors[i][j+1]<<std::endl;
   
  int* ret = new int[3];
  int found = 0;
  for(int i = 0; i < 32; i++)
    {
      int oddCount = xors[i][counts[i] ? 1 : 0];
      int evenCount = xors[i][counts[i] ? 0: 1];
      if(evenCount != 0) // avoid the 0 , a^b^c case
	{
	  if(found == 0)
	    {
	      ret[0] = oddCount; //a
	      ret[2] = evenCount; // b^c for now
	      found++;
	    }
	  else if( found == 1&& ret[0] != oddCount)
	    {
	      ret[1] = oddCount;  //b
	      ret[2] ^= oddCount;  //(b^c)^c == c
	      break;
	    }
	}
    }
  return ret;
}


int main()
{
  int arr[] = { 1,1,2,6,3,6,5,7,7,34,45,23,45,34,23};
  int* res = find_three_once_num(arr, 15);
  
  for(int i = 0 ; i < 3; i++)
    std::cout<<res[i]<<" ";
  std::cout<<std::endl;
  return 0;
}
