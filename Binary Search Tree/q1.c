//! Header to create binary search tree and sort it

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int roll, flg;
    struct NODE *left;
    struct NODE *right;
} node;

typedef struct BST
{
    node *rt;   //* root node
    node *prnt; //* parent node
    node *curr; //* current node, used for deletion
} bst;

void init(bst *t)
{
    t->rt = t->prnt = t->curr = NULL;
}

node *createnode(int d)
{
    node *a = (node *)malloc(sizeof(node));
    a->left = a->right = NULL;
    a->roll = d;
    a->flg = 0;
    return a;
}

//*preorder method
void preorder(node *a)
{
    if (a != NULL)
    {
        printf("%5d", a->roll); //* printf acts like visiting the root in root-left-right
        preorder(a->left);
        preorder(a->right);
    }
    else
    {
        return;
    }
}

//*inorder method
void inorder(node *a)
{
    if (a != NULL)
    {
        inorder(a->left);
        printf("%5d", a->roll); //* printf acts like visiting the root in left-root-right
        inorder(a->right);
    }
    else
    {
        return;
    }
}

//*postorder method
void postorder(node *a)
{
    if (a != NULL)
    {
        postorder(a->left);
        postorder(a->right);
        printf("%5d", a->roll); //*printf acts like visiting the root in left-right-root
    }
    else
    {
        return;
    }
}

//* method to create the binary tree
void createtree(bst *t)
{
    node *a, *b;
    int d;

    while (1)
    {
        printf("\nEnter Tree Data: ");
        scanf("%d", &d);

        if (d == 0)
        {
            break;
        }

        if (t->rt == NULL)
        {
            t->rt = createnode(d);
        }
        else
        {
            a = t->rt;
            while (1)
            {
                if (d < a->roll)
                {
                    if (a->left == NULL)
                    {
                        b = createnode(d);
                        a->left = b;
                        break;
                    }
                    else
                    {
                        a = a->left;
                    }
                }
                else
                {
                    if (a->right == NULL)
                    {
                        b = createnode(d);
                        a->right = b;
                        break;
                    }
                    else
                    {
                        a = a->right;
                    }
                }
            }
        }
    }
}

//! Function to search Data from BST, return 1 if found else return 0

int search(bst *p, int sv)
{
    int flg = 0;
    node *a = p->rt;

    while (a != NULL)
    {
        if (a->roll == sv)
        {
            p->curr = a;
            flg = 1;
            break;
        }
        if (a->roll > sv)
        {
            if (a->left == NULL)
            {
                break;
            }
            p->prnt = a;
            a = a->left;
        }
        else
        {
            if (a->right == NULL)
            {
                break;
            }
            p->prnt = a;
            a = a->right;
        }
    }

    return flg;
}

void del(bst *t)
{
    int sv, res;
    node *p, *q, *a, *b;

    printf("\nEnter Node Data: ");
    scanf("%d", &sv);

    res = search(t, sv);

    if (res == 0)
    {
        printf("\nData Not Found");
        return;
    }

    a = t->curr, b = t->prnt;

    //* leaf node deletion
    if (a->left == NULL && a->right == NULL)
    {
        if (b->left == a) //* left leaf node
        {
            b->left = NULL;
        }
        else //* right leaf node
        {
            b->right = NULL;
        }
    }

    //* node wtih both childs
    if (a->left != NULL && a->right != NULL)
    {
        if (b->left == a)
        {
            p = a->right;
            while (p != NULL)
            {
                q = p;
                p = p->left;
            }

            q->left = a->left;
            b->left = a->right;
        }
        else
        {
            p = a->left;
            while (p != NULL)
            {
                q = p;
                p = p->right;
            }
            q->right = a->right;
            b->right = a->left;
        }
    }

    //* deletion of left child
    if (b->left == a)
    {
        if (a->right == NULL)
        {
            b->left = a->left;
        }
        else
        {
            b->left = a->right;
        }
    }

    //* deletion of right child
    if (b->right == a)
    {
        if (a->left == NULL)
        {
            b->right = a->right;
        }
        else
        {
            b->right = a->left;
        }
    }

    free(a);
}

int main()
{
    bst t;
    int opt, sv;

    init(&t);

    while (1)
    {
        printf("\n1. Create Tree\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Delete Node\n7. Exit\nEnter Option: ");
        scanf("%d", &opt);

        if (opt > 6)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                createtree(&t);
                break;
            case 2:
                preorder(t.rt);
                break;
            case 3:
                inorder(t.rt);
                break;
            case 4:
                postorder(t.rt);
                break;
            case 5:
                printf("\nEnter Search Value: ");
                scanf("%d", &sv);

                if (search(&t, sv) == 0)
                {
                    printf("\nNot Found");
                }
                else
                {
                    printf("\nFound");
                }
            case 6:
                del(&t);
                break;
            }
        }
    }

    return 0;
}