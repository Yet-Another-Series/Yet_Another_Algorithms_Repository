#include<bits/stdc++.h>
using namespace std;
struct node{
 int data;
 struct node*next;
}; 
// used for inserting datas in the linked-list
void push(struct node**head,int e)
{
    struct node*root=(struct node*)malloc(sizeof (struct node));
    root->data=e;
    root->next=*head;
    *head=root;
}
// when the s_ptr and f_ptr meets at a same node other than head then a loop is found
bool detection(struct node*head)
{
  struct node* s_ptr=head,*f_ptr=head;
  int p=0;
  while(f_ptr!=NULL and f_ptr->next!=NULL)
  {
      f_ptr=f_ptr->next->next;
      s_ptr=s_ptr->next;
      if(f_ptr==s_ptr)
      {
          p=1;
          break;
      }
  }
  if (p)return 1;
  else return 0;
}
int main()
{
    // node points to null initially
    struct node*root=NULL;
    push(&root,1);
    push(&root,2);
    push(&root,3);
    push(&root,4);
    if(detection(root))
    {
        cout<<"found\n";
    }
    else{
        cout<<"Not\n";
    }


}