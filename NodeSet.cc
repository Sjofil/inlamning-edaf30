#include "NodeSet.h"
#include <vector>
#include <string>
#include "Node.h"
#include <algorithm>
#include <iostream>
using std::string;


NodeSet::NodeSet(){}

void NodeSet::add(Node* node){
    //om vectorn är tom push back
    if(!contains(node->getName())){
        nodes.push_back(node);
    }
}

Node* NodeSet::removeMin(){
    Node* last = nodes[nodes.size()-1];
    nodes.pop_back();
    return last;
}

bool NodeSet::contains(string a){
    int counter=0;
    for(Node* node: nodes){
        if(node->getName()==a){
            return true;
        }
    }
    return false;
}

bool NodeSet::isEmpty(){
    return nodes.empty();
}