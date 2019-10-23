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
  
   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}
