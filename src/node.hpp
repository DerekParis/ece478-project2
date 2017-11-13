//
//  node.hpp
//  parse
//
//  Created by Andrew Camps on 11/10/17.
//

#ifndef node_hpp
#define node_hpp

#include "link.hpp"

#include <stdio.h>
#include <vector>
#include <string>

enum Class {
    NONE,
    TRANSIT_ACCESS,
    CONTENT,
    ENTERPRISE
};

typedef struct IPSpace {
    Node *parent;
    string prefix;
    int length;
    int space;
} IPSpace;

typedef struct Rank {
    int ASes;
    int advertisedIP;
    int uniqueIP;
} Rank;

class Node {
private:
public:
    Class type;
    vector<Link *> link;
    vector<Node *> customers;
    vector<IPSpace> space;
    struct Rank nodeRank;
    long totalIPSpace = 0;
    string name;
    int ASnum;
    int degreeP2P = 0;
    int degreeProvider = 0;
    int degreeCustomer = 0;
    
    int getDegree();
    
};

bool compByDeg(Node *n1, Node *n2);
bool compByASes(Node *n1, Node *n2);
bool compByPer(Node *n1, Node *n2);

#endif /* node_hpp */
