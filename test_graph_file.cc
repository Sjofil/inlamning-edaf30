#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <utility>
#include <set>
#include "Graph.h"


void find_and_test(const std::string& name, Graph& g){
    Node* n=g.find(name);
    assert(n != nullptr);
    assert(n->getName() == name);
    assert(n->getValue() == Node::max_value);
    std::cout << "test for " << name << " has passed \n";
}

void test_graph(){
    std::ifstream in("graphnodes.txt");
    Graph g(in);

    find_and_test("Lund", g);
    find_and_test("Dalby", g);
    find_and_test("Veberod", g);

}

int main(){
    test_graph();
    return 0;
}