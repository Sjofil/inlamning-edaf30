#include "Node.h"
#include <string>
#include <vector>
#include <limits>
using std::string;
Node::Node(const std::string& name):name(name){}

string Node::getName() const {return name;}

void Node::setValue(int v){value=v;}

int Node::getValue() const {return value;}

void Node::addEdge(Node* destination, int length){edges.push_back(Edge(destination, length));}

std::vector<Edge>& Node::getEdges(){return edges;}

