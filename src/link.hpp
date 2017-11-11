//
//  link.hpp
//  parse
//
//  Created by Andrew Camps on 11/11/17.
//

#ifndef link_hpp
#define link_hpp

#include <stdio.h>

using namespace std;

class Node;

typedef struct P2P {
    Node *peer1;
    Node *peer2;
} P2P;

typedef struct P2C {
    Node *provider;
    Node *customer;
} P2C;

enum Type {
    P2P_TYPE,
    P2C_TYPE
};

class Link {
private:
public:
    Type type;
    struct P2C p2c;
    struct P2P p2p;
};

#endif /* link_hpp */
