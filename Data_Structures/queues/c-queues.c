#include <stdio.h>
#include <stdlib.h>

typedef struct s_queue
{
    int data;
    struct s_queue *next;
} t_queue;

void push(t_queue **head, int data)
{
    t_queue *new = malloc(sizeof(t_queue));
    if (new == NULL)
        return ;
    new->next = (*head);
    new->data = data;
    (*head) = new;
}

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

void display_list(t_queue *head)
{
    printf("Displaying:\n");
    for (int i = 1; head != NULL; i++) {
        printf("data is: %d    on node: %d\n", head->data, i);
        head = head->next;
    }
}

int main()
{
    t_queue *test = NULL;
    // push(&test, 5);
    // push(&test, 16);
    emplace(&test, 69);
    display_list(test);
    return (0);
}