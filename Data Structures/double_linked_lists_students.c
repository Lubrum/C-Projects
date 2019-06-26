//List of students with create, insert, search, remove and free operations.//
//Subject: lists//
//Author: Luciano Moraes da Luz Brum//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date{
    int day, month, year;
};
typedef struct date Date;

struct student{
    char name[80];
    Date *birthday;
};
typedef struct student Student;

struct list{
    Student *person;
    struct list *next;
    struct list *previous;
};

typedef struct list Double_list;

Double_list *create_empty();
Double_list *insert_student(Double_list *l);
Double_list *remove_student(Double_list *l, char *z);
int empty_list(Double_list *l);
void show_list(Double_list *l);
void show_inverse_list(Double_list *l);
void show_youngest_student(Double_list *l);
void free_list(Double_list *l);

int main(void){
    int x, menu;
    char name[80];
    Double_list *student_list = create_empty();
    while(menu != 100){
        printf("\n\nMenu:\nPress 1 to insert one student in the list.\nPress 2 to remove one student from the list.\nPress 3 to show the students.\nPress 4 to show the youngest student.\nPress 100 to exit.\n\n");
        scanf("%d", &menu);
        switch(menu){
            case (1):
                student_list = insert_student(student_list);
                break;

            case (2):
                if(empty_list(student_list)){
                    printf("\n\nEmpty list!! Insert at least one student.\n\n");
                }
                else{
                    printf("Give the student name to remove from the list.\n");
                    scanf(" %[^\n]", name);
                    student_list = remove_student(student_list, name);
                }
                break;

            case(3):
                if(empty_list(student_list)){
                    printf("\n\nEmpty list!! Insert at least one student.\n\n");
                }
                else{
                    printf("\nPress 1 to show students in order.\n Press 2 to show students in reverse order.\n");
                    scanf("%d", &x);
                    if(x == 1){
                        show_list(student_list);
                    }
                    else{
                        if(x == 2){
                            show_inverse_list(student_list);
                        }
                        else{
                            printf("This value is invalid. Going back to the main menu !!");
                        }
                    }
                }
                break;

            case(4):
                if(empty_list(student_list)){
                    printf("\n\nEmpty list!! Insert at least one student.!!\n\n");
                }
                else{
                    show_youngest_student(student_list);
                }
                break;

            case(100):
                printf("\n\nThank you for using this program!!\n\n");
                break;

            default:
                printf("\n\nInvalid option. Press another option.\n\n");
                break;            
        }
    }
    free_list(student_list);
    return 0;
}

Double_list *create_empty(){
    return NULL;
}

Double_list *insert_student(Double_list *l){
    Double_list *new = (Double_list*) malloc (sizeof(Double_list));
    new -> next = l;
    new -> previous = NULL;
    new -> person = (Student*) malloc (sizeof(Student));
    new -> person->birthday = (Date*) malloc (sizeof(Date));
    printf("Inform the student name.\n");
    scanf(" %[^\n]", new -> person -> name);
    printf("Inform the student birthday (dd/mm/yyyy)\n");
    scanf("%d", &new -> person -> birthday -> day);
    scanf("%d", &new -> person -> birthday -> month);
    scanf("%d", &new -> person -> birthday -> year);
    if(l != NULL){
        l -> previous = new;
    }
    return new;
}
     
int empty_list(Double_list *l){
    return (l == NULL);
}

Double_list *remove_student(Double_list *l, char *name){
	Double_list *aux=l;
	while(!empty_list(aux) && strcmp(aux -> person -> name, name) != 0){
	      aux = aux -> next;
    }
    if(empty_list(aux)){
        printf("This Student do not exist!! Back to the main menu!!\n");
        return l;
    }   
	if(!empty_list(aux -> next) && empty_list(aux -> previous)){
        printf("\n\nStudent (%s) removed !!\n\n", aux -> person -> name);
	    free(aux -> person -> birthday);
        free(aux -> person);
        free(aux);
	    return NULL;
    }             
	if(empty_list(aux -> previous)){     
	    l = aux -> next;
    }
	else{
	    aux -> previous -> next = aux -> next;
    }
    if(!empty_list(aux -> next)){        
        aux -> next -> previous = aux -> previous;
    }
    free(aux -> person -> birthday);
    free(aux -> person);
    free(aux);
    return l;
}

void show_list(Double_list *l){
    if(!empty_list(l)){
        printf("%s->", l -> person -> name);
        show_list(l -> next);
    }
    printf("\n");
}

void show_inverse_list(Double_list *l){
    if(!empty_list(l)){
        show_inverse_list(l -> next);
        printf("<-%s", l -> person -> name);
    }
}

void show_youngest_student(Double_list *l){
    int biggest_day = 0, biggest_mes = 0, biggest_ano = 0;
    Student *youngest;
    while(!empty_list(l)){
        if(l -> person -> birthday -> year > biggest_ano){
            youngest = l -> person;
            biggest_ano = l -> person -> birthday -> year;
            biggest_mes = l -> person -> birthday -> month;
            biggest_day = l -> person -> birthday -> day;
        }
        else{
            if(l -> person -> birthday -> year == biggest_ano){
                if(l -> person -> birthday -> month > biggest_mes){
                    youngest = l -> person;
                    biggest_mes = l -> person -> birthday -> month;
                    biggest_day = l -> person -> birthday -> day;
                }
                else{
                    if(l -> person -> birthday -> month == biggest_mes){
                        if(l -> person -> birthday -> day > biggest_day){
                            youngest = l -> person;
                            biggest_day = l -> person -> birthday -> day;
                        }
                    }
                }
            }
        }
        l = l -> next;
    }
    printf("Youngest Student:\n\tName: %s.\n\tBirthday: %d/%d/%d.\n\n", youngest -> name, youngest -> birthday -> day, youngest -> birthday -> month, youngest -> birthday -> year);
}

void free_list(Double_list *l){
    Double_list *p = l;
    while(!empty_list(p)){
        Double_list *aux = p -> next;
        free(p -> person -> birthday);
        free(p -> person);
        free(p);
        p = aux;
    }
}
