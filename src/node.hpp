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

enum Class {
    NONE,
    TRANSIT_ACCESS,
    CONTENT,
    ENTERPRISE
};

class Node {
private:
public:
    Class type;
    vector<Link *> link;
    int degreeP2P = 0;
    int degreeProvider = 0;
    int degreeCustomer = 0;
};

#endif /* node_hpp */
