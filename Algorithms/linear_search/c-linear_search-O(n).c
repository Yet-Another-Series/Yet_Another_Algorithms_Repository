//program to perform linear search on an interger array
#include<stdio.h>
#include<stdlib.h>
void read_Array(int* array, int size)
{
    for(int i = 0; i < size; ++i)
    {
        scanf("%d", &array[i]);
    }
}

int linear_Search(int* array, int size, int key) //performs linear search to search for the key in the array
{
    int index = 0;
    int found = 0;
    int i = 0;
    while(!found && i < size)
    {
        if(array[i] == key)
        {
            found = 1;
        }
        else
        {
            ++index;
        }
        ++i;
        
    }
    if(found)
        return index;
    else
        return -1;
}

int main()
{
    int size, key, index;
    printf("Enter the size of the array\n");
    scanf("%d", &size);
    int* array = (int*)malloc(sizeof(int));
    printf("\nEnter the elements of the array\n");
    read_Array(array, size);
    printf("\nEnter the key\n");
    scanf("%d", &key);
    index = linear_Search(array, size, key);
    if(index != -1) 
        printf("Key found at index %d", index);
    else
        printf("\nKey not found\n");
    return 0;   
}