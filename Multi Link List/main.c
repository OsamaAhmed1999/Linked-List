#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char *name;
    char *seat_no;
    double gpa;
    struct student *next;
};
struct classs
{
	char *name;
	int no_of_student;
	struct classs *next;
	struct student *head;
};

void main()
{
	struct classs *start = NULL;

	insert_class(&start , "Class1" , 1);
	insert_class(&start , "Class2" , 1);
	insert_class(&start , "Class3" , 1);

	insert_student(start , "Osama" , "111" , "Class1" , 4.0);
	insert_student(start , "Hamza" , "222" , "Class2" , 3.0);
    insert_student(start , "Fahad" , "333" , "Class2" , 3.4);

    /*print_student(start , "Class1");
    print_student(start , "Class2");
    printf("After Delete\n");
    delete_student(&start , "Fahad" , "333");
    print_student(start , "Class1");
    print_student(start , "Class2");
    print_student(start , "Class3");*/

    //search_student(&start , "Hamza" , "222");

    /*print_class(start);
    printf("After Delete\n");
    delete_class(&start , "Class1");
    print_class(start);*/
}

void insert_class(struct classs **start , char *name , int no_of_student)
{
	struct classs *ptr;
	ptr = (struct classs*)malloc(sizeof(struct classs));
	ptr->name = name;
	ptr->no_of_student = no_of_student;
	ptr->next = NULL;
	ptr->head = NULL;

	if(*start == NULL)
    {
        *start = ptr;
    }
    else
    {
        struct classs *curr = *start;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ptr;
	}
}

void insert_student(struct classs *start , char *name , char *seat_no , char *class_name , double gpa)
{
    struct student *ptr;
	ptr = (struct student*)malloc(sizeof(struct student));
	ptr->name = name;
	ptr->seat_no = seat_no;
	ptr->gpa = gpa;
	ptr->next = NULL;

	struct student **head = search_class(&start , class_name);

	if(*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct student *curr = *head;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ptr;
    }
}

void delete_student(struct classs **start , char *name , char *seat_no)
{
    struct classs *curr = *start;
    while(curr->next != NULL)
    {
        struct student **temp2 = &curr->head;
        if((*temp2)->name == name && (*temp2)->seat_no == seat_no)
        {
            *temp2 = (*temp2)->next;
            free(temp2);
            return;
        }
        else
        {
            struct student *temp = (curr->head)->next;
            struct student *prev = curr->head;
            while(temp != NULL)
            {
                if(temp->name == name && temp->seat_no == seat_no)
                {
                    prev->next = temp->next;
                    return;
                }
                prev = prev->next;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    printf("Not Found\n");
}

void delete_class(struct classs **start , char *class_name)
{
    if((*start)->name == class_name)
    {
        struct student *temp = (*start)->head;
        (*start)->head = NULL;
        while(temp != NULL)
        {
            temp = temp->next;
            free(temp);
        }
        *start = (*start)->next;
        free(start);
    }
    else
    {
        struct classs *curr = (*start)->next;
        struct classs *prev_class = *start;

        while(curr != NULL)
        {
            if(curr->name == class_name)
            {
                struct student *temp = curr->head;
                curr->head = NULL;
                while(temp != NULL)
                {
                    temp = temp->next;
                    free(temp);
                }
                break;
            }
            prev_class = prev_class->next;
            curr = curr->next;
        }
        if(curr != NULL && curr->head == NULL)
        {
            prev_class->next = curr->next;
        }
        else
        {
            printf("Class Not Found\n");
        }
    }
}

int search_class(struct classs **start , char *class_name)
{
    struct classs *curr = *start;
    while(curr != NULL)
    {
        if(curr->name == class_name)
        {
            return &curr->head;
        }
        curr = curr->next;
    }
}

void search_student(struct classs **start , char *name , char *seat_no)
{
    struct classs *curr = *start;
    while(curr != NULL)
    {
        struct student *temp = curr->head;
        while(temp != NULL)
        {
            if(temp->name == name && temp->seat_no == seat_no)
            {
                printf("%s %.2f" , curr->name , temp->gpa);
                return ;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }

    printf("Not Found");
}

void print_class(struct classs *start)
{
    struct classs *curr = start;
    while(curr != NULL)
    {
        printf("%s %d\n" , curr->name , curr->no_of_student);
        curr = curr->next;
    }
}

void print_student(struct classs *start , char *class_name)
{

    struct classs *curr = start;
    while(curr->name != class_name && curr->next != NULL)
    {
        curr = curr->next;
    }
    if(curr->name == class_name)
    {
        struct student *temp = curr->head;
        while(temp != NULL)
        {
            printf("%s %s %.2f\n" , temp->name , temp->seat_no , temp->gpa);
            temp = temp->next;
        }
    }
    else
    {
        printf("Class Not Found\n");
    }
}
