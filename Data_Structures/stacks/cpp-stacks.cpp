/*
 * c++-stacks.cpp
 *
 *  Created on: 12 de out de 2019
 *      Author: Luana Brasil Teixeira
 */
#include<iostream>
#include<stack>

using namespace std;

//Function to show stack's elements

void showstack(stack <int> stackExample) {

	//empty(): returns if the stack is empty
	//top(): shows the top element
	//pop(): removes the top element

	/*While the stack isn't empty, print the top element and remove it.
	This way we can print all the elements one by one.*/

    while (!stackExample.empty())
    {
        cout << '\t' << stackExample.top();
        stackExample.pop();
    }

}

//Main

int main () {


	//Declaring a stack

	stack <int> stackExample;

    //push(): adds an element to the top of the stack

    stackExample.push(10);
    stackExample.push(30);
    stackExample.push(20);
    stackExample.push(5);
    stackExample.push(1);

    cout << "The stack is : ";
    showstack(stackExample);
    cout << "\n";

    //size(): returns the size of the stack

    cout << "size: " << stackExample.size() << "\n";
    cout << "top element: " << stackExample.top() << "\n";


    //Removing the top element

    cout << "pop: ";
    stackExample.pop();
    showstack(stackExample);
    cout << "\n";

    return 0;
}
