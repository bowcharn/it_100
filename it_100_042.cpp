/*
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个排好序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

A sorted array is rotated at some unknown point, find the minimum element in it.

Following solution assumes that all elements are distinct(but can be duplicate).

Examples

Input: {5, 6, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4}
Output: 1

Input: {2, 1}
Output: 1
*/

#include <cstdio>

int min(int x, int y) {return (x<y) ? x : y;}


// The function that handles duplicates. It can be O(n) in worst case.
int find_min(int ary[], int low, int high)
{
  // thie condition is needed ot handle the case when array is not 
  // rotate at all
  if(high < low) return ary[0];
  
  // if there is only one element left
  if(high == low) return ary[low];

  // calculate the mid
  int mid = (low + high) / 2;
  
  // check id element (mid + 1) is minimum element.
  //Consider the cases like {1, 1, 0,1}
  if(mid < high && ary[mid + 1] < ary[mid])
    return ary[mid + 1];

  // this case causes O(n) time
  if(ary[low] == ary[mid] && ary[high] == ary[mid])
    return min(find_min(ary, low, mid-1), find_min(ary, mid + 1, high));

  // check if mid itself is minimum element
  if(mid > low && ary[mid] < ary[mid - 1])
    return ary[mid];

  //Decide whether we need to go to left half or right half
  if(ary[high] > ary[mid])
    return find_min(ary, low, mid - 1);
  else
    return find_min(ary, mid+1, high);
}



int main()
{
    int arr1[] =  {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("The minimum element is %d\n", find_min(arr1, 0, n1-1));
 
    int arr2[] =  {1, 1, 0, 1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("The minimum element is %d\n", find_min(arr2, 0, n2-1));
 
    int arr3[] =  {1, 1, 2, 2, 3};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("The minimum element is %d\n", find_min(arr3, 0, n3-1));
 
    int arr4[] =  {3, 3, 3, 4, 4, 4, 4, 5, 3, 3};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    printf("The minimum element is %d\n", find_min(arr4, 0, n4-1));
 
    int arr5[] =  {2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    printf("The minimum element is %d\n", find_min(arr5, 0, n5-1));
 
    int arr6[] =  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    printf("The minimum element is %d\n", find_min(arr6, 0, n6-1));
 
    int arr7[] =  {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    printf("The minimum element is %d\n", find_min(arr7, 0, n7-1));
 
    return 0;
}

