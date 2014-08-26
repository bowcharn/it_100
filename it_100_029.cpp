#include <iostream>


bool is_even(int num)
{
  return (num & 1) == 0;
}
void reorder_ary_with_odd_even(int ary[], int n, bool(*fun)(int))
{
  if(ary == NULL || n == 0) return;
  
  int *front = ary;
  int *tail = ary + n -1;

  while(front < tail)
    {
      if(!fun(*front))
	{
	  front++;
	  continue;
	}
      
      if(fun(*tail))
	{
	  tail--;
	  continue;
	}
      
      if(front < tail)
	{
	  int temp = *front;
	  *front = *tail;
	  *tail = temp;
	}
    }
}


void print_ary(int ary[], int n)
{
  for(int i = 0 ; i < n; i++)
    std::cout<<ary[i]<<" ";
  std::cout<<std::endl;
}

void reorder_ary_with_odd_even_2(int ary[], int n, bool(*fun)(int))
{
  int end_odd = -1;
  int front = 0;
  for(int i =0; i < n; i++)
    {
      if(!fun(ary[front]))
	{
	  end_odd++;
	  int temp = ary[front];
	  ary[front] = ary[end_odd];
	  ary[end_odd] = temp;
	}
      front++;
    }
}

int main()
{
  int ary[] ={1,2,3,4,5,6,7,8,9,10}; 
  print_ary(ary, 10);
  reorder_ary_with_odd_even_2(ary, 10, is_even);
  print_ary(ary, 10);

  return 0;
}
