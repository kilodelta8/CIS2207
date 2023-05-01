#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include "GraphInterface.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <Windows.h>


template<class LabelType>
class Graph : public GraphInterface<LabelType>
{
private:
	int maxSize;	
	int size;		
	int edges;			
	int** graph;		
	bool isDirected;	
	LabelType vertList[100];

	void printWeight(int*);
	void newMaxSize(int);
	void shortestPath(int, int, bool*, int*);

public:
	Graph();
	~Graph();

	void print();
	bool addVertex();
	bool removeVertex();
	bool removeVertex(int);
	bool removeEdge(int, int);
	void flip() { isDirected = !isDirected; }

	int getNumVertices() const override;
	int getNumEdges() const override;
	bool add(LabelType start, LabelType end, int edgeWeight) override;
	bool remove(LabelType start, LabelType end) override;
	int getEdgeWeight(LabelType start, LabelType end) const override;
	void depthFirstTraversal(LabelType start, void visit(LabelType&)) override;
	void breadthFirstTraversal(LabelType start, void visit(LabelType&)) override;

	void clear();
	void shortestPath(int start, int end);
	bool read(std::string filename);
	bool write(std::string filename);


};

#endif // GRAPH_H

template<class LabelType>
Graph<LabelType>::Graph()
{
	size = 0;
	maxSize = 3;
	isDirected = false;

	graph = new int* [maxSize];

	for (int index = 0; index < maxSize; index++)
	{
		graph[index] = new int[maxSize];

		for (int jndex = 0; jndex < maxSize; jndex++)
			graph[index][jndex] = 0;
	}
}

template<class LabelType>
Graph<LabelType>::~Graph()
{
	for (int index = 0; index < maxSize; index++)
		delete[] graph[index];

	delete[] graph;
}

template<class LabelType>
void Graph<LabelType>::print()
{
	int width = 0;

	for (int index = 0; index < size; index++)
		for (int jndex = 0; jndex < size; jndex++)
			if (log10(graph[index][jndex]) > width)
				width = log10(graph[index][jndex]);
	width++;
	std::cout << "\n\nSize: " << size << std::endl;
	std::cout << "Edges: " << edges << std::endl;
	std::cout << "Width: " << width << std::endl;
	if (isDirected)
		std::cout << "Directed: true" << std::endl;
	else
		std::cout << "Directed: false" << std::endl;
	std::cout << std::setw(log10(size) + 1) << " " << "  ";
	for (int jndex = 0; jndex < size; jndex++)
		std::cout << std::setw(width + 1) << jndex << "  ";
	std::cout << std::endl;
	for (int index = 0; index < size; index++)
	{
		std::cout << std::setw(log10(size) + 1) << index << " | ";
		for (int jndex = 0; jndex < size; jndex++)
			std::cout << std::setw(width) << graph[index][jndex] << " | ";
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
}

template<class LabelType>
void Graph<LabelType>::newMaxSize(int newMaxSize)
{
	if (maxSize >= newMaxSize)
	{
		std::cout << "Already too big..." << std::endl;
		return;
	}
	int** newMatrix = new int* [newMaxSize];
	for (int index = 0; index < newMaxSize; index++)
	{
		newMatrix[index] = new int[newMaxSize];
		for (int jndex = 0; jndex < newMaxSize; jndex++)
			newMatrix[index][jndex] = 0;
	}
	for (int index = 0; index < size; index++)
		for (int jndex = 0; jndex < size; jndex++)
			newMatrix[index][jndex] = graph[index][jndex];
	for (int index = 0; index < size; index++)
		delete[] graph[index];
	delete[] graph;
	graph = newMatrix;
	maxSize = newMaxSize;
}

template<class LabelType>
bool Graph<LabelType>::addVertex()
{
	if (size == maxSize)
	{
		newMaxSize(size * 2);
	}
	size++;

	return true;
}

template<class LabelType>
bool Graph<LabelType>::add(LabelType start, LabelType end, int weight)
{
	if (start == end)
	{
		std::cout << "Start cannot equal end" << std::endl;
		return false;
	}

	if (start < 0 || start >= size)
	{
		std::cout << "1st vertex is out of bounds" << std::endl;
		return false;
	}

	if (end < 0 || end >= size)
	{
		std::cout << "Vertex 2 is out of bounds" << std::endl;
		return false;
	}

	if (weight <= 0)
	{
		std::cout << "Edge Weight is out of bounds" << std::endl;
		return false;
	}

	if (isDirected)
	{
		graph[start][end] = weight;
		edges++;
	}
	else
	{
		graph[start][end] = weight;
		graph[end][start] = weight;
		edges++;
	}

	return true;
}

template<class LabelType>
bool Graph<LabelType>::removeEdge(int start, int end)
{
	if (graph[start][end] == 0)
	{
		std::cout << "Already empty" << std::endl;
		return false;
	}

	if (isDirected)
	{
		graph[start][end] = 0;
		edges--;
	}
	else
	{
		graph[start][end] = 0;
		graph[end][start] = 0;
		edges--;
	}

	return true;
}

template<class LabelType>
bool Graph<LabelType>::removeVertex()
{
	if (size == 0)
	{
		std::cout << "You have an empty graph alread" << std::endl;
		return false;
	}

	for (int index = 0; index < size; index++)
		if (graph[size - 1][index] > 0 || graph[index][size - 1] > 0)
		{
			removeEdge(index, size - 1);
		}

	size--;

	return true;
}

template<class LabelType>
bool Graph<LabelType>::removeVertex(int vertex)
{
	if (size == 0)
	{
		std::cout << "Graph already empty!" << std::endl;
		return false;
	}
	if (vertex < 0 || vertex >= size)
	{
		std::cout << "Vertex out of bounds" << std::endl;
		return false;
	}

	if (vertex == size - 1)
		return removeVertex();

	for (int index = vertex; index < size - 1; index++)
		for (int jndex = 0; jndex < size; jndex++)
		{
			if (index != jndex)
			{
				graph[index][jndex] = graph[index + 1][jndex];
				graph[jndex][index] = graph[jndex][index + 1];
			}
		}


	return removeVertex();
}

template<class LabelType>
void Graph<LabelType>::clear()
{
	for (int index = 0; index < size; index++)
		for (int jndex = 0; jndex < size; jndex++)
			graph[index][jndex] = 0;

	size = 0;
	edges = 0;
}

template<class LabelType>
void Graph<LabelType>::printWeight(int* weight)
{
	for (int index = 0; index < size; index++)
		std::cout << weight[index] << " ";
	std::cout << std::endl;
}

template<class LabelType>
void Graph<LabelType>::shortestPath(int start, int index, bool* visited, int* weight)
{
	for (int i = 0; i < size; i++)
	{
		if (!visited[i] && graph[index][i] != 0)
		{
			visited[i] = true;
			weight[i] = graph[index][i];
		}
	}
	printWeight(weight);
}

template<class LabelType>
void Graph<LabelType>::shortestPath(int start, int end)
{
	int* newWeight = new int[size];
	bool* visited = new bool[size];


	for (int i = 0; i < size; i++)
	{
		if (i == start)
			newWeight[i] = 0;
		else
			newWeight[i] = 1000000;

		visited[i] = false;
	}

	for (int j = 0; j < size; j++)
	{
		if (!visited[j] && graph[start][j] != 0)
			shortestPath(start, j, visited, newWeight);
	}

	printWeight(newWeight);

	std::cout << "This graph's weight is: " << newWeight[start] << "\n";

}

template<class LabelType>
bool Graph<LabelType>::read(std::string filename)
{
	int numVertices = 0;
	char directed = false;

	if (filename.length() > 0)
	{
		filename = ((filename.find(".grp") != std::string::npos) ? filename : (filename + ".grp"));

		std::ifstream myfile(filename);

		if (myfile.is_open())
		{
			myfile >> numVertices;
			myfile >> directed;

			clear();

			if (directed == 'd' || directed == 'D')
			{
				flip();
			}

			for (int i = 0; i < numVertices; i++)
			{
				addVertex();
			}


			for (int i = 0; i < numVertices; i++)
			{
				int v1;
				int v2;
				int wt;

				myfile >> v1;
				myfile >> v2;
				myfile >> wt;

				add(v1, v2, wt);
			}

			myfile.close();
		}
		else
		{
			std::cout << "Unable to open file.";
		}

		return true;
	}
	else
	{
		std::cout << "Filename cannot be empty." << std::endl;
		return false;
	}
}

template<class LabelType>
bool Graph<LabelType>::write(std::string filename)
{

	if (filename.length() > 0)
	{
		filename = (filename.find(".grp") != std::string::npos) ? filename : (filename + ".grp");

		std::ofstream myfile(filename);

		if (myfile.is_open())
		{

			std::cout << size << std::endl;
			myfile << size << std::endl;

			if (!isDirected)
			{
				std::cout << "U" << std::endl;
				myfile << "U" << std::endl;
			}
			else
			{
				std::cout << "D" << std::endl;
				myfile << "D" << std::endl;
			}

			Graph tempGraph;
			tempGraph.flip(); 
			for (int i = 0; i < size; i++)
				tempGraph.addVertex();

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (graph[i][j] > 0 && i <= tempGraph.size && j <= tempGraph.size)
					{
						if (tempGraph.getEdgeWeight(i, j) == 0 && tempGraph.getEdgeWeight(j, i) == 0)
						{
							tempGraph.add(i, j, graph[i][j]);
						}
					}
				}
			}

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (tempGraph.graph[i][j] > 0)
					{
						std::cout << i << " " << j << " " << tempGraph.graph[i][j] << std::endl;
						myfile << i << " " << j << " " << tempGraph.graph[i][j] << std::endl;
					}
				}
			}


			myfile.close();
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
			return false;
		}

		return true;
	}
	else
	{
		std::cout << "Filename can't be empty" << std::endl;
		return false;
	}
}


template<class LabelType>
int Graph<LabelType>::getEdgeWeight(LabelType start, LabelType end) const //TODO - needs work in the body
{

	if (start == end)
	{
		std::cout << "Start caonnt equal end" << std::endl;
		return -1;
	}

	if (start < 0 || start >= size)
	{
		std::cout << "Vertex 1 is out of bounds" << std::endl;
		return -1;
	}

	if (end < 0 || end >= size)
	{
		std::cout << "Vertex 2 is out of bounds" << std::endl;
		return -1;
	}

	if (graph[start][end] <= 0)
	{
		std::cout << "Edge Weight is out of bounds" << std::endl;
		return 0;
	}


	return graph[start][end];
}

//=====================================================
template<class LabelType>
int Graph<LabelType>::getNumVertices() const
{
	return size;
}

template<class LabelType>
int Graph<LabelType>::getNumEdges() const
{
	return edges;
}

template<class LabelType>
bool Graph<LabelType>::remove(LabelType start, LabelType end)
{
	if (graph[start][end] == 0)
	{
		std::cout << "Already empty" << std::endl;
		return false;
	}

	if (isDirected)
	{
		graph[start][end] = 0;
		edges--;
	}
	else
	{
		graph[start][end] = 0;
		graph[end][start] = 0;
		edges--;
	}

	return true;
}

template<class LabelType>
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&))
{
	bool* visited = new bool[size];

	for (int i = 0; i < size; i++)
		visited[i] = false;

	std::stack<int> tempStack;

	int startIndex = -1;

	for (int i = 0; i < size; i++)
	{
		if (vertList[i] == start)
		{
			startIndex = i;
			break;
		}
	}

	if (startIndex != -1)
	{
		tempStack.push(startIndex);

		while (!tempStack.empty())
		{
			int current = tempStack.top();
			tempStack.pop();

			if (!visited[current])
			{
				visited[current] = true;
				LabelType& label = vertList[current];
				visit(label);

				for (int i = 0; i < size; i++)
				{
					if (graph[current][i] != 0 && !visited[i])
					{
						tempStack.push(i);
					}
				}
			}
		}
	}

	delete[] visited;
}

template<class LabelType>
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&))
{
	// Find the starting vertex index
	int startIndex = -1;
	for (int i = 0; i < size; i++)
	{
		if (vertList[i] == start)
		{
			startIndex = i;
			break;
		}
	}

	
	if (startIndex == -1)
		return;

	bool* visited = new bool[size];
	for (int i = 0; i < size; i++)
		visited[i] = false;

	std::queue<int> vertQueue;

	visited[startIndex] = true;
	vertQueue.push(startIndex);

	while (!vertQueue.empty())
	{
		int vertIndex = vertQueue.front();
		vertQueue.pop();

		LabelType vertLabel = vertList[vertIndex];
		visit(vertLabel);

		std::cout << "Visited vertex " << vertLabel << std::endl;

		for (int j = 0; j < size; j++)
		{
			if (graph[vertIndex][j] != 0 && !visited[j])
			{
				visited[j] = true;
				vertQueue.push(j);
			}
		}
	}

	// Free memory used by the visited array
	delete[] visited;
}