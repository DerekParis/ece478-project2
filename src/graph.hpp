//
//  graph.hpp
//  parse
//
//  Created by Andrew Camps on 11/10/17.
//

#ifndef graph_hpp
#define graph_hpp

#include "node.hpp"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cmath>

typedef struct Clique {
    vector<Node *> nodes;
    int size;
    Clique(vector<Node *> c, int s) {
        nodes = c; size = s;
    }
} Clique;

class Graph {
private:
    string classFile = "input/classification-input.txt";
    string relationFile = "input/relationship-input.txt";
    string routeFile = "input/routeviews-input.txt";
    string organizationsFile = "input/organizations-input.txt";
    map<int, Node *> node;
    vector<Clique> allCliques;
    vector<Node *> rankList;
    long TotIPSpace = pow(2, 32);
    
    void getASClass();
    void getASRelation();
    void getIPSpace();
    void getTier1AS();
    void getOrganizationNames();
    void getASRank();
    void getParentSpace();
    void getASRankHelper(Node *node, map<int, Node *> &visited);
    vector<string> split(string s, string delimiter);
    
public:
    void printGraphData1();
    void printGraphData2();
    void printGraphData3();
    void printGraphData4();
    void printTableData1();
    void printTableData2();
    void printTableData3();
};

#endif /* graph_hpp */
