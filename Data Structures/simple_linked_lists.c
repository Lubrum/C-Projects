//Simple Linked Lists with simple operations (Create, Remove, Insert, Free and Print)//
//Subject: lists//
//Author: Luciano Moraes da Luz Brum//

#include<stdio.h>
#include<stdlib.h>

struct list{
    int info;
    struct list *next;
};
typedef struct list list;

list *list_create_empty();
list *list_insert(list *l, int value);
int empty_list(list *l);
void list_print(list *l);
list *list_remove(list *l, int value);
void list_free(list *l);

int main(void){
    list *l = list_create_empty();
    int x, menu;

    while(menu != 100){
        printf("Menu:\nPress 1 to insert one element in the list.\nPress 2 to print elements from the list.\nPress 3 to remove a element from the list.\nPress 100 to exit.\n\n");
        scanf("%d", &menu);

        switch(menu){
            case (1):
                printf("\n\nInform a number to insert into the list\n");
                scanf("%d", &x);
                l = list_insert(l,x);
                break;
            
            case (2):
                if(empty_list(l)){
                    printf("\n\nEmpty list !! Back to the main menu !!\n\n");
                }
                else{
                    list_print(l);
                }
                break;
            
            case (3):
                if(empty_list(l)){
                    printf("\n\nEmpty list !! Back to the main menu !!\n\n");
                }
                else{
                    printf("\n\nInform the value to remove from the list.\n\n");
                    scanf("%d", &x);
                    l = list_remove(l, x);
                }
                break;
            
            case (100):
                printf("\n\nThank you for using this program!!\n\n");
                break;


            default:
                printf("\n\nInvalid option. Select another option.\n\n");
                break;
        }
    }
    list_free(l);
    return 0;
}

list *list_create_empty(){
    return NULL;
}

list *list_insert(list *l, int value){
    list *novo = (list*) malloc(sizeof(list));
    novo -> info = value;
    novo -> next = l;
    return novo;
}

int empty_list(list *l){
    return (l == NULL);
}

void list_print(list *l){
    list *aux;
    for(aux = l;aux != NULL;aux = aux -> next){
        printf("%d ->", aux -> info);
    }
    printf("\n");
}

list *list_remove(list *l, int value){
    list *aux = l;
    list *ant = NULL;

    while(!empty_list(aux) && aux -> info != value){
        ant = aux;
        aux = aux->next;
    }

    if(empty_list(aux)){
        printf("\n\nElement not found!!\n\n");
        return l;
    }

    if(empty_list(ant)){
        l = aux -> next;
    }
    else{
        ant -> next = aux -> next;
    }

    printf("\n\nElement (%d) removed !!\n\n", aux -> info);
    free(aux);
    return l;
}

void list_free(list *l){
    list *p = l;
    while(!empty_list(p)){
        list *aux = p -> next;
        free(p);
        p = aux;
    }
}