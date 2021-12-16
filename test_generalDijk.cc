
#include "dijkstra.h"
#include "dijkstra.cc"
using std::cout;
using std::endl;

//Samma algoritm som dijkstra enligt uppgiftbeskrivningen.
int getCost(Node *n, Edge &e)
{
    //Kalla bågens längd för l och dess destination för d
    int l = e.getLength();

    //Låt a vara summan av n:s värde och l.
    int a = n->getValue() + l;

    return a;
}

//Här räknas value ut genom antal föräldranoder istället.

int getCostParentNodes(Node *n, Edge &e)
{
    //spara antal föräldranoder istället för längden
    int cost = 0;
    while (n != nullptr)
    {
        ++cost;
        n = n->getParentNode();
    }
    return cost;
}

//Här räknas kostnaden ut genom totalt antal tecken i färdvägen

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

void test_generalDijk_nbrChar()
{
    bool print_shortest = false;
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

    generalDijkstra(&lund, getCostNbrChars, print_shortest);
    assert(dalby.getValue() == 9);
    assert(sandby.getValue() == 16);
    assert(hallestad.getValue() == 24);

    cout << "test_generalDijk_nbrChar passed" << endl;
}

void test_generalDijk_cost()
{
    bool print_shortest = false;

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

    generalDijkstra(&lund, getCost, print_shortest);
    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);

    cout << "test_generalDijk_cost passed" << endl;
}

void test_generalDijk_parentNodes()
{
    bool print_shortest = false;
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

    generalDijkstra(&lund, getCostParentNodes, print_shortest);
    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 1);
    assert(sandby.getValue() == 1);
    assert(hallestad.getValue() == 2);

    cout << "test_generalDijk_parentNodes passed" << endl;
}

int main()
{
    test_generalDijk_nbrChar();
    test_generalDijk_parentNodes();
    test_generalDijk_cost();

    return 0;
}
