#ifndef graph
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/property_map.hpp>
#include <vector>

typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property, EdgeWeightProperty > DirectedGraph;
typedef boost::graph_traits<DirectedGraph>::edge_iterator edge_iterator;
typedef boost::adjacency_list <boost::listS, boost::vecS, boost::directedS, boost::no_property,
	boost::property<boost::edge_weight_t, int> > graph_t;
typedef boost::graph_traits<graph_t>::vertex_descriptor vertex_descriptor;
typedef std::pair<int, int> Edge;

class Graph
{
private:
	std::vector<int> nodes;
public:
	DirectedGraph addEdges();
	void printList(DirectedGraph g);
	void findShortestPath(int node1,int node2,DirectedGraph g);
};
#endif