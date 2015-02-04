#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Node
{
public:
	Node(string, string*);
	~Node();
	Node* next;

	string row;
	//make array of int 0s and 1s
	string * Data[30];
};

Node::Node(string vertex, string* edges)
{
	this->row = vertex;
	//this->Data = edges[30];
	this->next = NULL;
}

class Hypergraph
{
public:
	Node* root;

	Hypergraph();
	~Hypergraph();

	void insertNode(string, string*);
	void insertHyperData();
	void printHypergraph(string);

};

Hypergraph::Hypergraph()
{
	root = NULL;
}

Hypergraph::~Hypergraph()
{
    cout << "[Hypergraph DTRO (Killed)]" << endl;
}

void Hypergraph::insertNode(string vertex, string* edges)
{
	Node* newNode = new Node(vertex, edges);
	if (root == NULL)
	{
		root = newNode;
		cout<< "Root is: " << root->row << endl;
		for (int i = 0; i < 30; ++i)
		{
			cout << "characteristics are: " << &root->Data[i] << endl;
		}

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

int main()
{
	Hypergraph graph;

	graph.insertHyperData();
	return 0;
}
