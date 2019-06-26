//Sorted list//
//Subject: lists//
//Author: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>

struct list{
  int info;
  struct list *next;
};
typedef struct list List;

List *create_empty(){
  return NULL;
}

List *insert(List *original, int x){
  List *aux = original;
  List *previous = NULL;
  List *new = (List*) malloc (sizeof(List));
  new -> info = x;
  while(aux != NULL && x > aux -> info){
    previous = aux;
    aux = aux -> next;
  }
  if(previous == NULL){
    new -> next = aux;//aux==previous->next
    return new;
  }
  else{
    new -> next = previous -> next;//previous->next=aux
    previous -> next = new;
    return original;
  }
}

void show_list_recursive(List *original){
  if(original != NULL){
    printf("%d ->", original -> info);
    show_list_recursive(original -> next);
  }
}

void show_reverse_list_recursive(List *original){
  if(original != NULL){
    show_reverse_list_recursive(original -> next);
    printf("%d <-", original -> info); 
  }
}

int main(void){
  int i, x;
  List *list = create_empty();
  for(i = 0; i < 10; i++){
    printf("Inform 10 integers to insert in the list.\n");
    scanf("%d", &x);
    list = insert(list, x);
  }
  show_list_recursive(list);
  printf("\n\n");
  show_reverse_list_recursive(list);
  return 0;
}

