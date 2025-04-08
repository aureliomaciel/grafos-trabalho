#include <stdio.h>
#include <stdlib.h>
#include "graph_list.h"

Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

GraphList* createGraphList(int vertices) {
    GraphList* g = malloc(sizeof(GraphList));
    g->vertices = vertices;
    g->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++)
        g->adjLists[i] = NULL;

    return g;
}

void addEdgeList(GraphList* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    
    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

void printGraphList(GraphList* g) {
    printf("Lista de Adjacência:\n");
    for (int v = 0; v < g->vertices; v++) {
        Node* temp = g->adjLists[v];
        printf("%d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraphList(GraphList* g) {
    for (int i = 0; i < g->vertices; i++) {
        Node* temp = g->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(g->adjLists);
    free(g);
}
