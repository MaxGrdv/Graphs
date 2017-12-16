#ifndef graph
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/property_map.hpp>
#include <vector>
#include <boost/graph/graphviz.hpp>

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
	std::vector<int[2]> nodes;
	std::vector<int> weigths;
	DirectedGraph g;
public:
	DirectedGraph addEdges();
	void printList(DirectedGraph g);
	void findShortestPath(int node1,int node2);
	void vizualization(DirectedGraph g);
	Graph(DirectedGraph graph);
	~Graph();
	void readFromFile(std::string path);
	void writeToFile(std::string path);
	DirectedGraph getGraph();
	void print();
#endif