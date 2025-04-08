#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"

GraphMatrix* createGraphMatrix(int vertices) {
    GraphMatrix* g = malloc(sizeof(GraphMatrix));
    g->vertices = vertices;

    g->adj = malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->adj[i] = calloc(vertices, sizeof(int));
    }

    return g;
}

void addEdgeMatrix(GraphMatrix* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; 
}

void printGraphMatrix(GraphMatrix* g) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

void freeGraphMatrix(GraphMatrix* g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}
