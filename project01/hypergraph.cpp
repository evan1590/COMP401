#include <iostream>
#include "Hypergraph.h"

using namespace std;

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

Hypergraph::Hypergraph()
//===============================================\
// inizatlise the graph and sets the root of the  \
// graph to null                                   \
//==================================================\

{
	root = NULL;
}

Hypergraph::~Hypergraph()
{
    cout << "[Hypergraph DTRO (Killed)]" << endl;
}

void Hypergraph::insertNode(string vertex, string* edges)
//======================================================\
// It inserts a new node into the graph. if the roots is \
// null it inserts a new node. If not the it wil continue \
// through the nodes until the current node next is null   \
// it takes in a string as the vertex and an array of edges \
// it returns nothing.                                       \
// ===========================================================\

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
// ================================================= \
// reads in a data file seperated by commas. It grabs \
// each line one at a time then it grabs each element  \
// one at a time. The first element in a line is the    \
// vertex and all other element in the line are put into \
// an array. It then calls the insert node and passes the \
// array and vertex to insertnode. it doesn't have a return\
// value.                                                   \
// ==========================================================\

{
	ifstream infile ("csv.dat");
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
}
