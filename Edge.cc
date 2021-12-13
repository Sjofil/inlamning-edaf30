#include <vector>
#include <string>
#include "Edge.h"
#include "Node.h"


   Edge::Edge(Node* destination, int length): dest{destination}, length(length) {}


   Node* Edge::getDestination(){
       return dest.getName();

   }

   int Edge::getLength() const{
       return length;
   }