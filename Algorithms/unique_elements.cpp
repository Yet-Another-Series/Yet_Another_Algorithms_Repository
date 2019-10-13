#include <iostream>
using namespace std;


int main()
{
    int array1[] = {1, 5, 7, 5, 8, 9, 11, 11, 2, 5, 6};
    int s1 = sizeof(array1)/sizeof(array1[0]);

    cout << "Original array: ";
    
    for (int i=0; i < s1; i++) 
    cout << array1[i] <<" ";
    
    cout <<"\nCommon elements of the said array: ";
    for (int i=0; i<s1; i++)
    {
        int j;
        for (j=0; j<i; j++)
           if (array1[i] == array1[j])
               break;
         if (i == j)
          cout << array1[i] << " ";
    }
    return 0; 
}
