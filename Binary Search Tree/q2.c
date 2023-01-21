//! Non-Recurrsive BST Traversal

#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree *left;
    int data, flg;
    struct tree *right;
} *rt = NULL;

struct stack
{
    int top;
    struct tree *arr[10];
} s;

//* Function to create node
struct tree *createnode(int d)
{
    struct tree *a;
    a = (struct tree *)malloc(sizeof(struct tree));
    a->data = d;
    a->left = a->right = NULL;
    a->flg = 0;
    return a;
}

//* Function to initialize the stack
void init()
{
    s.top = -1;
}

//* Function to push data in stack
void push(struct tree *a)
{
    s.top++;
    s.arr[s.top] = a;
}

//* Function to check if stack is empty or not
int isEmpty()
{
    return (s.top == -1);
}

//* Function to pop data from stack
struct tree *pop()
{
    return (s.arr[s.top--]);
}

//* Function to create a bst
void createtree()
{
    int d;
    struct tree *a, *b;

    while (1)
    {
        printf("\nEnter Data: ");
        scanf("%d", &d);

        if (d == 0)
        {
            break;
        }

        if (rt == NULL)
        {
            rt = createnode(d);
        }
        else
        {
            a = rt;

            while (1)
            {
                if (d < a->data)
                {
                    if (a->left != NULL)
                    {
                        a = a->left;
                    }
                    else
                    {
                        b = createnode(d);
                        a->left = b;
                        break;
                    }
                }
                else
                {
                    if (a->right != NULL)
                    {
                        a = a->right;
                    }
                    else
                    {
                        b = createnode(d);
                        a->right = b;
                        break;
                    }
                }
            }
        }
    }
}

//* preorder traversal
void preorder(struct tree *a)
{
    init();
    while (a != NULL || !isEmpty())
    {
        printf("%5d", a->data);
        if (a->right != NULL)
        {
            push(a->right);
        }
        a = a->left;

        if (a == NULL && !isEmpty())
        {
            a = pop();
        }
    }
}

//* inorder traversal
void inorder(struct tree *a)
{
    init();

    do
    {
        while (a != NULL)
        {
            push(a);
            a = a->left;
        }
        if (isEmpty())
        {
            a = pop();
            printf("%5d", a->data);
            a = a->right;
        }
    } while (a != NULL || !isEmpty());
}

//* postorder traversal
void postorder(struct tree *a)
{
    init();

    do
    {
        while (a != NULL && a->flg == 0)
        {
            push(a);
            a = a->left;
        }
        a = pop();
        if (a->flg == 0)
        {
            a->flg = 1;
            push(a);
            a = a->right;
        }
        else
        {
            printf("%5d", a->data);
        }
    } while (!isEmpty());
}

int main()
{
    int opt;

    while (1)
    {
        printf("Menu\n1. Create Tree\n2. Preorder\n3. Inorder\n4. Postorder\nEnter Option: ");
        scanf("%d", &opt);

        if (opt > 4)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                createtree();
                break;
            case 2:
                preorder(rt);
                break;
            case 3:
                inorder(rt);
                break;
            case 4:
                postorder(rt);
                break;
            }
        }
    }
}
