#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int vertices;
    Node** adjLists;
} GraphList;

GraphList* createGraphList(int vertices);
void addEdgeList(GraphList* g, int src, int dest);
void printGraphList(GraphList* g);
void freeGraphList(GraphList* g);

#endif
