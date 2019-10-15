#include <stdio.h>
#include <stdlib.h>

typedef struct s_queue
{
    int data;
    struct s_queue *next;
} t_queue;

typedef enum { false, true } bool;

int front(t_queue *head)
{
    return (head->data);
}

int back(t_queue *head)
{
    while (head->next != NULL) {
        head = head->next;
    }
    return (head->data);
}

bool empty(t_queue *head)
{
    if (head == NULL)
        return (true);
    return (false);
}

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

void pop(t_queue **head)
{
    t_queue *new = *head;

    (*head) = (*head)->next;
    free(new);
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
    emplace(&test, 69);
    // pop(&test);
    push(&test, 1);
    push(&test, 5);
    printf("%d\n", back(test));
    display_list(test);
    return (0);
}