#include "Edge.h"
#include "Node.h"

using std::string;

Edge::Edge(Node* destination, int length):destination(destination), length(length){}

Node* Edge::getDestination(){return destination;}

int Edge::getLength() const{return length;}

