#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct l{
  int d;
  struct l* next;
}List;

List* createList()
{
  return NULL;
}
List *reverse(List *l)
{
  List *current=l;
  List* prev=createList();
  List* next=createList();
  while(current)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  l=prev;
  return l;
}
List *insert(List *l,int val)
{
  List *temp=l;
  if(temp==NULL)
  {
    l=(List*)malloc(sizeof(List));
    l->d=val;
    l->next=NULL;
    return l;
  }
  while(temp->next)
  {
    temp=temp->next;
  }
  temp->next=(List*)malloc(sizeof(List));
  temp->next->d=val;
  temp->next->next=NULL;
  return l;
}
void printList(List* l)
{
  List* temp=l;
  while(temp)
  {
    printf("%d ",temp->d);
    temp=(List*)temp->next;
  }
  printf("\n" );
}
List *deleteNode(List* l, int key)
{
    List *temp =l;
    List *prev;
    if (temp != NULL && temp->d == key)
    {
        l = temp->next;
        free(temp);
        return l;
    }
    while (temp != NULL && temp->d != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {printf("Not found.\n" );return l;}
    prev->next = temp->next;
    free(temp);
    return l;
}
int main()
{
  List *l=createList();
  l=insert(l,3);
  l=insert(l,5);
  l=insert(l,7);
  printList(l);
  l=reverse(l);
  l = deleteNode(l,7);
  printList(l);
  free(l);
  return 0;
}
