#include "NodeSet.h"
#include <vector>
#include <string>
#include "Node.h"
#include <algorithm>
#include <iostream>
using std::string;

NodeSet::NodeSet() {}

void NodeSet::add(Node *node)
{
    if (!contains(node->getName()))
    {
        nodes.push_back(node);
    }
}

Node *NodeSet::removeMin()
{
    Node *n = nullptr;
    int min_value = std::numeric_limits<int>::max();
    int pos = -1;
    for (auto const &i : nodes)
    {
        if (i->getValue() < min_value)
        {
            min_value = i->getValue();
            n = i;
            pos++;
        }
    }
    nodes.erase(nodes.begin() + pos);
    return n;
}

bool NodeSet::contains(string a)
{
    for (Node *node : nodes)
    {
        if (node->getName() == a)
        {
            return true;
        }
    }
    return false;
}

bool NodeSet::isEmpty()
{
    return nodes.empty();
}