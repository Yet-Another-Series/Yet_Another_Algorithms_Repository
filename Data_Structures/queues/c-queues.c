#include <stdio.h>
#include <stdlib.h>

/** Data structure I use in this (data type can be replace by another type)
 */
typedef struct s_queue
{
    int data;
    struct s_queue *next;
} t_queue;

/** typedef for bool type in C
 */
typedef enum { false, true } bool;

/** front: return the first data of the list
 * @param reference of the head node
 * @return data from the front node
 */
int front(t_queue *head)
{
    return (head->data);
}
/** back: return the last data of the list
 * @param reference of the head node
 * @return data from the last node
 */
int back(t_queue *head)
{
    while (head->next != NULL) {
        head = head->next;
    }
    return (head->data);
}

/** empty: return true if the queue is empty and false otherwise
 * @param reference of the head node
 */
bool empty(t_queue *head)
{
    if (head == NULL)
        return (true);
    return (false);
}

/** size: return the size of the queue
 * @param reference of the head node
 * @return size of the queue
 */
unsigned int size(t_queue *head)
{
    int size;

    for (size = 0; head != NULL; size++, head = head->next);
    return (size);
}

/** push: the data in the queue
 * @param reference of the head node
 * @param data you want to push in the queue
 */
void push(t_queue **head, int data)
{
    t_queue *new = malloc(sizeof(t_queue));
    if (new == NULL)
        return ;
    new->next = (*head);
    new->data = data;
    (*head) = new;
}

/** emplace: put the data a the end of the queue
 * @param reference of the head node
 * @param data you want to emplace in the queue
 */
void emplace(t_queue **head, int data)
{
    t_queue *new = malloc(sizeof(t_queue));
    if (new == NULL)
        return ;
    new->data = data;
    if ((*head) == NULL) {
        new->next = (*head);
        (*head) = new;
        return ;
    }
    t_queue *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    new->next = NULL;
    tmp->next = new;
}

/** pop: pop the first value of the queue
 * @param reference of the head node
 */
void pop(t_queue **head)
{
    t_queue *new = *head;

    (*head) = (*head)->next;
    free(new);
}

/** display_list: display the list for debug
 *  @param reference of the head node
 */
void display_list(t_queue *head)
{
    printf("Displaying:\n");
    for (int i = 1; head != NULL; i++) {
        printf("data is: %d    on node: %d\n", head->data, i);
        head = head->next;
    }
}


/**
*/
 int main()
 {
     t_queue *test = NULL;
     emplace(&test, 69);
     pop(&test);
     push(&test, 1);
     push(&test, 5);
     printf("%d\n", size(test));
     display_list(test);
     return (0);
 }
