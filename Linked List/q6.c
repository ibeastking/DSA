#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STU
{
    int roll;
    char nm[15];
    int m;
    int flag;
} student;

typedef struct NODE
{
    student data;
    struct NODE *next;
} node;

typedef struct STULIST
{
    node *head;
    int cnt;
} stulist;

void init(stulist *p)
{
    p->head = 0;
    p->cnt = 0;
}

//! Function to search roll number wise

node *searchroll(stulist *t, int n)
{
    node *a = t->head;

    while (a != 0)
    {
        if ((a->data).roll == n)
        {
            break;
        }
        a = a->next;
    }

    return a;
}

//! Function to search name wise

node *searchname(stulist *t, char *q)
{
    node *a = t->head;

    while (a != 0)
    {
        if (strcmp(q, (a->data).nm) == 0)
        {
            break;
        }
        a = a->next;
    }

    return a;
}

//! Function to create a new student data

void add(stulist *t)
{
    node *a = t->head;
    node *b;

    b = (node *)malloc(sizeof(node));

    int r;

    printf("Enter the roll number of the student: ");
    scanf("%d", &(b->data).roll);

    a = searchroll(t, (b->data).roll);

    if (a != 0)
    {
        printf("\nData Exist");
        return;
    }

    printf("Enter the name of the student: ");
    scanf("%s", (b->data).nm);
    printf("Enter the marks of the student: ");
    scanf("%d", &(b->data).m);
    (b->data).flag = 1;

    b->next = t->head;
    t->head = b;
    t->cnt = t->cnt + 1;

    printf("\nRecord Added");
}

//! Function to modify data

void modify(stulist *t)
{
    node *a;
    int r;

    printf("Enter the roll number of the student: ");
    scanf("%d", &r);

    a = searchroll(t, r);

    if (a == 0)
    {
        printf("\nData does not Exist");
        return;
    }

    if ((a->data).flag == 0)
    {
        printf("\nDeleted Record");
        return;
    }

    printf("\nName: ");
    scanf("%s", (a->data).nm);
    printf("\nMarks: ");
    scanf("%d", &(a->data).m);
}

//! Function to delete a specific record

void del(stulist *t)
{
    node *a = t->head;
    int r;

    printf("\nEnter the record: ");
    scanf("%d", &r);

    a = searchroll(t, r);

    if (a == 0)
    {
        printf("\nRecord does not Exist");
        return;
    }

    if ((a->data).flag == 0)
    {
        printf("\nRecord already deleted");
        return;
    }

    (a->data).flag = 0;
}

//! Function to display the whole list

void display(stulist *t)
{
    node *a = t->head;

    if (t->head == 0)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nStudetn List \n");

        while (a != 0)
        {
            printf("%5d %15s %3d %d", (a->data).roll, (a->data).nm, (a->data).m, (a->data).flag);
            printf("\n");
            a = a->next;
        }
    }
}

//! We use binary file because the length of data may vary from record to record in text file which does not happen in binary file
//! Function to store data in binary file

void toFile(stulist *t)
{
    FILE *fs;
    student d;
    node *a = t->head;

    fs = fopen("stu.dat", "wb");

    while (a != 0)
    {
        d = a->data;
        fwrite(&d, sizeof(student), 1, fs);
        a = a->next;
    }

    fclose(fs);
}

//! Function to create list from file

void fromFile(stulist *t)
{
    node *a, *b;
    student d;
    FILE *fp;

    fp = fopen("stu.dat", "rb");

    if (fp == NULL)
    {
        printf("File Not Found");
        return;
    }

    if (t->head != 0)
    {
        while (t->head != 0)
        {
            a = t->head;
            t->head = a->next;
            free(a);
        }
        t->cnt = 0;
    }

    while (1)
    {
        fread(&d, sizeof(student), 1, fp);

        if (feof(fp))
        {
            break;
        }

        a = (node *)malloc(sizeof(node));
        a->data = d;
        a->next = t->head;
        t->head = a;
        t->cnt = t->cnt + 1;
    }

    fclose(fp);
}

int main()
{
    int d;
    stulist p;
    init(&p);

    while (1)
    {
        printf("\nMenu\n1. Add\n2. Modify\n3. Delete\n4. Display\n5. To file\n6. From file\n7. Exit\nEnter Option: ");
        scanf("%d", &d);

        if (d == 7)
        {
            break;
        }
        else
        {
            switch (d)
            {
            case 1:
                add(&p);
                break;
            case 2:
                modify(&p);
                break;
            case 3:
                del(&p);
                break;
            case 4:
                display(&p);
                break;
            case 5:
                toFile(&p);
                break;
            case 6:
                fromFile(&p);
                break;
            default:
                break;
            }
        }
    }

    return 0;
}
