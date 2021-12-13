#include "NodeSet.h"
#include <vector>
#include <string>
#include "Node.h"
#include <algorithm>
using std::string;


NodeSet::NodeSet(){}

void NodeSet::add(Node* node){
    //om vectorn är tom push back
    if(isEmpty()){
        nodes.push_back(node);
    } else if(!contains(node->getName())) {        //om vectorn inte är tom, håll vectorn sorterad i storleksordning med minsta objekten längst bak
         int counter=nodes.size()-1;
         while(nodes[counter]->getValue() < node->getValue()){
             counter--;
         }
         nodes.insert(nodes.begin()+counter, node);
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