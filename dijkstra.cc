#include "dijkstra.h"

using std::cout;

void dijkstra(Node *start, bool print_shortest)
{

    //Låt start vara noden vi vill räkna avstånd från. Sätt start:s värde till 0.
    start->setValue(0);
    NodeSet S{};
    //Låt S vara en mängd av noder. Inledningsvis ska S innehålla en enda nod, nämligen start.
    S.add(start);

    //Så länge mängden S inte är tom ska följande upprepas:
    while (!S.isEmpty())
    {
        //Ta ut den nod ur S som har lägst värde. Kalla noden n
        Node *n = S.removeMin();
        //Gå igenom de bågar som utgår från n. För var och en av dessa bågar, gör följande:
        for (Edge e : n->getEdges())
        {
            //Kalla bågens längd för l och dess destination för d
            int l = e.getLength();
            Node *d = e.getDestination();
            //Låt a vara summan av n:s värde och l.
            int a = n->getValue() + l;
            //Om a är mindre än d:s värde: ändra d:s värde till a, och lägg in d i mängden S.

            if (a < d->getValue())
            {
                d->setValue(a);
                d->setParentNode(n);
                S.add(d);
                if (print_shortest)
                {
                    print_shortest_path(d);
                }
            }
        }
    }
}

void generalDijkstra(Node *start, int (*f)(Node *, Edge &), bool print_shortest)
{

    //Låt start vara noden vi vill räkna avstånd från. Sätt start:s värde till 0.
    start->setValue(0);
    NodeSet S{};
    //Låt S vara en mängd av noder. Inledningsvis ska S innehålla en enda nod, nämligen start.
    S.add(start);

    //Så länge mängden S inte är tom ska följande upprepas:
    while (!S.isEmpty())
    {
        //Ta ut den nod ur S som har lägst värde. Kalla noden n
        Node *n = S.removeMin();
        //Gå igenom de bågar som utgår från n. För var och en av dessa bågar, gör följande:
        for (Edge e : n->getEdges())
        {
            //Kalla bågens längd för l och dess destination för d
            int a = f(n, e);
            Node *d = e.getDestination();
            if (a < d->getValue())
            {
                d->setValue(a);
                d->setParentNode(n);
                S.add(d);
                if (print_shortest)
                {
                    print_shortest_path(d);
                }
            }
        }
    }
}

void print_shortest_path(Node *dest)
{
    std::vector<Node *> store_nodes;
    int length = dest->getValue();
    while (dest != nullptr)
    {
        store_nodes.push_back(dest);
        dest = dest->getParentNode();
    }
    //utskrift
    while (store_nodes.size() != 0)
    {
        Node *temp = store_nodes.back();
        cout << temp->getName() << " ";
        store_nodes.pop_back();
    }
    cout << length << "\n";
}
