//
//  graph.cpp
//  parse
//
//  Created on 11/10/17.
//

#include "graph.hpp"

void Graph::printGraphData1(){
    int total;
    int numTransit = 0;
    int numContent = 0;
    int numEnterprise = 0;
    
    getASClass();
    total = node.size();
    
    /* Count number of each type */
    for (map<int, Node *>::iterator it = node.begin(); it != node.end(); ++it){
        switch(it->second->type){
            case TRANSIT_ACCESS:
                numTransit++;
                break;
            case CONTENT:
                numContent++;
                break;
            case ENTERPRISE:
                numEnterprise++;
                break;
            case NONE:
                /* Do nothing */
                break;
        }
    }
    
    cout << "----------> GRAPH DATA 1 <----------" << endl;
    cout << "\tType Totals:" << endl << endl;
    cout << "\tTransit/Access\t" << numTransit << endl;
    cout << "\tEnterprise\t" << numEnterprise << endl;
    cout << "\tContent\t\t" << numContent << endl;
    cout << "\tTotal by Sum\t" << numTransit + numContent + numEnterprise << endl;
    cout << "\tTotal Int Variable\t" << total << endl << endl;
    
    cout << "\tType Percentages:" << endl << endl;
    cout << "\tTransit/Access\t" << (double)numTransit / (double)total << endl;
    cout << "\tEnterprise\t" << (double)numEnterprise / (double)total << endl;
    cout << "\tContent\t\t" << (double)numContent / (double)total << endl;
    cout << "\tTotal by Sum\t" << ((double)numTransit / (double)total) + ((double)numEnterprise / (double)total) + ((double)numContent / (double)total) << endl << endl << endl;
}

void Graph::printGraphData2(){
    int total;
    int bin[6] = {0};
    int null = 0;
    
    getASRelation();
    total = node.size();
    
    /* Count number of each type */
    for (map<int, Node *>::iterator it = node.begin(); it != node.end(); ++it){
        
        /* Change the degree value if we need to change degree definition */
        //int deg = it->second->degreeP2P + it->second->degreeCustomer + it->second->degreeProvider;
        int deg = it->second->degreeP2P + it->second->degreeCustomer; //<<<<< I think its this definition 
        //int deg = it->second->degreeP2P + it->second->degreeProvider;

        if(deg == 1){
            bin[0]++;
        }else if(deg > 1 && deg <= 5){
            bin[1]++;
        }else if(deg > 5 && deg <= 100){
            bin[2]++;
        }else if(deg > 100 && deg <= 200){
            bin[3]++;
        }else if(deg > 200 && deg <= 1000){
            bin[4]++;
        }else if(deg > 1000){
            bin[5]++;
        }else{
            null++;
            /* no links */
        }
    }
    
    cout << "----------> GRAPH DATA 2 <----------" << endl;
    cout << "\tAS Node Degree Distribution:" << endl << endl;
    cout << "\tBINS" << endl;
    cout << "\t1\t\t" << bin[0] << endl;
    cout << "\t2-5\t\t" << bin[1] << endl;
    cout << "\t5-100\t\t" << bin[2] << endl;
    cout << "\t100-200\t\t" << bin[3] << endl;
    cout << "\t200-1000\t" << bin[4] << endl;
    cout << "\t1000+\t\t" << bin[5] << endl << endl;
    cout << "\t\ttotal AS nodes by variable: " << total << endl;
    cout << "\t\ttotal AS nodes by sum: \t" << bin[0] + bin[1] + bin[2] + bin[3]
    + bin[4] + bin[5] + null << endl << endl;
    
}

void Graph::printGraphData3(){
    getIPSpace();
    
    //TODO: print proper bins
    cout << "----------> GRAPH DATA 3 <----------" << endl;
}

void Graph::printGraphData4(){
    int total;
    int nonCat = 0;
    int numTransit = 0;
    int numContent = 0;
    int numEnterprise = 0;
    
    /* Count number of each type */
    for (map<int, Node *>::iterator it = node.begin(); it != node.end(); ++it){
        int deg;
        switch(it->second->type){
            case TRANSIT_ACCESS:
                if(it->second->customers.size() > 0){
                    numTransit++;
                }
                
                nonCat++;
                break;
            case CONTENT:
                if(!it->second->customers.size() && it->second->degreeP2P > 0){
                    numContent++;
                }
                
                nonCat++;
                break;
            case ENTERPRISE:
                deg = it->second->degreeP2P + it->second->degreeCustomer;
                if(deg <= 2 && !it->second->customers.size() && !it->second->degreeP2P){
                    numEnterprise++;
                }
                
                nonCat++;
                break;
            case NONE:
                /* Do nothing */
                break;
        }
    }
    
    total = numTransit + numContent + numEnterprise;
    
    cout << "----------> GRAPH DATA 4 <----------" << endl;
    cout << "\tType Totals:" << endl << endl;
    cout << "\tTransit/Access\t" << numTransit << endl;
    cout << "\tEnterprise\t" << numEnterprise << endl;
    cout << "\tContent\t\t" << numContent << endl;
    cout << "\tTotal\t" << total << endl;
    cout << "\tNo Catagory\t" << nonCat << endl << endl;
    
    cout << "\tType Percentages:" << endl << endl;
    cout << "\tTransit/Access\t" << (double)numTransit / (double)total << endl;
    cout << "\tEnterprise\t" << (double)numEnterprise / (double)total << endl;
    cout << "\tContent\t\t" << (double)numContent / (double)total << endl;
    cout << "\tTotal by Sum\t" << ((double)numTransit / (double)total) + ((double)numEnterprise / (double)total) + ((double)numContent / (double)total) << endl << endl << endl;
    
}

void Graph::printTableData1(){
    
    cout << "----------> TABLE DATA 1 <----------" << endl;
}

void Graph::printTableData2(){
    
    cout << "----------> TABLE DATA 2 <----------" << endl;
}

void Graph::printTableData3(){
    
    cout << "----------> TABLE DATA 3 <----------" << endl;
}

void Graph::getASClass(){
    fstream in;
    
    in.open(classFile.c_str());
    
    /* if file is available, open and read */
    if (!in.is_open()) {
        cout << "No input file found with the name: " << classFile << endl;
        return;
    }
    
    while(!in.eof()){
        string line;
        vector<string> splitLine;
        getline(in, line);
        
        splitLine = split(line, "|");
        
        Node *newNode = new Node();
        switch (line.back()) {
            case 's':
                newNode->type = TRANSIT_ACCESS;
                node[stoi(splitLine.front())] = newNode;
                break;
            case 'e':
                newNode->type = ENTERPRISE;
                node[stoi(splitLine.front())] = newNode;
                break;
            case 't':
                newNode->type = CONTENT;
                node[stoi(splitLine.front())] = newNode;
                break;
        }
        
    }
    
}

void Graph::getASRelation(){
    fstream in;
    
    in.open(relationFile.c_str());
    
    /* if file is available, open and read */
    if (!in.is_open()) {
        cout << "No input file found with the name: " << classFile << endl;
        return;
    }
    
    while(!in.eof()){
        string line;
        vector<string> splitLine;
        getline(in, line);
        
        /* Parse line */
        splitLine = split(line, "|");
        if(splitLine.size() < 3){
            continue;
        }
        
        int as1 = stoi(splitLine.front());
        splitLine.erase(splitLine.begin());
        int as2 = stoi(splitLine.front());
        splitLine.erase(splitLine.begin());
        
        /* Create new link */
        Link *newLink = new Link();
        switch(stoi(splitLine.front())){
            case -1:
                newLink->type = P2C_TYPE;
                break;
            case 0:
                newLink->type = P2P_TYPE;
                break;
        }
        
        /* Create new node if not in map */
        Node *node1 = node[as1];
        Node *node2 = node[as2];
        if(node1 == NULL){
            Node *newNode = new Node();
            node[as1] = newNode;
            node1 = node[as1];
        }
        if(node2 == NULL){
            Node *newNode = new Node();
            node[as2] = newNode;
            node2 = node[as2];
        }

        /* Add new link to node */
        node1->link.push_back(newLink);
        node2->link.push_back(newLink);
        
        /* Add node link connections */
        switch(newLink->type){
            case P2P_TYPE:
                newLink->p2p.peer1 = node1;
                newLink->p2p.peer2 = node2;
                node1->degreeP2P++;
                node2->degreeP2P++;
                break;
            case P2C_TYPE:
                newLink->p2c.provider = node1;
                node1->customers.push_back(node2);
                newLink->p2c.customer = node2;
                node1->degreeProvider++;
                node2->degreeCustomer++;
                break;
        }
    }
}

void Graph::getIPSpace(){
    fstream in;
    
    in.open(routeFile.c_str());
    
    /* if file is available, open and read */
    if (!in.is_open()) {
        cout << "No input file found with the name: " << classFile << endl;
        return;
    }
    
    while(!in.eof()){
        string line;
        vector<string> splitLine;
        getline(in, line);
        
        splitLine = split(line, "\t");
        if(splitLine.size() < 3){
            continue;
        }
        
        vector<string> nodeSet = split(splitLine.at(2), "_");
        for(auto &i : nodeSet){
            vector<string> nodes = split(i, ",");
            for(auto &i : nodes){
                int as;
                Node *node1;
                try {
                    as = stoi(i);
                    node1 = node[as];
                }
                catch(out_of_range& e){
                    /* Ignore */
                }
                
                if(node1 == NULL){
                    Node *newNode = new Node();
                    node[as] = newNode;
                    node1 = node[as];
                }
                
                node1->space.prefix = splitLine.at(0);
                node1->space.length = stoi(splitLine.at(1));
                
            }
        }
    }
    
}

vector<string> Graph::split(string s, string delimiter){
    vector<string> list;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}
