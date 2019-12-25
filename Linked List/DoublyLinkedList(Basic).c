/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};


struct node *head = NULL;


struct node *
getNewNode (int x)
{
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->data = x;
  temp->next = temp->prev = NULL;
  return temp;
}

void
insertAtTail (int x)
{
  struct node *newNode = getNewNode (x);
  struct node *ptr;

  if (head == NULL)
    {
      head = newNode;
    }
  else
    {
      ptr = head;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->next = newNode;
      newNode->prev = ptr;
    }
}


void
insertAtHead (int x)
{
  struct node *newNode = getNewNode (x);
  struct node *ptr;

  if (head == NULL)
    {
      head = newNode;
    }
  else
    {
      ptr = head;
      ptr->prev = newNode;
      newNode->next = ptr;
      head = newNode;
    }
}

void
display ()
{
  struct node *ptr = head;
  while (ptr != NULL)
    {
      printf ("%d\t", ptr->data);
      ptr = ptr->next;
    }
}

void
reverseDisplay ()
{
  struct node *ptr = head;
  while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
  while (ptr != NULL)
    {
      printf ("%d\t", ptr->data);
      ptr = ptr->prev;
    }
}

int
main ()
{
  insertAtTail (45);
  insertAtTail (56);		//45->56
  insertAtHead (64);		//64->45->56;
  printf ("\n");
  display ();			//64->45->56
  printf ("\n");
  reverseDisplay ();		//56->45->64
  return 0;
}
