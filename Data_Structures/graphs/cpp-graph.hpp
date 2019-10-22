#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <fstream>

#define MAXINT 2147483647

struct Vertex
{
	int value;
	std::unordered_map<Vertex*, int> adjList;
	bool visited = false; //automatically defaults all nodes to unvisited
	int weight;

	Vertex(int value)
	{
		this->value = value;
		this->adjList = adjList;
		this->visited = false;
	}

	void newEdge(Vertex* node, int weight)
	{
		adjList.insert({ node, weight });
	}

	int getValue() //needed otherwise returning value just gives memeory address
	{
		return value;
	}

	bool printAdj() //just prints adjacent nodes and says node is disconnectied if there are no connections
	{
		if (adjList.size() != NULL)
		{
			for (auto i : adjList)
			{
				std::cout << " -> " << i.first->getValue() << "(" << i.second << ") ";
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Node is disconnected " << std::endl;
			return false;
		}
		return true;
	}
};


struct Graph
{
	std::vector<Vertex*> vertices;

	Graph()
	{
		this->vertices = vertices;
	}

	void newNode(int item)
	{
		Vertex* node = new Vertex(item);
		//std::unique_ptr<Vertex> node(new Vertex(item)); //i cant get smart pointer to work plzzz help
		vertices.push_back(node);
		std::cout << node->getValue() << " has been added to the list of vertices" << std::endl;
	}

	void newEdges(Vertex* n1, Vertex* n2, int weight)
	{
		n1->newEdge(n2, weight);
		n2->newEdge(n1, weight);

		std::cout << "weight of edge: " << weight << std::endl;
	}

	void displayGraph()
	{
		std::cout << "vertices: " << std::endl;
		for (int i = 0; i < vertices.size(); i++)
		{
			std::cout << vertices[i]->getValue() << ", ";
		}
		std::cout << std::endl;
	}

	void printGraph(Vertex* node)
	{
		std::cout << "vertices: " << std::endl;
		for (int i = 0; i < vertices.size(); i++)
		{
			std::cout << vertices[i]->getValue() << ", ";
			std::cout << "vertices adjacent to " << node->getValue() << std::endl;
			node->printAdj();
		}
		std::cout << std::endl;
	}

	Vertex* returnNode(int value)
	{
		for (int i = 0; i < vertices.size(); i++) //iterates over the vertices vector 
		{
			if (vertices[i]->getValue() == value)
				//just linear searches the vector until the vector element matches the node the user wants to find
			{
				return vertices[i];
			}
		}
		return nullptr;
	}

	void resetVisited(Graph* g)
	{
		for (int i = 0; i < vertices.size(); i++)
			vertices[i]->visited = false;
	}

	std::vector<int> DFS(Graph* g, Vertex* n)
	{
		g->resetVisited(g);
		std::vector<int> path;
		std::ofstream file;
		file.open("dfs.txt", std::ofstream::app);
		//resetVisited(g, n);
		std::cout << "depth first search:\n";
		std::stack<Vertex*> stack;
		stack.push(n); //push first node to stack
		while (!stack.empty())
		{
			if (stack.top()->visited == false)
			{
				path.push_back(stack.top()->getValue());
				std::cout << stack.top()->getValue() << ", "; //prints node
				int nodeVal = stack.top()->getValue();
				file << nodeVal;
				stack.top()->visited = true; //sets node to visited
			}
			Vertex* top = stack.top();
			stack.pop();
			for (auto i : top->adjList) //push adjacent nodes to stack
			{
				if (i.first->visited == false)
				{
					stack.push(i.first);
				}
			}
		}
		for (int i = 0; i < path.size(); i++)
		{
			std::cout << path[i];
		}
		return path;
	}

	void DFSTest(Graph* g, Vertex* n)
	{
		std::stack<int> q;
		resetVisited(g);
		q.push(n->getValue());
		n->visited = true;
		while (!q.empty())
		{
			int temp = q.top();
			q.pop();
			std::cout << temp << " ";
			for (auto i : n->adjList)
			{
				if (i.first->visited == false)
				{
					i.first->visited = true;
					q.push(i.first->getValue());
				}
			}
		}
	}

	void dfstestWholeGraph(Graph* g)
	{
		g->resetVisited(g);

		for (int i = 0; i < g->vertices.size(); i++)
		{
			g->DFSTest(g, g->vertices[i]);
			std::cout << std::endl;
		}
	}


	void BFSTest(Graph* g, Vertex* n)
	{
		std::queue<int> q;
		resetVisited(g);
		q.push(n->getValue());
		n->visited = true;
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			std::cout << temp << " ";
			for (auto i : n->adjList)
			{
				if (i.first->visited == false)
				{
					i.first->visited = true;
					q.push(i.first->getValue());
				}
			}
		}
	}


	void bfstestWholeGraph(Graph* g)
	{
		g->resetVisited(g);

		for (int i = 0; i < g->vertices.size(); i++)
		{
			g->BFSTest(g, g->vertices[i]);
			std::cout << std::endl;
		}
	}

	std::vector<int> BFS(Graph* g, Vertex* n)
	{
		g->resetVisited(g);
		//PRINTING PATH TRAVERSED TO TXT FILE DOES NOT WORK WITH bfsWholeGraph
		std::ofstream file;
		std::vector<int> path;
		file.open("bfs.txt", std::ofstream::app);
		//resetVisited(g, n);
		std::cout << "braedth first search:\n";
		std::queue<Vertex*> queue;
		queue.push(n);
		//std::vector<int>::iterator i;
		while (!queue.empty())
		{
			if (queue.front()->visited == false)
			{
				path.push_back(queue.front()->getValue());
				std::cout << queue.front()->getValue() << ", ";
				int nodeVal = queue.front()->getValue();
				file << nodeVal;
			}
			Vertex* top = queue.front();
			top->visited = true;
			queue.pop();
			for (auto i : top->adjList)
			{
				if (i.first->visited == false)
				{
					queue.push(i.first);
				}
			}
		}
		for (int i = 0; i < path.size(); i++)
		{
			std::cout << path[i];
		}
		return path;
	}

	void bfsWholeGraph(Graph* g)
	{
		g->resetVisited(g);

		for (int i = 0; i < g->vertices.size(); i++)
		{
			g->BFS(g, g->vertices[i]);
			std::cout << std::endl;
		}
	}

	void dfsWholeGraph(Graph* g)
	{
		g->resetVisited(g);
		for (int i = 0; i < g->vertices.size(); i++)
		{
			g->DFS(g, g->vertices[i]);
			std::cout << std::endl;
		}
	}

	bool isPath(Graph* g, Vertex* v, Vertex* w)
	{
		resetVisited(g);
		if (v == w) // checks if the first node is the same as the one youre searching for
			return true; //returns true if it is

		std::stack<Vertex*> pathQueue;
		//made of of type Vertex so i can access the adjlist, considered using vector instead of queue but accessing first place of queue is much easier
		pathQueue.push(v); //places the starting node at the FRONT of the queue
		while (!pathQueue.empty())
		{
			pathQueue.top()->visited = true;
			Vertex* queueFront = pathQueue.top();
			//assigning this was important because writing pathQueue.front() in the if statement and for loop gives a runtime error stating deque iterator not dereferencable
			pathQueue.pop();
			if (queueFront == w)
			{
				std::cout << "There  is a path between the 2 nodes.";
				return true;
			}
			for (auto i : queueFront->adjList)
			{
				if (i.first->visited == false)
					pathQueue.push(i.first);
			}
		}
		std::cout << "no path between the 2 nodes";
		return false;
	}


	/*Checks if each individual node is conneccted
	only used within the isconnected function to
	make it easier*/
	bool isConnectedUtil(Graph* g)
	{
		for (auto i = 0; i < vertices.size(); ++i)
		{
			std::cout << vertices[i]->getValue();
			//have to call the posititon of vertices[i] like this otherwise it returns a memory address
			if (vertices[i]->printAdj() == false)
			{
				return false;
			}
		}
		return true;
	}

	/*checks if the graph as a whole is connected7*/
	bool isConnected(Graph* g)
	{
		if (isConnectedUtil(g) == true)
		{
			std::cout << "graph connected\n";
			return true;
		}
		std::cout << "graph not connected\n";
		return false;
	}

	int findLowestWeight()
	{
		int lowestWeight = MAXINT;
		int lowestWeightNode = 0;
		for (int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i]->visited == false && vertices[i]->weight <= lowestWeight)
			{
				lowestWeight = vertices[i]->weight;
				lowestWeightNode = i;
			}
		}
		return lowestWeightNode;
	}

	int dijkstra(Graph* g, Vertex* n1, Vertex* n2)
	{
		g->resetVisited(g);
		std::vector<Vertex*> path;
		if (isPath(g, n1, n2) == false)
		{
			std::cout << "Cannot perform dijkstras algorithm as the 2 nodes are not connected" << std::endl;
			return 0;
		}
		for (int i = 0; i < vertices.size(); i++)
		{
			// reset visited for each node and set the weight the closest thing to infinite
			vertices[i]->weight = MAXINT;
			vertices[i]->visited = false;
		}
		n1->weight = 0; //set the starting node to weight 0
		path.push_back(n1);
		for (int i = 0; i < vertices.size(); i++)
		{
			path.push_back(vertices[i]);
			int curr = findLowestWeight();

			if (vertices[i]->visited == false)
			{
				vertices[curr]->visited = true;
			}
			for (auto i : vertices[curr]->adjList)
			{
				if (vertices[curr]->weight + i.second < i.first->weight)
				{
					i.first->weight = vertices[curr]->weight + i.second;
				}
			}
		}
		std::cout << "shortest pasth: " << n1->getValue() << " to " << n2->getValue() << " is: " << n2->weight << std::
			endl;
		g->resetVisited(g);
		for (auto i : vertices)
		{
			std::cout << i->getValue();
		}
		return n2->weight;
	}
};
