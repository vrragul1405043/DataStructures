
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



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
display (struct node *head)
{
  struct node *ptr = head;
  while (ptr != NULL)
    {
      printf ("%d\n", ptr->data);
      ptr = ptr->next;
    }
}

void
split_linked_list ()
{
  if (head == NULL || head->next == NULL)
    {
      return;
    }
  struct node *p = head;
  struct node *q = head->next;
  struct node *current;
  struct node *last_p = p;
  struct node *last_q = q;

  bool flag = true;

  if (head->next->next)
    {
      current = head->next->next;
    }

  while (current->next != NULL)
    {
      if (flag)
	{
	  last_p->next = current;
	  last_p = last_p->next;
	  flag = !flag;
	}
      else
	{
	  last_q->next = current;
	  last_q = last_q->next;
	  flag = !flag;
	}
      current = current->next;
    }
  if (flag)
    {
      last_p->next = current;
      last_q->next = NULL;
    }
  else
    {
      last_q->next = current;
      last_p->next = NULL;
    }
  display (p);
  printf ("-----------\n");
  display (q);

}

int
main ()
{
  insert_tail (41);
  insert_tail (42);
  insert_tail (43);
  insert_tail (44);
  insert_tail (45);
  insert_tail (46);
  split_linked_list ();
  return 0;
}
