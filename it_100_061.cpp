/*
题目：在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。
例如在数组{2, 4, 1, 16, 7, 5, 11, 9}中，数对之差的最大值是11，是16减去5的结果。
*/
#include <iostream>

#define max(x,y) ((x > y ? x : y))

int get_max_diffence(int arr[], int n)
{
  if(arr == NULL || n <=1)
    return -1;  // 这里返回值，是个测试用而已，因为有可能最大差就是-1

  int max_diff = arr[0] - arr[1];
  int max_diff_idx = 0;
  
  for(int i = 1; i < n-1 ; i++)
    {
      int temp_diff = arr[i] - arr[i+1];
      int tmp_max_diff = arr[max_diff_idx] - arr[i+1];
      if(tmp_max_diff > max_diff)
	  max_diff = tmp_max_diff;

      if(temp_diff > max_diff)
	{
	  max_diff = temp_diff;
	  max_diff_idx = i;
	}
    }

    return max_diff;
}

int main()
{
  // int arr[] = {2, 4, 1, 16, 7, 5, 11, 9};
  //  int arr[] ={ 0 ,10 ,8 ,9 ,6 ,7 ,4,10 ,0};
  int arr[] = {2, 3, 10, 6, 4, 8, 1};
  std::cout<<"max diffence :: "<<get_max_diffence(arr, 7)<<std::endl;

  return 0;
}
