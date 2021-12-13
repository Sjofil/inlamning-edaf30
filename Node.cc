#include "Node.h"
#include <vector>
#include <string>
#include "Edge.h"

Node::Node(const std::string& name):node_name{name} {};

std::string Node::getName() const{
    return node_name;
}

    void Node::setValue(int v){
        node_value = v;
    }
 
    int Node::getValue() const{
        return node_value;
    }
   
    void Node::addEdge(Node* destination, int length){
        Edge e(destination, length);
        destinations.push_back(e);

    }
   
    const std::vector<Edge>& Node::getEdges() const{
        return destinations;
    }
