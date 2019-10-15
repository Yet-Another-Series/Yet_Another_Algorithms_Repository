/*
 * c++-queues.cpp
 *
 *  Created on: 12 de out de 2019
 *      Author: Luana Brasil Teixeira
 */
#include <iostream>
#include <queue>

using namespace std;

//Function to show queue's elements

void showqueue(queue <int> queueExample) {

	//empty(): returns if the queue is empty
	//front(): shows the front element
	//pop(): removes the front element

	/*While the queue isn't empty, print the front element and remove it.
	This way we can print all the elements one by one.*/

    while (!queueExample.empty())
    {
        cout << '\t' << queueExample.front();
        queueExample.pop();
    }

}

//Main

int main() {

	//Declaring a queue

    queue <int> queueExample;

    //push(): adds an element to the back of the queue

    queueExample.push(10);
    queueExample.push(20);
    queueExample.push(30);

    cout << "The queue is: ";
    showqueue(queueExample);
    cout << "\n";

    //size.(): returns the size of the queue
    //back(): shows the back element

    cout << "size: " << queueExample.size() << "\n";
    cout << "front: " << queueExample.front() << "\n";
    cout << "back: " << queueExample.back() << "\n";

    //Removing the front element

    cout << "pop: ";
    queueExample.pop();
    showqueue(queueExample);
    cout << "\n";

    return 0;
}



