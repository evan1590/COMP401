#Project 01: Hypergraph

###Description:

A Hypergraph is a data structure. Its definition is a graph whose hyperedges connect two or more vertices. it is generalized as an undirected graph. For example the verticies of the hypergraph could be individual countries and the hyperedges could represent one aspect of the country's flag. It requires n x m space, n represents the number of verticies and m is the number of hyperedges. Each row in the matrix would represent a vertex and each column would represent an edge. One basic structure for a hypergraph is an incidence matrix. 

###To use this code:
* place main.cpp, Hypergraph.cpp and Hypergraph.h in the same directory of your other code. 

* include in the main file at the top #include "Hypergraph.h"

* Also one will have to go into the Hypergraph.cpp file and change the size of the string array for the edges depending on how many edges one needs. currently it is set to size 30.  

###Implementation 

implementation of a hypergraph:
* inseretNode - inserts a new vertex into the graph
* insertHyperedge - grabs data from a tex file and then inserts the 					  data by calling insertNode

* The << operator is overloaded to allow for the graph to be printed out in a semi formatted way. 

### Contents:
* project01 one contains the following files
..* Hypergraph.h - header file 
..* Hypergraph.cpp - implementation of the Hypergraph

* data file contains:
	..* csv.dat - 194 countries and their flag charaterastics
	..* dataTen.dat - 10 countries and their flag charaterastics
	..* data1000.dat - 1000 countries and their flag charaterastics
	..*	data2000.dat - 2000 countries and their flag charaterastics
	..*	data10000.dat - 10000 countries and their flag charaterastics