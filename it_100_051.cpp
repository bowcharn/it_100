/*题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

例如：如果输入如下矩阵：

1              2              3              4
5              6              7              8
9              10           11           12
13           14           15           16

则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10。


注：该题利用的资源为以下网址提供的资源（没有参考何海涛的日志）
http://stackoverflow.com/questions/726756/print-two-dimensional-array-in-spiral-order
*/

#include <iostream>

const int COL = 4; 
void print_top_right(int arr[][COL], int x1, int y1, int x2, int y2);
void print_bottom_left(int arr[][COL], int x1, int y1, int x2, int y2);


void print_top_right(int arr[][COL], int x1, int y1, int x2, int y2)
{
  // print values in the row
  for(int i = x1; i <= x2; i++)
    std::cout<<arr[y1][i]<<" ";
  
  // print values in the column
  for(int i = y1 +1; i <= y2; i++)
    std::cout<<arr[i][x2]<<" ";
  
  // see if more layers need to be printed
  if(x2 - x1 > 0)
    {
      print_bottom_left(arr, x1, y1+1, x2 -1, y2);
    }
}

void print_bottom_left(int arr[][COL], int x1, int y1, int x2, int y2)
{
  // print the values int the row in reverse order
  for(int i= x2; i >= x1; i--)
    std::cout<<arr[y2][i]<<" ";

  // print the values int the row in reverse order
  for(int j = y2 -1; j >= y1; j--)
    std::cout<<arr[j][x1]<<" ";

  if(x2 - x1 >0)
    {
      print_top_right(arr, x1+1, y1, x2, y2 -1);
    }
}

void print_matrix_spiral(int arr[][COL], int row, int col)
{
  print_top_right(arr, 0, 0, col-1 , row -1);
  std::cout<<std::endl;
}

int main()
{
  int arr[4][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  print_matrix_spiral(arr, 4, 4);
  print_matrix_spiral(arr, 3, 3);
  print_matrix_spiral(arr, 2, 2);

  return 0;
}
