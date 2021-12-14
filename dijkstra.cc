#include "dijkstra.h"
#include "NodeSet.h"
#include <iostream>
#include <vector>
using namespace::std;


void dijkstra(Node* start){

    //Låt start vara noden vi vill räkna avstånd från. Sätt start:s värde till 0.
    start->setValue(0);
    NodeSet S{};
    //Behövs senare för att skriva ut vägen till destinationen.
    Node *destination;

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
                d->setParentNode(n);
                S.add(d);
                //Hittar vägen till parentnode
                destination = d;
                std::vector<Node*> store_nodes;
                while (destination != nullptr){
                   store_nodes.push_back(destination);
                    destination = destination->getParentNode();
                }
                //utskrift
                while(store_nodes.size() != 0){
                    Node * temp = store_nodes.back();
                    cout << temp->getName() << " ";
                    store_nodes.pop_back();
                }
                cout << d->getValue() <<  "\n";
                {
                    /* code */
                }
                
            }
        }
    }
}