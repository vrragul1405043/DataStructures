
#include <stdio.h>
#include <stdlib.h>


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

void
k_node_deletion_from_end (int k)
{
  struct node *p = head;
  struct node *q = head;
  struct node *prev;
  for (int i = 1; i < k; i++)
    {
      q = q->next;
    }
  while (q->next != NULL)
    {
      q = q->next;
      prev = p;
      p = p->next;
    }
  prev->next = p->next;
  free (p);
}


int
main ()
{
  insert_tail (43);
  insert_tail (84);
  insert_tail (93);
  insert_tail (17);
  insert_tail (65);
  display ();
  k_node_deletion_from_end (3);
  printf ("\n After Deletion\n");
  display ();
  return 0;
}
