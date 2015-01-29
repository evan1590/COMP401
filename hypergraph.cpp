#include <iostream>

using namespace std;

class Node
{
public:
	Node(string);
	~Node();
	Node* next;

	string row;
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

