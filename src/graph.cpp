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
        int deg = it->second->getDegree();

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
    cout << "\t6-100\t\t" << bin[2] << endl;
    cout << "\t101-200\t\t" << bin[3] << endl;
    cout << "\t201-1000\t" << bin[4] << endl;
    cout << "\t1000+\t\t" << bin[5] << endl << endl;
    cout << "\ttotal AS nodes by variable: " << total << endl;
    cout << "\ttotal AS nodes by sum: \t" << bin[0] + bin[1] + bin[2] + bin[3]
    + bin[4] + bin[5] + null << endl << endl;
    
}

void Graph::printGraphData3(){
    int total;
    int bin[7] = {0};
    int null = 0;
    
    getIPSpace();
    total = node.size();
    
    for (map<int, Node *>::iterator it = node.begin(); it != node.end(); ++it){
        int space = it->second->totalIPSpace;
        
        if(space >= 1 && space < pow(2, 6)){
            bin[0]++;
        }else if(space >= pow(2, 6) && space < pow(2, 10)){
            bin[1]++;
        }else if(space >= pow(2, 10) && space < pow(2, 14)){
            bin[2]++;
        }else if(space >= pow(2, 14) && space < pow(2, 18)){
            bin[3]++;
        }else if(space >= pow(2, 18) && space < pow(2, 22)){
            bin[4]++;
        }else if(space >= pow(2, 22) && space < pow(2, 26)){
            bin[5]++;
        }else if(space >= pow(2, 26)){
            bin[6]++;
        }else{
            null++;
            /* no defined ip space */
        }
    }
    
    cout << "----------> GRAPH DATA 3 <----------" << endl;
    cout << "\tAS IP Space Distribution:" << endl << endl;
    cout << "\tBINS" << endl;
    cout << "\t2^0  - 2^6\t:\t" << bin[0] << endl;
    cout << "\t2^6  - 2^10\t:\t" << bin[1] << endl;
    cout << "\t2^10 - 2^14\t:\t" << bin[2] << endl;
    cout << "\t2^14 - 2^18\t:\t" << bin[3] << endl;
    cout << "\t2^18 - 2^22\t:\t" << bin[4] << endl;
    cout << "\t2^22 - 2^26\t:\t" << bin[5] << endl;
    cout << "\t2^26 - 2^32\t:\t" << bin[6] << endl << endl;
    cout << "\ttotal AS nodes by variable: " << total << endl;
    cout << "\ttotal AS nodes by sum: \t" << bin[0] + bin[1] + bin[2] + bin[3] + bin[4] +
            bin[5] + bin[6] + null << endl << endl;
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
                break;
            case CONTENT:
                if(!it->second->customers.size() && it->second->degreeP2P > 0){
                    numContent++;
                }
                break;
            case ENTERPRISE:
                deg = it->second->getDegree();
                if(deg <= 2 && !it->second->customers.size() && !it->second->degreeP2P){
                    numEnterprise++;
                }
                break;
            case NONE:
                /* Do nothing */
                nonCat++;
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
    getTier1AS();
    
    cout << "----------> TABLE DATA 1 <----------" << endl;
    
    /* Get largest Clique */
    Clique *largest = &allCliques.front();
    for(int i = 0; i < allCliques.size(); i++){
        if(largest->size < allCliques.at(i).size){
            largest = &allCliques.at(i);
        }
    }
    
    for(auto &i : largest->nodes){
        cout << "AS: " << i->ASnum << ", NAME: " << i->name << ", DEGREE: " << i->getDegree() << endl;
    }
    
    cout << "SIZE: " << largest->size << endl;
}

void Graph::printTableData2(){
    getASRank();

    sort(rankList.begin(), rankList.end(), compByASes);
    cout << "----------> TABLE DATA 2 <----------" << endl;
    
    for(int i = 0; i < 25; i++){
        cout << "Rank: " << i+1 << ", AS #: " << rankList.at(i)->ASnum << ", Degree: " << rankList.at(i)->getDegree() <<
        ", AS Name: " << rankList.at(i)->name << ", # ASes: " << rankList.at(i)->nodeRank.ASes << ", # Prefixes: " << rankList.at(i)->nodeRank.advertisedIP <<
        ", # IPs: " << rankList.at(i)->nodeRank.uniqueIP << ", AS Percent " << (double)rankList.at(i)->nodeRank.ASes / (double)node.size() << ", Pre Percent " <<
        (double)rankList.at(i)->nodeRank.advertisedIP / (double)727792<< ", IP Percent " << (double)rankList.at(i)->nodeRank.uniqueIP / (double)pow(2, 32) << endl;
    }
}

void Graph::printTableData3(){
    
    sort(rankList.begin(), rankList.end(), compByPer);
    cout << "----------> TABLE DATA 3 <----------" << endl;

    for(int i = 0; i < 25; i++){
        cout << "Rank: " << i+1 << ", AS #: " << rankList.at(i)->ASnum << ", Degree: " << rankList.at(i)->getDegree() <<
        ", AS Name: " << rankList.at(i)->name << ", # ASes: " << rankList.at(i)->nodeRank.ASes << ", # Prefixes: " << rankList.at(i)->nodeRank.advertisedIP <<
        ", # IPs: " << rankList.at(i)->nodeRank.uniqueIP << ", AS Percent " << (double)rankList.at(i)->nodeRank.ASes / (double)node.size() << ", Pre Percent " <<
        (double)rankList.at(i)->nodeRank.advertisedIP / (double)727792<< ", IP Percent " << (double)rankList.at(i)->nodeRank.uniqueIP / (double)pow(2, 32) << endl;
    }
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
        if(splitLine.size() < 3){
            continue;
        }
        
        Node *newNode = new Node();
        newNode->ASnum = stoi(splitLine.front());
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
            newNode->ASnum = as1;
            node[as1] = newNode;
            node1 = node[as1];
        }
        if(node2 == NULL){
            Node *newNode = new Node();
            newNode->ASnum = as2;
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
                    newNode->ASnum = as;
                    node[as] = newNode;
                    node1 = node[as];
                }
                
                /* Add new IPSpace */
                IPSpace newSpace;
                newSpace.prefix = splitLine.at(0);
                newSpace.length = stoi(splitLine.at(1));
                newSpace.space = 32 - newSpace.length;
                node1->space.push_back(newSpace);
                node1->totalIPSpace += pow(2, newSpace.space);
            }
        }
    }
    
    getParentSpace();
}

void Graph::getParentSpace(){
    
    for (map<int, Node *>::iterator it = node.begin(); it != node.end(); ++it){
        
        for(auto &i : it->second->space){
            vector<string> prefixParts = split(i.prefix, ".");
            vector<int> nonZeroParts;
            for(int c = 0; c < prefixParts.size(); c++){
                if(stoi(prefixParts.at(c)) != 0){
                    nonZeroParts.push_back(stoi(prefixParts.at(c)));
                }
            }
            
            for(auto &j : it->second->customers){
                for(auto k : j->space){
                    if(k.parent == NULL){
                        vector<string> prefixParts2 = split(k.prefix, ".");
                        vector<int> nonZeroParts2;
                        for(int l = 0; l < prefixParts2.size(); l++){
                            if(stoi(prefixParts2.at(l)) != 0){
                                nonZeroParts2.push_back(stoi(prefixParts.at(l)));
                            }
                        }
                        
                        if(nonZeroParts2.size() >= nonZeroParts.size()){
                        
                            bool match = true;
                            for(int p = 0; p < nonZeroParts.size(); p++){
                                if(nonZeroParts.at(p) != nonZeroParts2.at(p)){
                                    match = false;
                                    cout << "HERE\n";
                                }
                            }
                            if(match){
                                k.parent = it->second;
                                //cout << "ASSIGNED\n";
                            }
                        }
                    }
                }
            }
        }
    }
    
}

void Graph::getTier1AS(){
    vector<Node *> degreeSort;
    
    getOrganizationNames();
    
    /* Add all nodes from map to vector */
    for (map<int, Node *>::iterator it = node.begin(); it != node.end(); ++it){
        degreeSort.push_back(it->second);
    }
    
    /* Sort function by degree */
    sort(degreeSort.begin(), degreeSort.end(), compByDeg);
 
    /* Calculate largest clique */
    //while(degreeSort.size() > 0){
        vector<Node *> clique;
        clique.push_back(degreeSort.front());
        degreeSort.erase(degreeSort.begin());
        int i = 0;
        
        while(1){
            Node *test = degreeSort.front();
            bool inClique;
            for(auto &i : clique){
                inClique = false;
                for(auto &j : i->link){
                    if(test == j->p2p.peer2 || test == j->p2p.peer1 || test == j->p2c.customer || test == j->p2c.provider){
                        inClique = true;
                        break;
                    }
                }
                
                if(!inClique) break;
            }
            
            if(!inClique) break;
            
            clique.push_back(degreeSort.at(i));
            i++;
        }
        
        Clique newClique(clique, clique.size());
        allCliques.push_back(newClique);
    //}
}

void Graph::getOrganizationNames(){
    fstream in;
    
    in.open(organizationsFile.c_str());
    
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
        if(splitLine.size() < 3){
            continue;
        }
        
        int as;
        Node *node1;
        try {
            as = stoi(splitLine.at(0));
            if (node.count(as) != 0) {
                node1 = node[as];
                node1->name = splitLine.at(2);
            }
        }
        catch(out_of_range& e){
            /* Ignore */
        }
        catch(invalid_argument& e){
            /* Ignore */
        }
    }
}

void Graph::getASRank(){

    for (map<int, Node *>::iterator it = node.begin(); it != node.end(); ++it){
        map<int, Node *> visited;
        getASRankHelper(it->second, visited);
        rankList.push_back(it->second);
    }
    
}

void Graph::getASRankHelper(Node *node, map<int, Node *> &visited){
    vector<Node *> cust;
    
    visited[node->ASnum] = node;
    for(int i = 0; i < node->customers.size(); i++){
        if(visited.count(node->customers.at(i)->ASnum) == 0){
            cust.push_back(node->customers.at(i));
        }
    }
    
    int num = 0;
    int prefix = 0;
    int ip = 0;
    while(cust.size() > 0){
        Node *temp = cust.front();
        if(visited.count(temp->ASnum) == 0){
            getASRankHelper(temp, visited);
            num += temp->nodeRank.ASes;
            prefix += temp->nodeRank.advertisedIP;
            for(auto i : temp->space){
                if(i.parent != node){
                    ip += pow(2, i.space);
                }
            }
            num++;
        }
        cust.erase(cust.begin());
    }
    
    node->nodeRank.advertisedIP = node->space.size() + prefix;
    node->nodeRank.ASes = num;
    node->nodeRank.uniqueIP = ip + node->totalIPSpace;
    
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
