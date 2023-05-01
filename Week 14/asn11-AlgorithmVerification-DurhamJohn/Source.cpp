
//* @file Source.cpp 
//* 
//* You are asked to complete Programming Projects 1, 2, & 3 on page 663 of your textbook. 
//* This program is meant to apply what you have learned in this topic.
//*
//* 1. Write a C++ class derived from GraphInterface, as given in Listing 20-1 on pages 634-635.  
//*    Use an adjacency matrix to represent the graph. 
//* 2. Repeat the previous programming problem, but represent the graph using an 
//*    adjacency list instead of an adjacency matrix. 
//* 3. Repeat Programming Problems 1 and 2, but allow the graph to be either 
//*    weighted or unweighted and either directed or undirected.
//* 
//* Carefully study and make sure you understand Figure 20-7 on page 635, Figure 20-8 on page 636, Figure 20-9 on page 636, 
//* and Figure 20-10 on page 637.
//*
//* 23.SP.CIS.2207.501 Data Structures & Algorithms
//* Assignment 10 - Graphs
//* @author John Durham
//* @date   04-10-2023
//*/

#include "Graph.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#include <windows.h>

#include <cassert> //FOR THIS WEEKS ASSIGNMENT


int menu();
void listFilesInCurrentWorkingDirectory();

template<class LabelType>
void printLabel(LabelType& label) {
	std::cout << label << std::endl;
}

int main()
{
	Graph<int> graph;


	graph.addVertex(); // 0
	graph.addVertex(); // 1
	graph.addVertex(); // 2
	graph.addVertex(); // 3
	graph.addVertex(); // 4
	graph.addVertex(); // 5

	graph.add(0, 4, 9);
	graph.add(0, 2, 7);
	graph.add(2, 3, 1);
	graph.add(2, 1, 5);
	graph.add(2, 5, 2);


	
	int choice = -2;
	std::string newString, filename;
	bool didWeAddaVertexOrEdge;
	int vertex1, vertex2, weight;


	do {
		system("CLS");
		choice = menu();
		assert(choice <= 0 || choice <= 10);  // 1. ASSERT

		switch (choice)
		{
		case 0: //print
			graph.print();
			std::cout << "Press ENTER to continue.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 1: //add
			didWeAddaVertexOrEdge = graph.addVertex();
			assert(didWeAddaVertexOrEdge);  // 2. ASSERT
			if (didWeAddaVertexOrEdge == true)
				std::cout << "Vertex Added" << std::endl;
			else
				std::cout << "Vertex Not Added" << std::endl;
			break;
		case 2: //remove
			std::cout << "Enter a Vertex to remove: ";
			std::cin >> vertex1;
			didWeAddaVertexOrEdge = graph.removeVertex(vertex1);
			assert(didWeAddaVertexOrEdge);// 3. ASSERT
			if (didWeAddaVertexOrEdge)
				std::cout << "Vertex Removed" << std::endl;
			else
				std::cout << "Vertex NOT Removed" << std::endl;
			break;
		case 3: //new Edge
			std::cout << "Enter Vertex 1: ";
			std::cin >> vertex1;
			std::cout << "Enter Vertex 2: ";
			std::cin >> vertex2;
			std::cout << "Enter Weight: ";
			std::cin >> weight;
			didWeAddaVertexOrEdge = graph.add(vertex1, vertex2, weight);
			assert(didWeAddaVertexOrEdge); // 4. ASSERT
			if (didWeAddaVertexOrEdge)
				std::cout << "Edge Added" << std::endl;
			else
				std::cout << "Edge NOT Added" << std::endl;
			break;
		case 4: //remove Edge
			std::cout << "Enter Vertex 1: ";
			std::cin >> vertex1;
			std::cout << "Enter Vertex 2: ";
			std::cin >> vertex2;
			didWeAddaVertexOrEdge = graph.remove(vertex1, vertex2);
			assert(didWeAddaVertexOrEdge); // 5. ASSERT
			if (didWeAddaVertexOrEdge)
				std::cout << "Edge Removed" << std::endl;
			else
				std::cout << "Edge NOT Removed" << std::endl;
			break;
		case 5:  //flip
			graph.flip();
			std::cout << "Graph has been flipped!" << std::endl;
		case 6: //open File
			std::cout << "Enter the starting vertex: ";
			std::cin >> vertex1;
			std::cout << "Enter the end vertex: ";
			std::cin >> vertex2;
			graph.depthFirstTraversal(vertex1, printLabel);
			//graph.shortestPath(vertex1, vertex2); 
			std::cout << "Press ENTER to continue.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 7: //save File
			std::cout << "Enter the starting vertex: ";
			std::cin >> vertex1;
			std::cout << "Enter the end vertex: ";
			std::cin >> vertex2;
			graph.breadthFirstTraversal(vertex1, printLabel);
			//graph.shortestPath(vertex1, vertex2); 
			std::cout << "Press ENTER to continue.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 8: //open file
			listFilesInCurrentWorkingDirectory();
			std::cout << "Enter a filename to load from: ";
			std::cin >> filename;
			graph.read(filename);
			std::cout << "File opened.\n";
			std::cout << "Press ENTER to continue.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 9:
			std::cout << "Enter a filename to save to: ";
			std::cin >> filename;
			graph.write(filename);
			break;
		case -1:
			std::cout << "An error occurred." << std::endl;
		}
	} while (choice != 10);


	return 0;
}



//================================================================
int menu()
{
	int choice = -1;

	std::cout << "=========================================================================" << std::endl;
	std::cout << "|\t0. Print                      5. Flip Undirected / Directed Graph    |" << std::endl;
	std::cout << "|\t1. New Vertex                 6. Depth First Traverse                |" << std::endl;
	std::cout << "|\t2. Remove Vertex              7. Breadth First Traverse              |" << std::endl;
	std::cout << "|\t3. New Edge                   8. Open File                           |" << std::endl;
	std::cout << "|\t4. Remove Edge                9. Save File                           |" << std::endl;
	std::cout << "|                      10. Quit                                         |" << std::endl;
	std::cout << "=========================================================================" << std::endl;
	std::cout << "Enter Choice: ";
	std::cin >> choice;

	if (choice < 0 || choice > 10)
	{
		std::cout << "Error, That is an invalid selection!\n";
		std::cout << "Enter Choice: ";
		std::cin >> choice;
	}

	return choice;
}


//courtesy of Microsoft.com
void listFilesInCurrentWorkingDirectory()
{
	WIN32_FIND_DATAW findData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	LPCSTR lpFileName = "*";
	int nLen = MultiByteToWideChar(CP_ACP, 0, lpFileName, -1, NULL, 0);
	LPWSTR lpwFileName = new WCHAR[nLen];
	MultiByteToWideChar(CP_ACP, 0, lpFileName, -1, lpwFileName, nLen);

	hFind = FindFirstFileW(lpwFileName, &findData);
	if (hFind == INVALID_HANDLE_VALUE) {
		std::cout << "Error opening directory." << std::endl;
		return;
	}

	do {
		std::wcout << findData.cFileName << std::endl;
	} while (FindNextFileW(hFind, &findData) != 0);

	FindClose(hFind);

	delete[] lpwFileName;
}

