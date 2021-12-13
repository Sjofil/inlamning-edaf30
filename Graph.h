#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <string>
#include <vector>
#include <limits>
#include <string>

class Graph{
    public:
        Graph();
        void addNode(const std::string &name);
        Node* find(const std::string &name);
        void resetVals();
        std::vector<std::unique_ptr<Node>>::iterator begin(){return store_nodes.begin();};
        std::vector<std::unique_ptr<Node>>::iterator end(){return store_nodes.end();};
    private:
        std::vector<std::unique_ptr<Node>> store_nodes;


};

#endif