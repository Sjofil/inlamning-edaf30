#include <iostream>
#include <cassert>

#include "dijkstra.h"
#include "Node.h"
#include "NodeSet.h"
#include "Edge.h"
using std::cout;
using std::endl;

void test()
{
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    dalby.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);

    dijkstra(&lund);

    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);



    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }

    cout << "test_dijkstra passed" << endl;
}

void dijkstra(Node* start){

    //Låt start vara noden vi vill räkna avstånd från. Sätt start:s värde till 0.
    start->setValue(0);
    NodeSet S{};

    //Låt S vara en mängd av noder. Inledningsvis ska S innehålla en enda nod, nämligen start.
    S.add(start);

    //Så länge mängden S inte är tom ska följande upprepas:
    while(!S.isEmpty()){
        //Ta ut den nod ur S som har lägst värde. Kalla noden n
        Node* n=S.removeMin();
        //Gå igenom de bågar som utgår från n. För var och en av dessa bågar, gör följande:
        for(Edge e:n->getEdges()){
            //Kalla bågens längd för l och dess destination för d
            int l=e.getLength();
            Node* d=e.getDestination();
            //Låt a vara summan av n:s värde och l.
            int a=n->getValue()+l;
            //Om a är mindre än d:s värde: ändra d:s värde till a, och lägg in d i mängden S.
            if(a<d->getValue()){
                d->setValue(a);
                S.add(d);
            }
        }
    }

}

int main()
{
    test();
    return 0;
}
