// Proect.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "graph.h"


int main()
{	
	Graph graph;
	DirectedGraph g = graph.addEdges();
	graph.printList(g);
	std::cout << std::endl;
	graph.findShortestPath(1,4,g);
	system("pause");
	return 0;
}

