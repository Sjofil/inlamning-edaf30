#include "dijkstra.cc"
#include "dijkstra.h"

int getCost(Node *n, Edge &e);
int getCostParentNodes(Node *n, Edge &e);

int main()
{

    bool print_shortest = true;

    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby, 12);
    lund.addEdge(&sandby, 12);
    dalby.addEdge(&sandby, 12);
    dalby.addEdge(&veberod, 11);
    dalby.addEdge(&hallestad, 5);
    sandby.addEdge(&lund, 12);
    sandby.addEdge(&flyinge, 4);
    hallestad.addEdge(&veberod, 8);

    std::cout << "Dijkstras algoritm enligt uppgiften. Med kostand enligt edge längd: \n";

    generalDijkstra(&lund, getCost, print_shortest);

    std::cout << "\n";
    std::cout << "Dijkstras algortims generaliserad. Med kostnad för antal noder som passeras: \n";

    generalDijkstra(&lund, getCostParentNodes, print_shortest);
}

int getCost(Node *n, Edge &e)
{

    int l = e.getLength();
    int a = n->getValue() + l;

    return a;
}

int getCostParentNodes(Node *n, Edge &e)
{
    int cost = 0;
    while (n != nullptr)
    {
        ++cost;
        n = n->getParentNode();
    }
    return cost;
}

int getCostNbrChars(Node *n, Edge &e)
{
    int cost = 0;
    while (n != nullptr)
    {
        cost += n->getName().size();
        n = n->getParentNode();
    }
    cost += e.getDestination()->getName().size();
    return cost;
}
