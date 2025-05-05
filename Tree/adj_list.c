#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode
{
    int vertex;
    struct GraphNode* Link;
}GraphNode;

typedef struct GraphType
{
    int n; //트리에서 노드의 개수와 동일
    GraphNode* adj_list[MAX_VERTICES]; //각 노드가 누구와 연결되있는지 나타내는 배열
}GraphType;

void init(GraphType* g){
    int v;
    g -> n = 0;
    for (v = 0; v < MAX_VERTICES; v++){
        g->adj_list[v] = NULL;
    }
}

void insert_vertex(GraphType* g, int v){
    if(((g->n)+1) > MAX_VERTICES){
        fprintf(stderr, "그래프: 정점 갯수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v){ 
    GraphNode* node; //예를들어서 in_e(g,2,4) 하고 in_e(g,2,3)하면 2가 3이랑 4랑 연결되나 3이랑 4는 2랑 연결하지않아서 단방향이다. 
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node -> vertex = v;
    node -> Link = g->adj_list[u];
    g -> adj_list[u] = node;
}

void print_adj_list(GraphType* g){
    for(int i = 0; i < g->n; i++){
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접리스트 ", i);
        while(p != NULL){
            printf("-> %d ", p->vertex);
            p = p->Link;
        }
        printf("\n");
    }
}

int main(){
    // 구현하세요
    GraphType g;
    init(&g);

    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);
    insert_vertex(&g, 6);
    insert_vertex(&g, 7);
    insert_vertex(&g, 8);

    insert_edge(&g, 0, 1);
    insert_edge(&g, 1, 2);
    insert_edge(&g, 1, 3);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 4);
    insert_edge(&g, 3, 4);
    insert_edge(&g, 3, 5);
    insert_edge(&g, 5, 6);
    insert_edge(&g, 5, 7);
    insert_edge(&g, 6, 8);

    print_adj_list(&g); 
    return 0;
}