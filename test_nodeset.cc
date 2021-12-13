#include "nodeset.h"
#include <cassert>
#include <iostream>
#include "Node.h"

void test()
{
    NodeSet ns{};
    std::cout << "begin testing \n";
    Node a("A");
    a.setValue(10);
    Node b("B");
    b.setValue(20);
    Node c("C");
    c.setValue(30);

    ns.add(&a);
    ns.add(&b);
    ns.add(&c);
    std::cout << "added abc \n";
    std::cout << ns.removeMin()->getValue();


    assert(ns.removeMin() == &a);
     std::cout << "begin testing";
    assert(ns.removeMin() == &b);
    assert(ns.removeMin() == &c);
    std::cout << "removeMin() working fine";
    assert(ns.isEmpty());

    ns.add(&a);
    assert(!ns.isEmpty());

    ns.add(&b);
    assert(!ns.isEmpty());

    ns.add(&c);
    assert(!ns.isEmpty());

    ns.add(&a);
    assert(!ns.isEmpty());

    a.setValue(40);

    assert(ns.removeMin() == &b);
    assert(ns.removeMin() == &c);
    assert(ns.removeMin() == &a);

    assert(ns.isEmpty());
}

int main()
{
    test();
    std::cout << "test_nodeset passed" << std::endl;
    return 0;
}
