/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
  char data;
  struct node *next;
};

struct node *head = NULL;


void
insert_tail (char x)
{
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->data = x;
  temp->next = NULL;

  if (head == NULL)
    {
      head = temp;
    }
  else
    {
      struct node *ptr = head;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->next = temp;
    }
}

void
display (struct node *head)
{
  struct node *ptr = head;
  while (ptr != NULL)
    {
      printf ("%c\n", ptr->data);
      ptr = ptr->next;
    }
}

struct node *
reverse (struct node *ptr)
{
  struct node *prev = NULL;
  struct node *current = ptr;
  struct node *after;

  while (current != NULL)
    {
      after = current->next;
      current->next = prev;
      prev = current;
      current = after;
    }
  //display(prev);
  return prev;
}

int
isPalindrome ()
{
  int flag = 0;
  if (head == NULL)
    {
      return 0;
    }

  struct node *ptr = head;
  struct node *slow = head;
  struct node *fast = head;
  struct node *slow_prev;
  struct node *middle;


  // finding the middle element

  while (slow != NULL && fast != NULL && fast->next != NULL)
    {
      slow_prev = slow;		// for the purpose of even number of nodes
      slow = slow->next;
      fast = fast->next->next;
    }				//end while

  //even number of nodes
  if (fast == NULL)
    {
      middle = slow_prev;
      //display(middle);
    }

  // odd number of nodes
  else if (fast->next == NULL)
    {
      middle = slow;
    }

  struct node *new_head = reverse (middle->next);
  struct node *ptr1 = head;
  struct node *ptr2 = new_head;

  while ((ptr1 != NULL) && (ptr2 != NULL))
    {
      if (ptr1->data == ptr2->data)
	{
	  ptr1 = ptr1->next;
	  ptr2 = ptr2->next;
	}
      else
	{
	  flag = -1;
	  return flag;
	}
    }				// end while
  return flag;
}

int
main ()
{
  int flag;
  // insert_tail('k');
  // insert_tail('a');
  // insert_tail('y');
  // insert_tail('a');
  // insert_tail('k');

  insert_tail ('n');
  insert_tail ('o');
  insert_tail ('o');
  insert_tail ('n');
  //display(head);
  flag = isPalindrome ();
  if (flag == 0)
    {
      printf ("\n Palindrome");
    }
  else
    {
      printf ("\n Not a palindrome");
    }
  return 0;
}
