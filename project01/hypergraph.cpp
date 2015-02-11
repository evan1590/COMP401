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

Node::Node(string vertex, string* edges)
{
    int a = 30;
	this->row = vertex;
    this->Data = new string[a];
    for (int i = 0; i < a; ++i)
    {
    	this->Data[i] = edges[i];
    }
	this->next = NULL;
}

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
	void printHypergraph();

	friend ostream& operator<<(ostream& Sout, const Hypergraph&);// allows the graph to be printed out
};

Hypergraph::Hypergraph()
//==================================================\
// inizatlise the graph and sets the root of the     \
// graph to null                                      \
//=====================================================\

{
	root = NULL;
}

Hypergraph::~Hypergraph()
{
    cout << "[Hypergraph DTRO (Killed)]" << endl;
}

void Hypergraph::insertNode(string vertex, string* edges)
//=====================================================\
// It inserts a new node into the graph. if the roots is\
// null it inserts a new node. If not the it wil continue\
// through the nodes until the current node next is null  \
// it takes in a string as the vertex and an array of edges\
// it returns nothing.                                      \
// ==========================================================\

{
	Node* newNode = new Node(vertex, edges);
	if (root == NULL)
	{
		root = newNode;
		// cout<< "Root is: " << root->row << endl;
		// for (int i = 0; i < 29; ++i)
		// {
		// 	cout << "characteristics are: " << root->Data[i] << endl;
		// }

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
// =================================================\
// reads in a data file seperated by commas. It grabs\
// each line one at a time then it grabs each element \
// one at a time. The first element in a line is the   \
// vertex and all other element in the line are put into\
// an array. It then calls the insert node and passes the\
// array and vertex to insertnode. it doesn't have a return\
// value.                                                   \
// ==========================================================\

{
	ifstream infile ("./data/data10000.dat");
	string line;
	int linenum = 0;
	while(getline (infile, line)) // gets each line
	{
		linenum++;
		istringstream linestream(line);
		string item;
		int itemnum = 0;
		string charatristic[30];
		string nodeName;
		while (getline (linestream, item, ',')) // gets each item in each line
		{
			if (itemnum == 0)
			{
				nodeName = item;
			}
			else
			{
				charatristic[itemnum - 1] = item;
			}

			itemnum++;
		}
		insertNode(nodeName, charatristic);
		 // cout << "Country: " << nodeName << endl;
   //       cout << "characteristics: ";
   //       for (int i = 0; i < 30; ++i)
   //       {
   //           cout << charatristic[i] ;
   //       }
   //       cout << endl;
	}
}

ostream& operator<<(ostream& Sout, const Hypergraph& S)
// ===================================================\
// overloads the << operator so the graph can be       \
// printed out                                          \
// ======================================================\

{
	Node* currentNode = S.root;
	while(currentNode->next != NULL)
	{
		cout << currentNode->row << ": " ;
		for (int i = 0; i < 29; ++i)
		{
			cout << currentNode->Data[i];
			cout << "\t" ;
		}
		cout << endl;
		currentNode = currentNode->next;
	}
	if (currentNode->next == NULL)
    {
        cout << currentNode->row << ": " ;
		for (int i = 0; i < 29; ++i)
		{
			cout << currentNode->Data[i];
			cout << "\t" ;
		}
		cout << endl;
    }
}
