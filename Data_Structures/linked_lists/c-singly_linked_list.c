#include <stdio.h>
#include <stdlib.h>
 
struct node {
   int data;
   struct node *next;
};
 
struct node *start = NULL;
void insert_at_begining(int);
void insert_at_end(int);
void traverse();
void delete_from_begining();
void delete_from_end();
int count = 0;
 
int main () {
   int input, data;
   
while(input!=6) {
      printf("1. Insert at the beginning of the linked list.\n");
      printf("2. Insert at the end of the linked list.\n");
      printf("3. Traverse the linked list.\n");
      printf("4. Delete from beginning.\n");
      printf("5. Delete from end.\n");
      printf("6. Exit\n");
     
      scanf("%d", &input);
     switch(input){
     
      case 1: 
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_begining(data);
         break;
      case 2:
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_end(data);
         break;
         
      case 3:
         traverse();

     case 4:
         delete_from_begining();  
         break;
     case 5:
          delete_from_end();
          break;
     case 6:
          break;
     default:
         printf("Invalid Input.\n");  
         break;
   }}
   
   return 0;
}
 
void insert_at_begining(int x) {
   struct node *t;
   
   t = (struct node*)malloc(sizeof(struct node));
   count++;
     
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   t->data = x;
   t->next = start;
   start = t;
}
 
void insert_at_end(int x) {
   struct node *t, *temp;
   
   t = (struct node*)malloc(sizeof(struct node));
   count++;
   
   if (start == NULL) {
      start = t;
      start->data = x;
      start->next = NULL;
      return;
   }
   
   temp = start;
   
   while (temp->next != NULL)
      temp = temp->next;  
   
   temp->next = t;
   t->data    = x;
   t->next    = NULL;
}
 
void traverse() {
   struct node *t;
   
   t = start;
   
   if (t == NULL) {
      printf("Linked list is empty.\n");
      return;
   }
   
   printf("There are %d elements in linked list.\n", count);
   
   while (t->next != NULL) {
      printf("%d\n", t->data);
      t = t->next;
   }
   printf("%d\n", t->data);
}
 
void delete_from_begining() {
   struct node *t;
   int n;
   
   if (start == NULL) {
      printf("Linked list is already empty.\n");
      return;
   }
   
   n = start->data;
   t = start->next;
   free(start);
   start = t;
   count--;
   
   printf("%d deleted from beginning successfully.\n", n);
}
 
void delete_from_end() {
   struct node *t, *u;
   int n;
     
   if (start == NULL) {
      printf("Linked list is already empty.\n");
      return;
   }
   
   count--;
   
   if (start->next == NULL) {
      n = start->data;
      free(start);
      start = NULL;
      printf("%d deleted from end successfully.\n", n);
      return;
   }
   
   t = start;
   
   while (t->next != NULL) {
      u = t;
      t = t->next;
   }
   
   n = t->data;
   u->next = NULL;
   free(t);
   
   printf("%d deleted from end successfully.\n", n);
}
