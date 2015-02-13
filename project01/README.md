#Project 01: Hypergraph

###Description:

A Hypergraph is a data structure. Its definition is a graph whose hyperedges connect two or more vertices. It is generalized as an undirected graph. For example the vertices of the hypergraph could be individual countries and the hyperedges could represent one aspect of the country's flag. It requires n x m space, n represents the number of vertices and m is the number of hyperedges. Each row in the matrix would represent a vertex and each column would represent an edge. One basic structure for a hypergraph is an incidence matrix. 

###To use this code:
* Place main.cpp, Hypergraph.cpp and Hypergraph.h in the same directory of your other code. 

* include in the main file at the top #include "Hypergraph.h"

* Also one will have to go into the Hypergraph.cpp file and change the size of the string array for the edges depending on how many edges one needs. Currently it is set to size 30.  

###Implementation 

Implementation of a hypergraph:
* InseretNode - inserts a new vertex into the graph.  
* InsertHyperedge - grabs data from a text file and then inserts the data by calling insertNode. 
* The << operator is overloaded to allow for the graph to be printed out in a semi formatted way. 

### Time complexity:
* Insert takes O(n) time due to the fact that it also is indexing to the correct place then inserting the element.
* Insethyperedge seems to only take O(n^2) time. This is because it will grab each line one at a time then grab each element of that line within a nested while loop

### Contents:
project01 one contains the following files
* Hypergraph.h - header file 
* Hypergraph.cpp - implementation of the Hypergraph

Data file contains:
* csv.dat - 194 countries and their flag characteristics
* dataTen.dat - 10 countries and their flag characteristics
* data1000.dat - 1000 countries and their flag characteristics
* data2000.dat - 2000 countries and their flag characteristics
* data10000.dat - 10000 countries and their flag characteristics

### References:
1. http://xlinux.nist.gov/dads//HTML/hypergraph.html
2. http://xlinux.nist.gov/dads//HTML/hyperedge.html
3. http://en.wikipedia.org/wiki/Hypergraph
4. http://archive.ics.uci.edu/ml/machine-learning-databases/flags/flag.data