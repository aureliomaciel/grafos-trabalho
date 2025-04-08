#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

typedef struct {
    int vertices;
    int **adj;
} GraphMatrix;

GraphMatrix* createGraphMatrix(int vertices);
void addEdgeMatrix(GraphMatrix* g, int src, int dest);
void printGraphMatrix(GraphMatrix* g);
void freeGraphMatrix(GraphMatrix* g);

#endif
