#include <iostream>

#include "Hypergraph.h"

using namespace std;

int main()
{
	Hypergraph graph;

	graph.insertHyperData();
    cout << graph;
	return 0;
}
