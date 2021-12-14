#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <string>
#include <vector>
#include <limits>
#include <string>
#include <memory>

class Graph{
    public:
        Graph();
        /** Skapar en graf med noder och bågar som läses från strömmen in. */
        Graph(std::istream& in);
        /** Lägger till en nod i vektorna store_nodes */
        void addNode(const std::string &name);
        /** Kollar om noden redan finns i store_nodes */
        Node* find(const std::string &name);
        /** Återställer värdet på alla noder så dijstras algoritm kan upprepas */
        void resetVals();
        /** Retunerar en iterator till första objektet i store_nodes */
        std::vector<std::unique_ptr<Node>>::iterator begin(){return store_nodes.begin();};
        /** Retunerar en iterator till sista objektet i store_nodes */
        std::vector<std::unique_ptr<Node>>::iterator end(){return store_nodes.end();};
    private:
        std::vector<std::unique_ptr<Node>> store_nodes;
        


};

#endif