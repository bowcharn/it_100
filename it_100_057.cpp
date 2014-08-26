/*
题目：某公司有几万名员工，请完成一个时间复杂度为O(n)的算法对该公司员工的年龄作排序，可使用O(1)的辅助空间。

分析：排序是面试时经常被提及的一类题目，我们也熟悉其中很多种算法，
诸如插入排序、归并排序、冒泡排序，快速排序等等。这些排序的算法，
要么是O(n2)的，要么是O(nlogn)的。可是这道题竟然要求是O(n)的，这里面到底有什么玄机呢？

题目特别强调是对一个公司的员工的年龄作排序。员工的数目虽然有几万人，但这几万员工的年龄却只有几十种可能。
上班早的人一般也要等到将近二十岁才上班，一般人再晚到了六七十岁也不得不退休。

由于年龄总共只有几十种可能，我们可以很方便地统计出每一个年龄里有多少名员工。
举个简单的例子，假设总共有5个员工，他们的年龄分别是25、24、26、24、25。
我们统计出他们的年龄，24岁的有两个，25岁的也有两个，26岁的一个。
那么我们根据年龄排序的结果就是：24、24、25、25、26，即在表示年龄的数组里写出两个24、两个25和一个26。
*/

#include <iostream>
#include <cassert>
#include <cstring>

void print_arr(int arr[], int n);

void sort_ages(int arr[], int n)
{
  if(arr == NULL || n <= 0)
    return;

  const int oldest_age = 99;
  int ages_count_arr[oldest_age +1];
  memset(ages_count_arr, 0, sizeof(ages_count_arr));

  for(int i = 0 ; i < n; i++)
    {
      int age = arr[i];
      //      if(age <0 || age >99)
      //	throw new std::exception("age out of range");
      assert(age >=0 && age <= 99);
      ++ages_count_arr[age];
    }
  print_arr(ages_count_arr, 100);

  int idx = 0;
  for(int i = 0 ; i <= oldest_age; i++)
    {
      for(int j = 0; j < ages_count_arr[i]; j++)
	{
	  arr[idx] = i;
	  ++idx;
	}
    }
}

void print_arr(int arr[], int n)
{
  for(int i=0 ; i< n; i++)
    std::cout<<arr[i]<<" ";
  std::cout<<std::endl;
}
int main()
{
  int arr[] = {23,34,42,12,66,22,34,65,76, 10};
  print_arr(arr, 10);
  sort_ages(arr, 10);
  print_arr(arr, 10);

  return 0;
}
