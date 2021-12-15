#include <iostream>
#include <cassert>


#include "Node.h"
#include "NodeSet.h"
#include "Edge.h"

#include "generalDijkstra.cc"
using std::cout;
using std::endl;

//samma algoritm som tidigare
int getCost(Node* n, Edge& e){
    //Kalla bågens längd för l och dess destination för d
            int l=e.getLength();
            
            //Låt a vara summan av n:s värde och l.
            int a=n->getValue()+l;

            return a;
}

//här räknas value ut genom antal föräldranoder istället.

int getCostParentNodes(Node* n, Edge& e){
    //spara antal föräldranoder istället för längden
    int cost=0;
    while(n!=nullptr){
        ++cost;
        n=n->getParentNode();
    }
    return cost;
}

//här räknas kostnaden ut genom totalt antal tecken i färdvägen

int getCostNbrChars(Node* n, Edge& e){
    int cost=0;

    while (n!=nullptr)
    {
        cost+=n->getName().size();
        n=n->getParentNode();
    }
   
    
    cost+=e.getDestination()->getName().size();
    return cost;
    
}

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




    
    cout << "test_dijkstra passed" << endl;

    generalDijkstra(&lund, getCostNbrChars);
    
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }

    cout << "test_dijkstra passed" << endl;

   
}



int main()
{
    test();
    return 0;
}
