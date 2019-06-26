#include<stdio.h>
#include<stdlib.h>
struct Graph{
    int **matrix;
    int vertex;
};
typedef struct Graph Graph;

struct Result{
    int *color;
    int *distance;
    int *predecessor;
};
typedef struct Result Result;

struct List{
    int info;
    struct List *next;
};
typedef struct List List;

struct Queue{
	List *first;
	List *last;
};
typedef struct Queue Queue;

int empty_queue(Queue *q){
	return (q -> first == NULL);
}

Queue *create_queue(){
	Queue *q = (Queue*) malloc (sizeof(Queue));
	q -> first = q -> last = NULL;
	return q;
}

void insert_queue(Queue *q, int i){
	List *new = (List*) malloc (sizeof(List));
	new -> info = i;
	new -> next = NULL;
	if(empty_queue(q)){
		q -> first = new;
		q -> last = new;
    }
	else{
		q -> last -> next = new;
		q -> last = new;
    }
}

int remove_queue(Queue *q){
	List *aux = q -> first;
	int number = aux -> info;
	q -> first = aux -> next;
	free(aux);
	return number;
}

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
    r -> distance = (int*) malloc (sizeof(int) * vertex);
    int i;
    for(i = 0; i < vertex; i++){
        r -> color[i] = 0;
        r -> predecessor[i] = -1;
        r -> distance[i] = 0;
    }
    return r;
}

void *insert_edge(Graph *g, int v1, int v2){
    g -> matrix[v1][v2] = 1;
    g -> matrix[v2][v1] = 1;
}

Result *breadth_first_search(Graph *g, Result *r, int beginning){
    int current, adjacent;
    Queue *q = create_queue();
    r -> color[beginning] = 1; 
    insert_queue(q, beginning);
    while(!empty_queue(q)){
        current = remove_queue(q);
        for(adjacent = 0; adjacent < g -> vertex; adjacent++){
	        if(g -> matrix[current][adjacent] == 1){
	            if(r -> color[adjacent] == 0){
                    r -> color[adjacent] = 1;
	                r -> predecessor[adjacent] = current;
	                r -> distance[adjacent] = 1 + r -> distance[current];
	                insert_queue(q, adjacent);	            
                }
	        }
        }
        r -> color[current] = 2;
    }
    free(q);
    return r;
}

void free_result(Result *r){
    free(r -> color);
    free(r -> distance);
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
	int vertex, v1, v2, beginning, menu, i, j;
    printf("First, enter the vertex number of the graph.\n");
    scanf("%d", &vertex);
    Graph *g = create_empty_graph(vertex);
	Result *r = create_empty_result(g -> vertex);
	    while(menu != 4){
            printf("\n\nMenu:\n\n(1) Insert edges in the graph.\n(2) Breadth-First Search.\n(3) Show adjacentacence matrix.\n(4) Exit program.\n\n");
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
                    printf("Enter the vertex where the BFS begins.\n");
                    scanf("%d", &beginning);
                    if(beginning >= vertex){
                        printf("Invalid beginning !!\n");
                        break;
                    }
                    r = breadth_first_search(g, r, beginning);

                    for(i = 0; i < vertex; i++){
                        printf("r->color[%d]:%d   r->distance[%d]:%d   r->predecessor[%d]:%d\n", i, r -> color[i], i, r -> distance[i], i, r -> predecessor[i]);
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
