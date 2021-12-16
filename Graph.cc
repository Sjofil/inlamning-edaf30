#include <iostream>
#include <cassert>
#include "Graph.h"
#include <algorithm>
#include <utility>
#include <set>
#include "NodeSet.h"
#include <sstream>

using std::string;

Graph::Graph() {}

Graph::Graph(std::istream &in)
{
    string line;
    string dest;
    int length;
    string name;
    while (getline(in, line))
    {
        //skapar en stringstream av varje rad för att kunna extrahera ort, destination och sträcka. trimmar av ":"
        string fullname;
        std::stringstream ss;
        ss << line;

        ss >> name;
        while(name.find(":") == name.npos){
            fullname += name;
            ss >> name;
        }

        fullname += name.substr(0, name.length() - 1);
        //Efter fullname tar vi längden
        ss >> length;

        getline(ss, dest);
        //tar bort överflödigt blanksteg i början av ordet
        dest.erase(dest.begin(), dest.begin()+1);
        //lägg till båda noderna, om de redan finns händer inget och funktionen är i princip gratis så onödigt med massa if-satser
        addNode(fullname);
        addNode(dest);
        //hämta ut pekare på node-objektet och lägg till edge
        Node *node = find(fullname);

        node->addEdge(find(dest), length);
       
        dest.clear();
    }
}

void Graph::addNode(const std::string &name)
{

    if (find(name) == nullptr)
    {
        store_nodes.push_back(std::unique_ptr<Node>(new Node(name)));
    }
}

Node *Graph::find(const std::string &name)
{
    for (auto const &n : store_nodes)
    {
        Node *node = n.get();
        if (node->getName() == name)
        {
            return n.get();
        }
    }
    return nullptr;
}

void Graph::resetVals()
{
    for (auto &n : store_nodes)
    {
        n.get()->setValue(std::numeric_limits<int>::max());
    }
}
