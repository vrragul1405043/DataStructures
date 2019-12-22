#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node *next;
};


struct node *head = NULL;

void
insert_tail (int x)
{
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->data = x;
  temp->next = NULL;

  struct node *ptr = head;

  if (ptr == NULL)
    {
      head = temp;
    }
  else
    {
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->next = temp;
    }
}

void
display ()
{
  struct node *ptr = head;
  while (ptr != NULL)
    {
      printf ("%d\n", ptr->data);
      ptr = ptr->next;
    }
}

bool
isLoop (struct node *head)
{
  struct node *slow = head;
  struct node *fast = head;

  while (slow && fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
	{
	  return true;
	}
    }
  return false;
}

int
main ()
{
  insert_tail (43);
  insert_tail (76);
  insert_tail (19);
  insert_tail (65);
  insert_tail (99);
  display ();
  bool flag = isLoop (head);
  (flag) ? (printf ("\nThe loop exists")) : (printf ("\n No loop exists"));
  return 0;
}
