#include "Node.h"


/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
void dijkstra(Node* start);


void generalDijkstra(Node* start);

/** Hjälpmetod för att skriva ut den kortaste vägen från en destination */
void print_shortest_path(Node *dest);