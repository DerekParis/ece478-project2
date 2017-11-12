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
    string prefix;
    int length;
} IPSpace;

class Node {
private:
public:
    Class type;
    vector<Link *> link;
    vector<Node *> customers;
    struct IPSpace space;
    int degreeP2P = 0;
    int degreeProvider = 0;
    int degreeCustomer = 0;
};

#endif /* node_hpp */
