//Queue of structs with simple operations.//
//Subject: queue//
//Author: Luciano Moraes da Luz Brum//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date{
    int day;
    int month;
    int year;
};
typedef struct date Date;

struct person{
    char name[20];
    int age;
    Date birth_date;
};
typedef struct person Person;

struct list{
    Person info;
    struct list *next;
};
typedef struct list List;

struct queue{
    List *begin;
    List *end;
};
typedef struct queue Queue;

Queue *Queue_create(void);

void Queue_insert(Queue *f, char *name, int age, int day, int month, int year);

void Queue_remove(Queue *f, char *name, int *age, int *day, int *month, int *year);

int Queue_empty(Queue *f);

void Queue_free(Queue *f);

void Queue_print(Queue *f);

void Queue_print_oldest(Queue *f);

void Queue_print_special(Queue *f, int info, char op);

int main()
{
    Queue *f;
    char name[20], option, op;
    int day, month, year, age, created = 0;

    do{
        printf("\n\tMENU\n");
        printf("\n[a] Create a Queue.");
        printf("\n[b] Insert a Person in the Queue.");
        printf("\n[c] Remove a Person of the Queue.");
        printf("\n[d] Print Queue elements.");
        printf("\n[e] Print Persons with 18+ age.");
        printf("\n[f] Print Persons by day, month or year.");
        printf("\n[g] Exit program.");
        printf("\n\nChoose you option: ");
        fflush(stdin);
        scanf("%c", &option);
        switch(option){
            case 'a':
                if(created == 0){
                    f = Queue_create();
                    created = 1;
                }
                else{
                    printf("\n\nQueue already exists!\n\n");
                }
                break;

            case 'b':
                printf("\n\nEnter the name: ");
                scanf("%s", &name);
                printf("Enter the age: ");
                scanf("%d", &age);
                printf("Enter the born day: ");
                scanf("%d", &day);
                printf("Enter the born month: ");
                scanf("%d", &month);
                printf("Enter the born year: ");
                scanf("%d", &year);
                Queue_insert(f, name, age, day, month, year);
                break;

            case 'c':
                if(!Queue_empty(f)){
                    Queue_remove(f, name, &age, &day, &month, &year);
                    printf("\n\nThe Person below was removed from the Queue:");
                    printf("\n\nName: %s", name);
                    printf("\nAge: %d", age);
                    printf("\nBirthday: %d/%d/%d\n\n", day, month, year);
                }
                else{
                    printf("Empty Queue !!\n\n");
                }
                break;

            case 'd':
                Queue_print(f);
                break;

            case 'e':
                Queue_print_oldest(f);
                break;

            case 'f':
                do{
                    printf("\n\nHow do you want to filter: ");
                    printf("\n[a] day");
                    printf("\n[b] month");
                    printf("\n[c] year");
                    printf("\n\nChoose you option: ");
                    fflush(stdin);
                    scanf("%c", &op);
                    switch (op){
                        case 'a':
                            printf("\n\nEnter the day: ");
                            scanf("%d", &day);
                            Queue_print_special(f, day, op);
                            break;

                        case 'b':
                            printf("\nEnter the month (1 to 12): ");
                            scanf("%d", &month);
                            Queue_print_special(f, month, op);
                            break;

                        case 'c':
                            printf("\nEnter the year: ");
                            scanf("%d", &year);
                            Queue_print_special(f, year, op);
                            break;

                        default:
                            printf("\nInvalid Option!\n\n");
                            break;
                    }
                }
                while(op!='a' && op!='b' && op!='c');
                break;

                case 'g':
                    printf("\n\nThank you for using this program.");
                    Queue_free(f);
                    break;

                default:
                    printf("\nInvalid Option! Choose again!\n\n");
        }
    }
    while(option != 'g');
    return 0;
}

Queue *Queue_create(void){
    Queue *f= (Queue *)malloc(sizeof(Queue));
    f->begin = f->end = NULL;
    return f;
}

void Queue_insert(Queue *f, char *name, int age, int day, int month, int year){
    List *l = (List*)malloc(sizeof(List));
    strcpy(l->info.name, name);
    l->info.age = age;
    l->info.birth_date.day = day;
    l->info.birth_date.month = month;
    l->info.birth_date.year = year;
    l->next = NULL;
    if(f->end != NULL){
        f->end->next = l;
    }
    else{
        f->begin= l;
    }
    f->end = l;
}

void Queue_remove(Queue *f, char *name, int *age, int *day, int *month, int *year){
    if(Queue_empty(f)){
        printf("\nEmpty Queue!\n");
        return;
    }
    List *no = f->begin;
    strcpy(name, no->info.name);
    *age = no->info.age;
    *day = no->info.birth_date.day;
    *month = no->info.birth_date.month;
    *year = no->info.birth_date.year;
    f->begin = f->begin->next;
    if(f->begin == NULL){
        f->end = NULL;
    }
    free(no);
}

int Queue_empty(Queue *f){
    return (f->begin == NULL);
}

void Queue_free(Queue *f){
    List *l = f->begin;
    while(l != NULL){
        List *aux = l->next;
        free(l);
        l = aux;
    }
    free(f);
}

void Queue_print(Queue *f){
    List *l;
    if(f->begin != NULL){
        for(l = f->begin; l != NULL; l = l->next){
            printf("\nName: %s", l->info.name);
            printf("\nAge: %d", l->info.age);
            printf("\nDate of Birth: %d/%d/%d\n\n", l->info.birth_date.day, l->info.birth_date.month, l->info.birth_date.year);
        }
    }
    else{
        printf("Empty Queue !! \n\n");
    }
}

void Queue_print_oldest(Queue *f){
    List *l;
    for(l = f->begin; l != NULL; l = l->next){
        if(l->info.age > 18){
            printf("\nName: %s", l->info.name);
            printf("\nAge: %d", l->info.age);
            printf("\nDate of Birth: %d/%d/%d\n\n", l->info.birth_date.day, l->info.birth_date.month, l->info.birth_date.year);
        }
    }
}

void Queue_print_special(Queue *f, int info, char op){
    List *l;
    switch(op){
        case 'a':
            for(l = f->begin; l != NULL; l = l->next){
                if(l->info.birth_date.day == info){
                    printf("\nName: %s", l->info.name);
                    printf("\nAge: %d", l->info.age);
                    printf("\nDate of Birth: %d/%d/%d\n\n", l->info.birth_date.day, l->info.birth_date.month, l->info.birth_date.year);
                }
            }
            break;

        case 'b':
            for(l = f->begin; l != NULL; l = l->next){
                if(l->info.birth_date.month == info){
                    printf("\nName: %s", l->info.name);
                    printf("\nAge: %d", l->info.age);
                    printf("\nDate of Birth: %d/%d/%d\n\n", l->info.birth_date.day, l->info.birth_date.month, l->info.birth_date.year);
                }
            }
            break;

        case 'c':
            for(l = f->begin; l != NULL; l = l->next){
                if(l->info.birth_date.year == info){
                    printf("\nName: %s", l->info.name);
                    printf("\nAge: %d", l->info.age);
                    printf("\nDate of Birth: %d/%d/%d\n\n", l->info.birth_date.day, l->info.birth_date.month, l->info.birth_date.year);
                }
            }
            break;
    }
}