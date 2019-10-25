#include <stdio.h>

int MAX = 10;       
int stack[10];     
int top = -1;            

int isempty() {
   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {
   if(top == MAX)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Stack is empty.\n");
   }
}

int push(int data) {
   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Stack is full.\n");
   }
}

int main() {
  int val=1;
   int data;
   while (val!=0){
      printf(" Select 1 to push ");
      printf(" Select 2 to pop ");
      printf(" Select 3 to peek ");
      printf(" Select 0 to Exit ");
      scanf("%d",&val);
      switch(val){
         case 1: 
            printf("Enter value : ");
            scanf("%d", &data);
            push(data);
            break;
         case 2:
            data=pop();
            printf("Popped data : %d", data);
            break;
         case 3 :
            data=peek();
            printf("The top value is : %d", data);
            break;
         case 0:
            break;
         default:
            printf("Invalid Input");
      }
   }

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}
