//Double linked lists with simple operations.//
//Subject: lists//
//Author: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
struct double_lists{
    int info;
    struct double_lists *next;
    struct double_lists *previous;
};
typedef struct double_lists double_lists;

double_lists *list_create();
double_lists *list_insert(double_lists *l, int value);
double_lists *list_remove(double_lists *l, int value);    
int list_empty(double_lists *l);
void list_print(double_lists *l);
void list_inverse_print(double_lists *l);
void list_free(double_lists *l);

int main(void){
    int x, menu;
    double_lists *list = list_create();
    while(menu != 100){
        printf("\n\nMenu:\nPress 1 to insert one element in the list.\nPress 2 to print elements from the list.\nPress 3 to remove a element from the list.\nPress 100 to exit.\n\n");
        scanf("%d", &menu);
        switch(menu){
            case (1):
                printf("\n\nInform the element to insert.\n");
                scanf("%d", &x);
                list = list_insert(list, x);
                break;
            
            case (2):
                if(list_empty(list)){
                    printf("\n\nEmpty list !! Back to the main menu !!\n\n");
                }
                else{
                    printf("Press 1 print the list.\n Press 2 to print the list reversed.\n");
                    scanf("%d", &x);
                    if(x == 1){
                        list_print(list);
                    }
                    else{
                        if(x == 2){
                            list_inverse_print(list);
                        }
                        else{
                            printf("Invalid value. Back to the main menu !!");
                        }
                    }
                }
                break;
            
            case (3):
                if(list_empty(list)){
                    printf("\n\nEmpty list !! Back to the main menu !!\n\n");
                }
                else{
                    printf("\n\nInform the value to remove from the list.\n\n");
                    scanf("%d", &x);
                    list = list_remove(list, x);
                }
                break;
            
            case (100):
                printf("\n\nThank you for using this program!!\n\n");
                break;

            default:
                printf("\n\nInvalid option. Back to the main menu !!\n\n");
                break;
        }
    }
    list_free(list);
    return 0;
}

double_lists *list_create(){
   return NULL;
}

int list_empty(double_lists *l){
    return (l == NULL);
}

double_lists *list_insert(double_lists *l, int value){
    double_lists *new = (double_lists*) malloc (sizeof(double_lists));
    new -> info = value;
    new -> next = l;
    new -> previous = NULL;
    if(!list_empty(l)){
        l -> previous = new;
    }
    return new;
}

double_lists *list_remove(double_lists *l, int value){
    double_lists *aux = l;
    while(!list_empty(aux) && aux -> info != value){
        aux = aux -> next;
    }
    if(list_empty(aux)){
        printf("Element do not exist !!\n");
        return l;
    }                           

    if(list_empty(aux -> next) && list_empty(aux -> previous)){
        printf("\n\nElement (%d) excluded !!\n\n", aux->info);
        free(aux);
        return NULL;
    }                           

    if(list_empty(aux -> previous)){         
        l = aux -> next;
    }
    else{
        aux -> previous -> next = aux -> next;
    }

    if(!list_empty(aux -> next)){        
        aux -> next -> previous = aux -> previous;
    }
    printf("\n\nElement (%d) excluded !!\n\n", aux -> info);
    free(aux);
    return l;
}                

void list_print(double_lists *l){
    if(!list_empty(l)){
        printf("%d->", l -> info);
        list_print(l -> next);
    }
    printf("\n");
}

void list_inverse_print(double_lists *l){
    if(!list_empty(l)){
        list_inverse_print(l -> next);
        printf("<- %d", l -> info);
    }
}

void list_free(double_lists *l){
    double_lists *p=l;
    while(!list_empty(p)){
        double_lists *aux = p -> next;
        free(p);
        p = aux;
    }
}