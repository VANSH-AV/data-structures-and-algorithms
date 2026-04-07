#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add directed edge u -> v
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);

    // Insert in sorted order (to ensure smaller nodes visited first)
    if (graph->adj[u] == NULL || graph->adj[u]->vertex > v) {
        newNode->next = graph->adj[u];
        graph->adj[u] = newNode;
    } else {
        struct Node* temp = graph->adj[u];
        while (temp->next != NULL && temp->next->vertex < v)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// DFS function
void DFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int start;
    scanf("%d", &start);

    int visited[MAX] = {0};

    DFS(graph, start, visited);

    return 0;
}
