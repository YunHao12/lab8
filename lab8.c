#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void printAdjacencyMatrix(int graph[][MAX_VERTICES], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printAdjacencyList(Node* adjList[], int vertices) {
    printf("Adjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d: ", i);
        Node* current = adjList[i];
        while (current != NULL) {
            printf("%d->", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int vertices = MAX_VERTICES;

    // Creating adjacency list from adjacency matrix
    Node* adjList[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                addEdge(adjList, i, j);
            }
        }
    }

    printAdjacencyMatrix(graph, vertices);
    printf("\n");
    printAdjacencyList(adjList, vertices);

    // Freeing the memory allocated for the adjacency list
    for (int i = 0; i < vertices; i++) {
        Node* current = adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
