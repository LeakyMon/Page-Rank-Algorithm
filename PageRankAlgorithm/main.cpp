#include <fstream>
#include <sstream>

#include "AList.h"

using namespace std;

/*
vector<string> readTextFile(ifstream& file) {

	 // Open the file
	std::string line;
	vector<string> s;
	if (file.is_open()) {
		while (getline(file, line)) { // Read each line
			s.push_back(line); // Output to console
		}
		//getline(file, line); // Read each line
		return s; // Output to console
		//file.close(); // Close the file
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
	return s;
}
*/


int main()
{

	int no_of_lines, power_iterations;

	string from, to;

	cin >> no_of_lines;
	cin >> power_iterations;
	AdjacencyList graph;
	Node node;
	graph.setIterations(power_iterations);
	
	int nodes = 0;

    for (int i = 0; i < no_of_lines; i++)
	{

		cin >> from;
		cin >> to;

		graph.AddNode(from, to, nodes);

	}

	
	graph.PageRank(power_iterations);
	
	graph.printGraph();

}