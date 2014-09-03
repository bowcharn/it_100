
/*
  2014.3.11
  该文件编写了基本的单链表操作，其中很多函数还是有一定困难的，
  后期在使用链表的
  时候可以参看此cpp的思想；
  
  
  题目：输入一个链表的头结点，反转该链表，并返回反转后链表的头结点。
  链表结点定义如下：

struct ListNode
{
      int       m_nKey;
      ListNode* m_pNext;
};

该程序主要为添加反转链表， 函数原型为：
node* reverse_list(node* list_head)

*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
struct node
{
  int           data;
  struct node*  next;
};

void fillAry(int* Ary, int lb, int ub)
{
  int i;
  srand(time(NULL));
  for(i=lb; i <=ub; ++i) Ary[i] = rand()%(int(ub-lb+1))+1;
}

///initilize a list with an array, just values in array
void create_list(node** head, int ary[], int n)
{
                   /* input*/
  // head: the head of the list will be create immediately, default NULL;
  // ary: contain the values of node
  // n: size of ary, n>=1
   
  *head = new node;
  node* p = *head;
  p->data = ary[0];
  p->next = NULL;

  node* add_ptr;
  for(int i = 1; i<n;++i)
    {
      add_ptr = new node;
      add_ptr->data = ary[i];
      add_ptr->next = NULL;
      p->next = add_ptr;
      p = add_ptr;
    }
}


int length(node* head)
{
  node* current = head;
  int count = 0;
  while(current!=NULL)
    {
      count++;
      current = current->next;
    }
  return count;
}

void insert_at_front(node** head, int data)
{
  node * new_node = new node;
  
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void insert_at_front(node* & head, int data)
{
  node* new_node = new node;
  
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void append_at_tail(node** head , int data)
{
  node* current = *head;
  node* new_node = new node;
  
  new_node->data = data;
  new_node->next = NULL;
  
  if(*head==NULL)
    *head = new_node;
  else
    {
      //locate the last node ::current->next (usage)
      while(current->next!=NULL)
	current = current->next;
      current->next = new_node;
    }
}


node* copy_list(node* src_head)
{
  //src_head(input):list will be copied
  node* src_current = src_head;
  node* new_head = NULL;     //new list head
  node* new_tail = NULL;    //new list tail

  while(src_current!=NULL)
    {
      if(new_head==NULL)
	{
	  new_head = new node;
	  new_head->data = src_current->data;
	  new_head->next = NULL;
	  new_tail = new_head;
	}
      else
	{// keep tail is new list's tail . be careful
	  new_tail->next = new node;
	  new_tail->next->data = src_current->data;
	  new_tail->next->next = NULL;
	  new_tail = new_tail->next;
	}
      src_current = src_current->next;
    }
  return new_head;
}

int count(node* head, int search_for)
{
  //counts the number of a given int("node.data") occurs in a list 
  node* current = head;
  int total_count = 0;
  while(current!=NULL)
    {
      if(current->data == search_for)
	total_count++;
      current= current->next;
    }
  return total_count;
}


int get_nth(node* head, int index)
{
  // takes a linked list and an integer index and returns
  // the data value stored in the node at that index position
  assert(index>=0&&index<=length(head)-1);
  
  node* current = head;
  int temp_count = 0;
  while(index!=temp_count)
    {
      if(temp_count==index) break;
      temp_count++;
      current= current->next;
    }
  return current->data;
}

void delete_list(node** head)
{
  //takes a list , deallocates all f its memory and 
  //set its head pointer to NULL(this empty list)
  node* current = *head;
  node* to_delete = NULL;
  while(current!=NULL)
    {
      to_delete = current;
      current = current->next;
      delete to_delete;
    }

  *head = NULL;
}

int delete_from_front(node** head)
{
  /*
    The opposite of insert_at_front(). Takes a non-empty list
    and removes the front node, and returns the data
    which was in that node.
  */

  assert(*head!=NULL);
    
  node* current = *head;
  int rtData = current->data;
  *head = current->next;
  delete current;

  return rtData;
}

void insert_at_nth(node** head, int index, int data)
{
  /*
    A more general version of insert_at_front().
    Given a list, an index 'n' in the range 0..length,
    and a data element, add a new node to the list so
    that it has the given index.
  */

  int list_length = length(*head);
  assert(index>=0&&index<=list_length);

  node* new_node = new node;
  new_node->data = data;

  if(index==0)
    {
      new_node->next = *head;
      *head = new_node;
    }
  else
    {
      node* current = *head;

      int count= 0;
      while((index-1)!=count++)
	current = current->next;

      if(current->next == NULL)
	  new_node->next = NULL;
      else
	  new_node->next = current->next;

      current->next = new_node;
    }
}

void sorted_insert(node** head, node* new_node)
{
  /*
    function which given a list that is sorted in increasing order,
    and a single node, inserts the node into the correct sorted position
    int the list
   */

  node dommy;
  node* current = &dommy;
  dommy.next = *head;
  
  while((current->next!=NULL)&&(current->next->data<new_node->data))
    current = current->next;
  
  new_node->next= current->next;
  current->next = new_node;

  *head = dommy.next;
}

void insert_sort(node** head)
{
  node* result = NULL;
  node* current = *head;
  node* next = NULL;
  
  while(current!=NULL)
    {
      next = current->next;
      sorted_insert(&result,current);
      current = next;
    }

  *head = result;
}

void append(node** head_a, node** head_b)
{

// Append 'b' onto the end of 'a', and then set 'b' to NULL.
  node* current = *head_a;
  if(current==NULL)
      *head_a = *head_b;
  else
    {
      while(current->next!=NULL)
	current = current->next;

      current->next = *head_b;
    }
  *head_b = NULL;
}

void print_list(node* head)
{
  node* current = head;
  while(current!=NULL)
    {
      std::cout<<current->data<<" ";
      current= current->next;
    }
  std::cout<<std::endl;
}

void front_back_split(node* source, node** front, node** back)
{

/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/


  delete_list(front);
  delete_list(back);
  int len = length(source);
  
  if(len<2)
    {
      *front = source;
      *back = NULL;
    }
  else
    {
      int front_tail_idx = (len-1)/2;
      int count=0;
      node* current = source;
      while(front_tail_idx!=count++)
	current = current->next;
      /*
	for(count = 0; count<front_tail_idx;++count)
	    current = current->next;
       */
      
      *front = source;
      *back = current->next;
      current->next = NULL;
    }
}

void remove_duplicates(node* head)
{
/*
Remove duplicates from a sorted list.
*/

  node* current = head;
  if(current == NULL)
    return;
  
  int pre_data = current->data;
  node* pre_ptr = current;
  current = current->next;
  while(current!=NULL)
    {
      node* p = NULL;
      if(pre_data == current->data)
	{
	   p = current;
	  pre_ptr->next = current->next;
	}
      else
	{
	  pre_ptr = current;
	  pre_data = current->data;
	}
      current = current->next;
      if(p) delete p;
    }
}

void move_node(node** dest, node**source)
{
  node* current = *source;
  assert(current != NULL);

  *source = current->next;
  current->next = *dest;
  *dest = current; 
}

void alternating_split(node* source, node** a, node** b)
{

/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/

  delete_list(a);
  delete_list(b);
  node* current = source;
  while(current!=NULL)
    {
      if(current->data%2==0)
	{
	  //std:: cout<<"even::"<<current->data<<std::endl;
	  move_node(a,&current);	  
	}

      else
	{
	  //std::cout<<"odd::"<<current->data<<std::endl;
	  move_node(b,&current);
	}
    }
}


node* shuffle_merge(node* a, node* b)
{

/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/


  node dommy;
  dommy.next = NULL;
  node* head = &(dommy);

  node* a_cur = a;
  node* b_cur = b;
  while(a_cur&&b_cur)
    {
      move_node(&(head->next),&a_cur);
      head = head->next;
      move_node(&(head->next),&b_cur);
      head = head->next;
    }


  if(a_cur!=NULL)
    head->next= a_cur;      
  else if(b_cur!=NULL)
    head->next = b_cur; 

  return dommy.next;
}

node* sorted_merge(node* a, node* b)
{
  /*
Takes two lists sorted in increasing order, and
splices their nodes together to make one big
sorted list which is returned.
*/

  node dommy;
  dommy.next = NULL;
  node* head = &(dommy);

  node* a_cur = a;
  node* b_cur = b;
  while(a_cur&&b_cur)
    {
      if(a_cur->data<b_cur->data)	
	move_node(&(head->next),&a_cur);
      else
	move_node(&(head->next),&b_cur);      
      head = head->next;
    }

  if(a_cur!=NULL)
    head->next= a_cur;      
  else if(b_cur!=NULL)
    head->next = b_cur; 

  return dommy.next;
}

void merge_sort(node** head)
{ 
  node * current = *head;
  node* front = NULL;
  node* back = NULL;
 
  if(current==NULL || current->next==NULL)
    return;
    
   front_back_split(*head,&front,&back);     
   merge_sort(&front);
   merge_sort(&back);
   *head = sorted_merge(front,back);      
}

node* sorted_intersect(node* a, node* b)
{

/*
Compute a new sorted list that represents the intersection
of the two given sorted lists. (increasing order)
*/

  node dommy;
  dommy.next = NULL;  
  node* tail = &dommy;

  while(a!=NULL&&b!=NULL)
    {
      if(a->data == b->data)
	{
	  insert_at_front(&(tail->next),a->data);	  
	  tail = tail->next;
	  a = a->next;
	  b = b->next;
	}
      else if(a->data > b->data) //// advance the smaller list
	{
	  b = b->next;	  
	}

      else
	{
	a = a->next;	  
	}

    }

  return dommy.next;

}


void reverse(node** head)
{
  /*
Reverse the given linked list by changing its .next pointers and
its head pointer. Takes a pointer (reference) to the head pointer.
*/
  if(*head!=NULL)  //special case : skip the empty list
    {
      /*
Plan for this loop: move three pointers: front, middle, back
down the list in order. Middle is the main pointer running
down the list. Front leads it and Back trails it.
For each step, reverse the middle pointer and then advance all
three to get the next node.

::::当然， 直接利用move_node也可以完成该函数的功能
*/

      node * middle = *head;
      node * front = middle->next;
      node * back = NULL;
      while(1)
	{
	  middle->next = back;   // fix the middle node
	  if(front==NULL) break;  // test if done the work 
	  
	  back = middle;     // change or advance three pointers
	  middle = front;
	  front = front->next;
	}
      *head = middle;    //fix the new point to point to the new list front
    }
}


void recursive_reverse(node** head)
{
  node* first;
  node* rest;
  
  if(*head == NULL) return;
  
  first = *head;
  rest = first->next;

  if(rest == NULL) return;
  
  recursive_reverse(&rest);  //accept 'rest' has reversed

  first->next->next = first;
  first->next = NULL;
  
  *head = rest;
}


///reverse a list
node* reverse_list(node* list_head)
{

	if(list_head == NULL) 
		return NULL;
	node *phead = list_head;
	node *preverse_next = NULL;
	node* pmiddle = NULL;
	while(phead ->next != NULL)
	{
		pmiddle = phead -> next;
		
		phead->next = preverse_next;
		
		preverse_next = phead;
		
		phead = pmiddle;
	}
	
	phead->next = preverse_next;
	
	return phead;
}


int main()
{
  int a1[1] = {2};
  int a2[10] = {2,5,7,9,10};
  node* a_list = NULL;
  node* b_list = NULL;
 
  create_list(&a_list,a1, 1);
  create_list(&b_list,a2,5);

 /* print_list( sorted_intersect(a_list,b_list));
  print_list(a_list);
  print_list(b_list);
  
  reverse(&a_list);
  print_list(a_list);
  recursive_reverse(&a_list);
  print_list(a_list);
  */
  
  print_list(a_list);
  print_list(reverse_list(a_list));
  return 0;
}


