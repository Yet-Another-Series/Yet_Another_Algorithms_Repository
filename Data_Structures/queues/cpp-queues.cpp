
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



#include <iostream>
#include <queue>
#include <vector>
#include <ctype.h>

using namespace std;

// function to get the input of type "inp_type" and prevent any wrong input
template <typename inp_type>
inp_type get_input(const char * message, inp_type _resp) {
	cout << message;
	inp_type resp;
	while(!(cin >> resp)){
		cout << "Input failed...try again\n";
		cin.clear();
		while(cin.get() != '\n');
		cout << message;
	}
	cin.clear();
	while(cin.get() != '\n');
	return resp;
}

/*********** Implementation ************/
// Generic queue of type "queue_type"
// uses a vector for dynamic storage
template <typename queue_type>
class cppQueue {
	public:
	vector<queue_type> v;
	template<class inp_type>
	friend inp_type get_input(const char *, inp_type _resp);
	
	// enqueue, dequeue, isEmpty, peek, display
	void enqueue() {
		queue_type value;
		value = get_input("Enter value to add to the queue: ", value);
		v.push_back(value);	
		cout << "Enqueued " << value << " successfully\n";
	}

	void dequeue() {
		if (_isEmpty()) {
			cout << "!!!Empty queue!!!\n";
			return;
		}
		queue_type t = v[0];
		v.erase(v.begin());
		cout << "Dequeued " << t << endl;
	}

	void isEmpty() {
		cout << ((v.size() == 0)?"True":"False") << endl;
	}

	queue_type peek() {
		if(_isEmpty()) 
			cout <<"!!!Empty queue!!!\n";
		 else
			cout << v[0] << endl;
	}
	
	void displayAllElements() {
		if(_isEmpty()) 
			cout <<"!!!Empty queue!!!\n";
		 else
		{
			cout << "Elements of the queue:\n";
			for (auto i:v) {
				cout << i << ", " ;
			}
			// move back two spaces and replace the last ',' with a ' '
			cout << '\b';
			cout << '\b';
			cout << " ";
			cout << endl;
		}
	}

	private:
	bool _isEmpty() {
		return (v.size() == 0);	
	}
};
/******* End of implementation ********/


// driver program to test queue
int main() {
	cppQueue<double> cq; // you can change the type to any other to test if it works fine.
	int resp, value;
	while (true) {
		cout << "***************************************\n";
		cout << "Enter your choice :                   *\n";
		cout << "1: Enqueue an element                 *\n";
		cout << "2: Dequeue an element                 *\n";
		cout << "3: Check if queue is empty            *\n";
		cout << "4: See the first element of the queue *\n";
		cout << "5: Display all elements               *\n";
		cout << "6: Quit                               *\n";
		cout << "***************************************\n";
		
		resp = get_input("Choice: ", resp);
	
		switch (resp) {
			case 1:	
			cq.enqueue();
			break;

			case 2:
			cq.dequeue();
			break;

			case 3:
			cq.isEmpty();
			break;

			case 4:
			cq.peek();
			break;

			case 5:
			cq.displayAllElements();
			break;
			
			case 6:
			cout << "Bye...\n";
			return 0;

			default:
			cout << "Wrong input entered.. Try again." << endl;
		}
	}
	return 0;
}
