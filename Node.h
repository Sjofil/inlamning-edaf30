#ifndef NODE_H
#define NODE_H
#include "Edge.h"
#include <string>
#include <vector>
#include <limits>

class Edge;

class Node{
public:
/** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
Node(const std::string& name);
/** Hämtar nodens namn. */
std::string getName() const;
/** Sätter nodens värde till v. */
void setValue(int v);
/** Hämtar nodens värde. */
int getValue() const;
/** Lägger till en ny båge från denna nod till en given destination.
Bågen ska ha längden length. */
void addEdge(Node* destination, int length);
/** Hämtar de bågar som utgår från denna nod. */
std::vector<Edge>& getEdges();
/** Hämtar nodens förälder nod */
Node * getParentNode();
/** Sätter förälder nodens värde */
void setParentNode(Node * &node);

static const int max_value=std::numeric_limits<int>::max();

private:
Node * parent{nullptr};
std::string name;
int value{max_value};
std::vector<Edge> edges;
};


#endif