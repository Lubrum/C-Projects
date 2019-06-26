// List 4
// 18 de novembro de 2011
// Luciano Moraes Da Luz Brum (lucianobrum53@yahoo.com.br)

#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int begin;
	int n;
	int vector[10];
};
typedef struct Queue Queue;

struct List{
	struct List *next;
	int info;
};
typedef struct List List;

struct QueueList{
	List *first;
	List *last;
};
typedef struct QueueList QueueList;

Queue* create_queue(){
	Queue *q = (Queue*) malloc (sizeof(Queue));
	q -> begin = 0;
	q -> n = 0;
	return q;
}

void insert_end_queue(Queue *q, int value){
	if(q -> n != 10){
		int final = (q -> begin + q -> n) % 10;
		q -> vector[final] = value;
		q -> n++;
	}
	else{
		printf("Full Queue !!\n");
		return;
	}
}

int empty_queue(Queue *q){
	return q -> n == 0;
}

int remove_first_queue(Queue *q){
	int value = q -> vector[q -> begin];
	q -> begin = (q -> begin + 1) % 10;
	q -> n--;
	return value;
}

void print_queue(Queue *q){
	int i;
	for(i = 0; i < q -> n; i++){
		printf(" %d -", q -> vector[(q -> begin + i) % 10]);
	}
}

void free_queue(Queue *q){
	free(q);
}

QueueList* create_queue_list(){
	QueueList *q = (QueueList*) malloc (sizeof(QueueList));
	q -> first = q -> last = NULL;
	return q;
}

void insert_end_queue_list(QueueList *q, int value){
	List *new = (List*) malloc (sizeof(List));
	new -> info = value;
	new -> next = NULL;
	if(q -> first == NULL && q -> last == NULL){
		q -> first = new;
		q -> last = new;
	}
	else{
		q -> last -> next = new;
		q -> last = new;
	}
}

int empty_queue_list(QueueList *q){
	return q -> first == NULL;
}

int remove_first_queue_list(QueueList *q){
		List *aux = q -> first;
		int number = aux -> info;
		q -> first = aux -> next;
		free(aux);
		return number;
}

void print_queue_list(QueueList *q){
	List *l;
	for(l = q -> first; l != NULL; l = l -> next){
		printf("%d -", l -> info);
	}
}

void free_queue_list(QueueList *q){
	List *l = q -> first;
	while(l != NULL){
		List *t = l -> next;
		free(l);
		l = t;
	}
	free(q);
}

int main(void){
	int option, menu, value;
	Queue *q1;
	QueueList *q2;
	printf("Enter the way to implement the queue:\n (1) vector of integers.\n (2) Linked lists of integers.\n");
	scanf("%d", &option);
	if(option == 1){
		q1 = create_queue();
		while(menu != 4){
			printf("Menu:\n(1) Insert element. \n(2) Remove element.\n(3) Print all elements.\n (4) Exit.\n");
			scanf("%d", &menu);
			switch(menu){
				case 1:
					printf("Enter a number to insert.\n");
					scanf("%d", &value);
					insert_end_queue(q1, value);
					break;

				case 2:
					if(!empty_queue(q1)){
                		printf("Number removed: %d.\n", remove_first_queue(q1));
					}
					else{
						printf("Empty Queue !!");
					}
					break;

				case 3:
					if(!empty_queue(q1)){
                		print_queue(q1);
					}
					else{
						printf("Empty Queue !!");
					}
					break;

				case 4:
					free_queue(q1);
					printf("\n\nThank you for using this program.");
					break;
			}
		}
	}
	if(option == 2){
		q2 = create_queue_list();
		while(menu != 4){
			printf("Menu:\n(1) Insert element. \n(2) Remove element.\n(3) Print all elements.\n (4) Exit.\n");
			scanf("%d", &menu);
			switch(menu){
				case 1:
					printf("Enter a number to insert.\n");
					scanf("%d", &value);
					insert_end_queue_list(q2, value);
					break;

				case 2:
					if(!empty_queue_list(q2)){
                		printf("Number removed: %d.\n", remove_first_queue_list);
					}
					else{
						printf("Empty Queue !!");
					}
					break;

				case 3:
					if(!empty_queue_list(q2)){
						print_queue_list(q2);
					}
					else{
						printf("Empty Queue !!");
					}
					break;

				case 4:
					free_queue_list(q2);
					printf("\n\nThank you for using this program.");
					break;
			}
		}
	}
	return 0;
}