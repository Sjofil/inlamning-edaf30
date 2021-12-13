#include <vector>
#include <string>
#include "Edge.h"

class Node {
public:
    /** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
    Node(const std::string& name);
    /** Hämtar nodens namn. */
    std::string getName() const;
    /** Sätter nodens värde till v. */
    void setValue(int v);
    /** Hämtar nodens värde. */
    int getValue() const;
    /** Lägger till en ny båge från denna nod till en given destination.
         Bågen ska ha längden length. */
    void addEdge(Node* destination, int length);
    /** Hämtar de bågar som utgår från denna nod. */
    const std::vector<Edge>& getEdges() const;

    private:
        std::vector<Edge> destinations;
        std::string node_name;
        int node_value{std::numeric_limits<int>::max()};
        


};