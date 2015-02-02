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
	vector<string> column;
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
	bool searchHypergraph(string);
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
		bool looksee = searchHypergraph(rows);
		if (looksee == false)
		{
			Node* currentNode = root;
			while(currentNode->next != NULL)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = new Node(rows);
		}
	}
}

void Hypergraph::insertHyperEdge(string vertex, string edge);
{
	bool looksee = searchHypergraph(edge);
	if (looksee == true)
	{
		bool NotHereSee = true;
		Node* currentNode = root;
		while(currentNode->next != NULL && NotHereSee)
		{
			if (vertex != currentNode->row)
			{
				currentNode = currentNode->next;
			}
			else
			{
				NotHereSee = false;
			}
		}
		if (NotHereSee == false)
		{
			for (std::vector<string>::iterator i = currentNode->column.begin(); i != currentNode->column.end(); ++i)
			{
				if (currentNode->column[i] == edge)
				{
					break
				}
			}
		}
	}
}