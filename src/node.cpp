//
//  node.cpp
//  parse
//
//  Created on 11/10/17.
//

#include "node.hpp"

int Node::getDegree(){
    return this->degreeP2P + this->degreeCustomer + this->degreeProvider;
}

bool compByDeg(Node *n1, Node *n2) {
    return n1->getDegree() > n2->getDegree();
}

bool compByASes(Node *n1, Node *n2) {
    return n1->nodeRank.ASes > n2->nodeRank.ASes;
}

bool compByPer(Node *n1, Node *n2) {
    return n1->nodeRank.uniqueIP > n2->nodeRank.uniqueIP;
}
