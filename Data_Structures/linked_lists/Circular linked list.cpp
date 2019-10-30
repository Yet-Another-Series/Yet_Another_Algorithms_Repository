struct Node *addToEmpty(struct Node *last, int data)
{
	// This function is only for empty list
	if (last != NULL)
	return last;

	// Creating a node dynamically.
	struct Node *last =
		(struct Node*)malloc(sizeof(struct Node));

	// Assigning the data.
	last -> data = data;

	// Note : list was empty. We link single node
	// to itself.
	last -> next = last;

	return last;
}
struct Node *addBegin(struct Node *last, int data)
{
if (last == NULL)
	return addToEmpty(last, data);

// Creating a node dynamically.
struct Node *temp
		= (struct Node *)malloc(sizeof(struct Node));

// Assigning the data.
temp -> data = data;

// Adjusting the links.
temp -> next = last -> next;
last -> next = temp;

return last;
}
struct Node *addEnd(struct Node *last, int data)
{
if (last == NULL)
	return addToEmpty(last, data);

// Creating a node dynamically.
struct Node *temp =
		(struct Node *)malloc(sizeof(struct Node));

// Assigning the data.
temp -> data = data;

// Adjusting the links.
temp -> next = last -> next;
last -> next = temp;
last = temp;

return last;
}

struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
	return NULL;

	struct Node *temp, *p;
	p = last -> next;

	// Searching the item.
	do
	{
		if (p ->data == item)
		{
			// Creating a node dynamically.
			temp = (struct Node *)malloc(sizeof(struct Node));

			// Assigning the data.
			temp -> data = data;

			// Adjusting the links.
			temp -> next = p -> next;

			// Adding newly allocated node after p. 
			p -> next = temp;

			// Checking for the last node.
			if (p == last)
				last = temp;

			return last;
		}
		p = p -> next;
	} while (p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;
}
