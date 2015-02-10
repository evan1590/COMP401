// name: Evan Chessman
// date: 2/7/2015
//
// Description: Creates a hypergraph, it reads in a data file
//              and inserts the first element of each line as a
//              vertex. All other elements in the line are stored
//              in an array and inserted into a linked list. it is
//              an Incidence mactix
//
// Input: There is no user input. It reads in a data file seperated
//        by commas it is a .dat file.
//
// Output: The hypergraph is printed out in a semi fromated way.
//
//===================================================================
#ifndef FOO_Hypergraph
#define FOO_Hypergraph

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Node
//------------------------------------------------\
// Node a place to store date for the linked list. \
// These nodes store a string that acts as a vertex \
// and a string array that stores the hyperedges. and\
// a pointer to another Node called next.             \
// ----------------------------------------------------\

{
public:
	Node(string, string*); // constructor
	~Node(); //deconstructor

	Node* next; // pointer to the next node is set to null
	string row; //stores the verticies
	string* Data; // stores the hyperedges
};

class Hypergraph
//================================================\
// The verticies of the hypergraph are the string  \
// stores in the Node class aka (name). The edges of\
// the graph are subsets of more than two vertivies  \
// In this case they are the charateristics.          \
// Methods : insert Node, insert Data(get data), print \
//======================================================\

{
public:
	Node* root; // sets the head of the graph

	Hypergraph(); // constructor
	~Hypergraph(); // deconstructor

	void insertNode(string, string*); //inserts a new row
	void insertHyperData(); // reads in a data file and gets the data

	friend ostream& operator<<(ostream& Sout, const Hypergraph&);// allows the graph to be printed out
};
#endif
