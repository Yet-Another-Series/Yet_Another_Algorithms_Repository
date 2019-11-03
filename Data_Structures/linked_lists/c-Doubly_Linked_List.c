
#include <stdio.h>
#include <stdlib.h>
struct node {
	int element;
	struct node *next,*prev;//prev to point to previous element and next to next element
};

struct node *insertLast(struct node *head, int newElement) {
	struct node *newNode, *temp;
	temp = head;
	//A new node is allocated (heap)
	newNode = (struct node*)malloc(sizeof(struct node));
	//The element of newNode is assigned
	newNode->element = newElement;
	//The next pointer of newNode is assigned
	newNode->next = NULL;
	//The prev pointer of newNode is assigned
	newNode -> prev = NULL;
	
	if(head == NULL) { //List is empty
		head = newNode;
	} 
	else { //If list is not empty
		while(temp->next != NULL) { //Until last element of the list.
			temp = temp->next; //Temp pointer will move to next.
		}
		temp->next = newNode; //This will link last element to newNode.
		newNode -> prev = temp; //This will link newNode to last element.
	}
	return head;
};

int get(struct node *head, int position) {
	struct node *temp;
	temp = head;
	if(head == NULL) { //List is empty
		printf("List is empty!\n");
		return -1000;
	} 
	else { //If list is not empty
		int i;
		for(i=0; i < position; i++) { //Until find the exact position of the list.
			temp = temp->next; //Temp pointer will move to next.
		}
	return temp->element;
	}

}

void printList(struct node *head) {
	struct node *temp;
	temp = head;
	if(head == NULL) {
		printf("List is empty!\n");
	}
	else {
		printf("List: ");
		while(temp != NULL) {
			printf("%d ", temp->element);
			temp = temp->next;
		}
	}

}

struct node *removeEle(struct node *head, int position) {
	struct node *temp, *prev;
	temp = head;
	prev = NULL;
	if(head == NULL) {
		printf("List is empty!");
	}
	else {
		int i;
		for (i=0; i<position; i++) {
			prev = temp;
			temp = temp->next;
		}
		
		if(prev == NULL){//Remove First element of DLL
			if(head -> next == NULL){ //If only one element exists
				return NULL;
			}
			head = head -> next;
			head -> prev = NULL;
		}
		else if(temp -> next == NULL){ //Remove Last Element
			prev -> next = NULL;
		}
		else{
			prev->next = temp->next;
			temp->next->prev = prev;
		}
		
		free(temp);
	}
	return head;
}

int sizeList(struct node *head) {
	struct node *temp;
	temp = head;
	int sizeL = 1;
	if(head == NULL) {
		return 0;
	}
	else {
		while(temp->next != NULL) {
			temp = temp->next;
			sizeL++;
		}
		return sizeL;
	}

}

struct node *reverseList(struct node *head) {
	struct node *temp, *prev, *next;
	temp = head;
	prev = NULL;
	while(temp != NULL) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
	return head;

}

int main() {

	struct node *head = NULL;
	head = insertLast(head, 1);
	head = insertLast(head, 2);
	head = insertLast(head, 3);
	head = insertLast(head, 4);
	head = insertLast(head, 5);
	printList(head);
	printf("\n%d\n", get(head, 2));
	head = removeEle(head, 2);
	printList(head);
	printf("\nThe size of the list is %d\n", sizeList(head));
	head = reverseList(head);
	printList(head);
	return 0;
}