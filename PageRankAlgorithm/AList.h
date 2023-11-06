#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <iomanip>


using namespace std;

struct Node {

	int outDeg;
	int iterations;
	double rank;
	string name;

	Node() {}
	Node(string name) {
		this->name = name;
		this->outDeg = 0;
		this->iterations = 0;
		this->rank = 0.0;
	}
	
};

class AdjacencyList {
private:
	//Think about what member variables you need to initialize
	int vertices; //Number of nodes
	int pageIterations;
	//int outDegrees;
	double finalRank;
	map<string, vector<pair<string, double>>> aList;
	//map<string, pair<Node, vector<Node>>> newList;
	map<string, double> totalRank;
	vector<Node> v;
	

public:

	AdjacencyList() {
		this->vertices = 0;
		this->pageIterations = 0;
		this->finalRank = 0.0;
		//this->outDegrees = 0;
	}
	void setIterations(int p);
	void AddNode(string from, string to, int& w);
	void PageRank(int n);
	void numVertex(int v);
	void printGraph();
	void setOutDeg(vector<Node>& node);

};

void AdjacencyList::setIterations(int p)
{
	this->pageIterations = p;
}

void AdjacencyList::AddNode(string from, string to, int& w)
{
	map<string, vector<pair<string, double>>>::iterator it;
	map<string, vector<pair<string, double>>>::iterator it2;
	Node from1 = Node(from);
	Node to1 = Node(to);
	it = aList.find(from);
	it2 = aList.find(to);

	if (it == aList.end()) { 
		//obj = Node(from);
		//w++;
		aList[from].push_back(make_pair(to, 1.0));
		this->vertices++;
		v.push_back(from1);
		w = 1;

	}
	if (it2 == aList.end()) {
		this->vertices++;
		v.push_back(to1);
		w = 1;
		aList[to];
	}
	if (it != aList.end()){//Already exists
		w++;
		aList[from].push_back(make_pair(to, 1.0));
	}
	
}

void AdjacencyList::PageRank(int n)
{
	setIterations(n);
	setOutDeg(v);
	
		for (auto name : aList) {
			string temp = name.first;
			totalRank[temp] = (1.0 / (double)vertices);
			//tempRank[temp] = 1.0 / (double)vertices;
			
		}

		for (int powerIts = 0; powerIts < n - 1; powerIts++) {

			map<string, double> tempRank;
			
			int i = 0;

			for (auto name : aList) {

				string temp = name.first;
				auto d = name.second;

				if (aList[temp].size() == 1) {

					tempRank[d[i].first] = totalRank[temp] / aList[temp].size();
					//cout << d[i].first << " " << tempRank[d[i].first] << endl;
				}
				else if (aList[temp].size() > 1) {
					double num = 0.0;
					for (int j = 0; j < aList[temp].size(); j++) {
						//cout << d[j].first << " " << temp << " " << endl;
						num = totalRank[temp] / aList[temp].size();
						tempRank[d[j].first] += totalRank[temp] / aList[temp].size();
					}
				}


			}
			
			totalRank = tempRank;
		}

	


}
void AdjacencyList::numVertex(int v)
{
	
}


void AdjacencyList::setOutDeg(vector<Node>& node)
{


	int i = 0;
	for (auto& x : aList) {


		node[i].outDeg = aList[(node[i].name)].size();
		node[i].rank = 1.0/(double)vertices;
		i++;

	}
}

void AdjacencyList::printGraph() {
	//int x = 1;


	for (auto x : totalRank) {
		cout << x.first << " " << fixed << setprecision(2) << x.second << endl;
	}

}



