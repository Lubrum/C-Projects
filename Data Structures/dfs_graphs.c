#include<stdio.h>
#include<stdlib.h>
struct Graph{
    int **matrix;
    int vertex;
};
typedef struct Graph Graph;

struct Result{
    int *color;
    int *initial_time;
    int *end_time;
    int *predecessor;
};
typedef struct Result Result;

Graph *create_empty_graph(int vertex){
    Graph *g = (Graph*) malloc (sizeof(Graph));
    g -> vertex = vertex;
    g -> matrix = (int**) malloc (sizeof(int*) * vertex);
    int i, j;
    for(i = 0; i < vertex; i++){
        g -> matrix[i] = (int*) malloc (sizeof(int) * vertex);
    }
    for(i = 0; i < vertex; i++){
	      for(j = 0; j < vertex; j++){
	          g -> matrix[i][j] = 0;
	      }
    }
    return g;
}

Result *create_empty_result(int vertex){
    Result *r = (Result*) malloc (sizeof(Result));
    r -> color = (int*) malloc (sizeof(int) * vertex);
    r -> predecessor = (int*) malloc (sizeof(int) * vertex);
    r -> initial_time = (int*) malloc (sizeof(int) * vertex);
    r -> end_time = (int*) malloc (sizeof(int) * vertex);
    int i;
    for(i = 0; i < vertex; i++){
        r -> color[i] = 0;
        r -> predecessor[i] = -1;
        r -> initial_time[i] = 0;
        r -> end_time[i] = 0;
    }
    return r;
}

void *insert_edge(Graph *g, int v1, int v2){
    g -> matrix[v1][v2] = 1;
    g -> matrix[v2][v1] = 1;
}

 void dfs_visit(int vertex, Graph *g, Result *r, int *time){
	int adjacent;
	r -> color[vertex] = 1;
	*time = *time + 1;
	r -> initial_time[vertex] = *time;
	for(adjacent = 0; adjacent < g -> vertex; adjacent++){
		if(g -> matrix[vertex][adjacent] == 1){
			if(r -> color[adjacent] == 0){
				r -> predecessor[adjacent] = vertex;
				dfs_visit(adjacent, g, r, time);
			}
		}
	}
	r -> color[vertex] = 2;
	*time = *time + 1;
	r -> end_time[vertex] = *time;
}

Result *depth_first_search(Graph *g, Result *r){
    int vertex, time = 0;
    for(vertex = 0; vertex < g -> vertex; vertex++){
		if(r -> color[vertex] == 0){
			dfs_visit(vertex, g, r, &time);
		}
	}
    return r;
}

void free_result(Result *r){
    free(r -> color);
    free(r -> initial_time);
    free(r -> end_time);
    free(r -> predecessor);
    free(r);
}

void free_graph(Graph *g, int vertex){
    int i;
    for(i = 0; i < vertex; i++){
        free(g -> matrix[i]);
    }
    free(g -> matrix);
    free(g);
}

int main(void){
	int vertex, v1, v2, menu, i, j;
    printf("First, enter the vertex number of the graph.\n");
    scanf("%d", &vertex);
    Graph *g = create_empty_graph(vertex);
	Result *r = create_empty_result(g -> vertex);
	while(menu != 4){
        printf("\n\nMenu:\n\n(1) Insert edges in the graph.\n(2) Depth-First Search.\n(3) Show adjacentacence matrix.\n(4) Exit program.\n\n");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                printf("Enter the vertex to insert an edge.\n");
                scanf("%d%d", &v1, &v2);
                if(v1 < 0 || v1 > vertex || v2 < 0 || v2 > vertex){
                    printf("This vertex does now exists !!\n");
                    break;
                }
                insert_edge(g, v1, v2);
                break;

            case 2:
                r = depth_first_search(g, r);
                for(i = 0; i < vertex; i++){
                    printf("r->color[%d]:%d   r->initial_time[%d]:%d   r->end_time[%d]:%d   r->predecessor[%d]:%d\n", i, r -> color[i], i, r -> initial_time[i], i, r -> end_time[i], i, r -> predecessor[i]);
                }
                break;

            case 3:
                for(i = 0; i < vertex; i++){
                    printf("\n");
                    for(j = 0; j < vertex; j++){
                        printf("%d ", g -> matrix[i][j]);
                    }
                }
                break;
                
            case 4:
                printf("\n\nThank you for using this program !!\n\n");
                free_result(r);
                free_graph(g, vertex);
                break;

            default:
                printf("\n\nInvalid option. Returning to the main menu.\n\n");
                break;
        }
    }
    return 0;
}
