#include <iostream>
#include <string>
#include <cassert>
#include "Graph.h"
#include <algorithm>
#include <utility>
#include <set>
#include "Node.h"
#include "Edge.h"
#include "NodeSet.h"

Graph::Graph(){};

void Graph::addNode(const std::string &name){
   
    if(find(name) == nullptr){
        store_nodes.push_back(std::unique_ptr<Node>(new Node(name)));
    }
}

Node* Graph::find(const std::string &name){
    for(auto const &n : store_nodes){
        Node * node = n.get();
        if(node->getName() == name){
            return n.get();
        } 

    }
    return nullptr;
}

void Graph::resetVals(){
    for(auto &n : store_nodes){
        n.get()->setValue(std::numeric_limits<int>::max());
    }

}
