#include "stdafx.h"
#include"graph.h"
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>

DirectedGraph Graph::addEdges()
{
	DirectedGraph g;
	int count = 0;
	std::cout << "Please,enter count of edges:" << std::endl;
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		boost::add_edge(rand() % (i + 5), rand() % count, rand() % count, g);
		weigths.push_back(rand() % count);
	}
	return g;
}
void Graph::printList(DirectedGraph g)
{
	std::pair<edge_iterator, edge_iterator> ei = edges(g);
	std::cout << "Count of edges = " << num_edges(g) << "\n";
	std::cout << "Edge list:\n";
	std::copy(ei.first, ei.second,
		std::ostream_iterator<boost::adjacency_list<>::edge_descriptor>{
		std::cout, "\n"});
}
void Graph::findShortestPath(int node1,int node2,DirectedGraph g)
{
	
	// Create vectors to store the predecessors (p) and the distances from the root (d)
	std::vector<vertex_descriptor> p(num_vertices(g));
	std::vector<int> d(num_vertices(g));
	// Create descriptor for the source node
	vertex_descriptor s = vertex(node1, g);
	vertex_descriptor goal = vertex(node2, g);
	// Evaluate Dijkstra on graph g with source s, predecessor_map p and distance_map d
	boost::dijkstra_shortest_paths(g, s,
		boost::predecessor_map(&p[0]).distance_map(&d[0]));

	
	std::vector<boost::graph_traits<graph_t>::vertex_descriptor > path;
	boost::graph_traits<graph_t>::vertex_descriptor current = goal;

	while (current != s)
	{
		path.push_back(current);
		current = p[current];
	}
	path.push_back(s);

	// Prints the path obtained in reverse
	std::cout << "Path:";
	std::vector<boost::graph_traits<graph_t>::vertex_descriptor >::reverse_iterator it;
	for (it = path.rbegin(); it != path.rend(); ++it) {
		std::cout << weigths[*it] << " ";
	}
	std::cout << std::endl;
}
Graph::Graph(DirectedGraph graph)
{
	g = graph;
}

Graph::~Graph()
{
}

DirectedGraph Graph::getGraph() {
	return g;
}


void Graph::print() {
	std::pair<edge_iterator, edge_iterator> ei = edges(g);

	std::cout << "Number of edges = " << num_edges(g) << "\n";
	std::cout << "Edge list:\n";

	boost::property_map<DirectedGraph, boost::edge_weight_t>::type EdgeWeightMap = get(boost::edge_weight_t(), g);

	std::pair<edge_iterator, edge_iterator> edgePair;
	for (edgePair = edges(g); edgePair.first != edgePair.second; ++edgePair.first)
	{
		std::cout << *edgePair.first << " " << EdgeWeightMap[*edgePair.first] << std::endl;
	}

	std::cout << std::endl;
}

void Graph::readFromFile(std::string path) {
	g.clear();
	std::ifstream fin(path);
	std::string buff;
	if (!fin.is_open()) // если файл не открыт
		std::cout << "Файл не может быть открыт!\n";
	else
	{
		std::vector<std::string> superResults;
		std::vector<std::string> results;
		while (getline(fin, buff)) {
			boost::split(superResults, buff, [](char c) {return c == ' '; });
			boost::split(results, superResults[0], [](char c) {return c == ','; });
			results[0].erase(0, 1);
			results[1].erase(results[1].length() - 1, 1);
			//Заносим дугу в наш граф
			boost::add_edge(atoi(results[0].c_str()), atoi(results[1].c_str()), atoi(superResults[1].c_str()), g);
		}
	}
}

void Graph::writeToFile(std::string path) {
	std::ofstream fout(path);
	boost::property_map<DirectedGraph, boost::edge_weight_t>::type EdgeWeightMap = get(boost::edge_weight_t(), g);
	std::pair<edge_iterator, edge_iterator> edgePair;
	for (edgePair = edges(g); edgePair.first != edgePair.second; ++edgePair.first)
	{
		fout << *edgePair.first << " " << EdgeWeightMap[*edgePair.first] << std::endl;
	}
	fout.close();
}