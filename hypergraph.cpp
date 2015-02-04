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
	//make array of int 0s and 1s
	int Data[5]; 
};

Node::Node(string vertex)
{
	this->row = vertex;
	this->Data = edges;
	this->next = NULL;
}

class Hypergraph
{
public:
	Node* root;

	Hypergraph();
	~Hypergraph();

	void insertNode(string, );
	void insertHyperData(); 
	void printHypergraph(string);
	
};

Hypergraph::Hypergraph()
{
	root = NULL;
}

void Hypergraph::insertNode(string vertex, int edges[29])
{
	newNode = new Node(vertex, edges)
	if (root == NULL)
	{
		root = newNode;
		cout<< "Root is: " << root->vertex << endl;
	}
	else
	{
		Node* currentNode = root;
		while(currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;	
	}
}

void Hypergraph::insertHyperData()
{
/* here we could do a linked list that goes to the right...
	***
		noperes we will have the cargo be the vertex (country) and an array
		of 1s and 0s of the edges (traits of the flag)
	***
 */ 
	ifstream infile ("csv.dat");
	string line;
	int linenum = 0;
	while(getline (infile, line)) // gets each line
	{
		linenum++;
		istringstream linestream(line);
		string item;
		int itemnum = 0;
		while (getline (linestream, item, ',')) // gets each item in each line
		{
			itemnum++;	
		}
	}	
}

int main()
{
	Hypergraph graph;

	Hypergraph.insertHyperData;
	return 0;
}
 