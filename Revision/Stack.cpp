#include <bits\stdc++.h>
using namespace std;

class node
{
public:
    int val;
    class node *next;
};

class Stack
{
    struct node *top;

public:
    Stack()
    {
        top = NULL;
    }

    int empty()
    {
        return top ? 0 : 1;
    }

    int full()
    {
        node *a = new node;
        return a ? 0 : 1;
    }

    void push()
    {
        int d;
        cout << "\nEnter Stack Data: ";
        cin >> d;

        node *a = new node;
        a->val = d;
        a->next = NULL;

        if (top == NULL)
        {
            top = a;
        }
        else
        {
            a->next = top;
            top = a;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "\nStack is Empty";
        }
        else
        {
            node *a = top;
            node *b;

            b = a->next;
            top = b;
            free(a);
        }
    }

    void display()
    {
        node *a = top;

        if (top == NULL)
        {
            cout << "Empty Stack";
        }
        else
        {
            while (a != NULL)
            {
                cout << a->val << " ";
                a = a->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s;
    while (true)
    {
        cout << "\nStack Menu\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter Option: ";
        int opt;
        cin >> opt;

        if (opt > 3)
        {
            break;
        }
        switch (opt)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        }
    }

    return 0;
}