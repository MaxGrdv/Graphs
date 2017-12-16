

#include "stdafx.h"
#include "graph.h"


int main()
{	
	DirectedGraph g;
	boost::add_edge(0, 1, 8, g);
	boost::add_edge(0, 3, 18, g);
	boost::add_edge(1, 2, 20, g);
	boost::add_edge(2, 3, 2, g);
	boost::add_edge(3, 1, 1, g);
	boost::add_edge(1, 3, 7, g);
	boost::add_edge(1, 4, 1, g);
	boost::add_edge(4, 5, 6, g);
	boost::add_edge(2, 5, 7, g);
	Graph graph = Graph(g);
	graph.printList(g);
	std::cout << std::endl;
	
	//writing to file
	graph.writeToFile("edges.txt");
	graph.readFromFile("edges.txt");
	graph.print();
	system("pause");
	return 0;
}

