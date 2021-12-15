#ifndef __EDGE_H
#define __EDGE_H

#include "Node.h"

class Node;
class Edge{
public:
/** Skapa en ny båge till noden destination, med längden length. */
Edge(Node* destination, int length);
/** Hämtar bågens destination. */
Node* getDestination();
/** Hämtar bågens längd. */
int getLength() const;

private:
Node* destination;
int length;
};
#endif