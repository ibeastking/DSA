#include <bits\stdc++.h>
using namespace std;

typedef struct DATA
{
    int roll;
    char nm[50];
    double mrk;
} data;

typedef struct SNODE
{
    data d;
    struct SNODE *next;
} snode;

typedef struct DNODE
{
    data d;
    struct DNODE *next;
    struct DNODE *prev;
} dnode;

class slink
{
    snode *head = NULL;

public:
    int search(int n)
    {
        snode *a = head;
        int p = 0;

        while (a != NULL)
        {
            if ((a->d).roll == n)
            {
                return p;
            }
            else
            {
                p++;
                a = a->next;
            }
        }

        return 0;
    }

    snode *createnode(int n)
    {
        snode *a;
        a = new snode;
        (a->d).roll = n;
        cout << "Enter Name: ";
        cin >> (a->d).nm;
        cout << "Enter Marks: ";
        cin >> (a->d).mrk;
        a->next = NULL;

        return a;
    }

    void addbeg()
    {
        int n;
        cout << "\nEnter Roll Number: ";
        cin >> n;

        while (1)
        {
            if (search(n) == 0)
            {
                snode *a = createnode(n);

                if (head == NULL)
                {
                    head = a;
                    return;
                }

                a->next = head;
                head = a;

                break;
            }
            else
            {
                cout << "\nStudent with this Number already exists";
            }
        }
    }

    void addend()
    {
        int n;
        cout << "\nEnter Roll Number: ";
        cin >> n;

        while (1)
        {
            if (search(n) == 0)
            {
                snode *a = head;
                while (a != NULL)
                {
                    a = a->next;
                }

                snode *b;
                b = createnode(n);
                a->next = b;

                break;
            }
            else
            {
                cout << "\nStudent with this Number already exists";
            }
        }
    }

    void display()
    {
        snode *a = head;

        while (a != NULL)
        {
            cout << "\nStudent Data\nRoll Number: " << (a->d).roll << "\nName: " << (a->d).nm << "\nMarks: " << (a->d).mrk;
            a = a->next;
        }
    }

    void dissingle(int n)
    {
        snode *a;
        a = head;

        if (a->next == NULL)
        {
            cout << "\nStudent Data\nRoll Number: " << (a->d).roll << "\nName: " << (a->d).nm << "\nMarks: " << (a->d).mrk;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            a = a->next;
        }

        cout << "\nStudent Data\nRoll Number: " << (a->d).roll << "\nName: " << (a->d).nm << "\nMarks: " << (a->d).mrk;
    }

    void delbyroll()
    {
        snode *a = head;
        snode *b;
        int n;

        cout << "\nEnter Roll Number to Delete: ";
        cin >> n;

        while (a != NULL)
        {
            if ((a->d).roll == n)
            {
                if (a == head)
                {
                    snode *b = a->next;
                    head = b;
                    free(a);
                    cout << "\nData Deleted";
                    return;
                }

                if (a->next == NULL)
                {
                    b->next = NULL;
                    free(a);
                    cout << "\nData Deleted";
                    return;
                }

                b->next = a->next;
                free(a);
                cout << "\nData Deleted";
                return;
            }
            b = a;
            a = a->next;
        }

        if (a == NULL)
        {
            cout << "\nStudent with this Roll Number does not exist.";
        }
    }
};

int main()
{
    slink s;
    while (1)
    {
        cout << "\nMenu\nSingle Link List\n1. Add at Beginning\n2. Add at Ending\n3. Display\n4. Delete Data\n5. Search for Data\n6. Exit\nEnter Option: ";
        int opt;
        cin >> opt;

        if (opt > 5)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                s.addbeg();
                break;
            case 2:
                s.addend();
                break;
            case 3:
                s.display();
                break;
            case 4:
                s.delbyroll();
                break;
            case 5:
                int sv;
                cout << "\nEnter Search Value: ";
                cin >> sv;

                if (s.search(sv) == 0)
                {
                    cout << "\nNo such Data exists";
                }
                else
                {
                    s.dissingle(s.search(sv));
                }
                break;
            }
        }
    }

    return 0;
}