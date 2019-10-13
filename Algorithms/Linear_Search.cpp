/* Simple Linear Search Program in C++*/
/* Data Structure C++ Programs,C++ Array Examples */

#include <iostream>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 5

using namespace std;

int main() {
    int arr_search[MAX_SIZE], i, element;

    cout << "Simple C++ Linear Search Example - Array\n";
    cout << "\nEnter " << MAX_SIZE << " Elements for Searching : " << endl;
    for (i = 0; i < MAX_SIZE; i++)
        cin >> arr_search[i];

    cout << "\nYour Data   :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << arr_search[i];
    }

    cout << "\nEnter Element to Search : ";
    cin>>element;

    /* for : Check elements one by one - Linear */
    for (i = 0; i < MAX_SIZE; i++) {
        /* If for Check element found or not */
        if (arr_search[i] == element) {
            cout << "\nLinear Search : Element  : " << element << " : Found :  Position : " << i + 1 << ".\n";
            break;
        }
    }

    if (i == MAX_SIZE)
        cout << "\nSearch Element : " << element << "  : Not Found \n";

    getch();
}
