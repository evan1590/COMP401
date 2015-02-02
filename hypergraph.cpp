#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	Node(string);
	~Node();
	Node* next;

	string row;
	vector<string> column; //make array of int 0s and 1s
};

Node::Node(string vertex)
{
	this->row = vertex;
	this->next = NULL; 
}

class Hypergraph
{
public:
	Node* root;

	Hypergraph();
	~Hypergraph();

	void insertNode(string);
	void insertHyperEdge(string, string); 
	void printHypergraph(string);
	
};

Hypergraph::Hypergraph()
{
	root = NULL;
}

void Hypergraph::insertNode(string rows)
{
	if (root == NULL)
	{
		root = new Node(rows);
		cout<< "Root is: " << root->rows << endl;
	}
	else
	{
		Node* currentNode = root;
		while(currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = new Node(rows);	
	}
}

void Hypergraph::insertHyperEdge()
{
/* here we could do a linked list that goes to the right...
	***
		noperes we will have the cargo be the vertex (country) and an array
		of 1s and 0s of the edges (traits of the flag)
	***
 */ 
} 