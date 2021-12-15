#ifndef __DIJKSTRA_H
#define __DIJKSTRA_H
#include <iostream>
#include <vector>
#include <cassert>
#include "Node.h"
#include "NodeSet.h"

/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
void dijkstra(Node* start, bool print_path);
/** Användaren har möjligthet att skicka in en funktion för att räkna
 * kostand på valfritt sätt */
void generalDijkstra(Node* start, bool print_path, bool print_shortest);

/** Hjälpmetod för att skriva ut den kortaste vägen från en destination */
void print_shortest_path(Node *dest);

#endif