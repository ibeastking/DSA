#include <bits\stdc++.h>

using namespace std;

typedef struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
} node;

struct NODE *root;
struct NODE *parent;
struct NODE *current;

void init()
{
    root = parent = current = NULL;
}

node *createnode(int d)
{
    node *a = new (node);
    a->data = d;
    a->left = a->right = NULL;
    return a;
}

//* node *a in the below function depicts root node
void preorder(node *a)
{
    if (a != NULL)
    {
        printf("%d ", a->data);
        preorder(a->left);
        preorder(a->right);
    }
    else
    {
        return;
    }
}

void inorder(node *a)
{
    if (a != NULL)
    {
        inorder(a->left);
        printf("%d ", a->data);
        inorder(a->right);
    }
    else
    {
        return;
    }
}

void postorder(node *a)
{
    if (a != NULL)
    {
        postorder(a->left);
        postorder(a->right);
        printf("%d ", a->data);
    }
    else
    {
        return;
    }
}

void createtree()
{
    int d;

    while (1)
    {
        cout << "Enter Node Data: ";
        cin >> d;

        if (d == 0)
        {
            break;
        }
        if (root == NULL)
        {
            root = createnode(d);
        }
        else
        {
            node *a, *b;
            a = root;

            while (1)
            {
                if (a->data > d)
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

int search(node *a, int sv)
{
    while (a != NULL)
    {
        if (a->data > sv)
        {
            if (a->left == NULL)
            {
                break;
            }
            parent = a;
            a = a->left;
        }
        if (a->data < sv)
        {
            if (a->right == NULL)
            {
                break;
            }
            parent = a;
            a = a->right;
        }

        if (a->data == sv)
        {
            current = a;
            return 1;
        }
    }

    return 0;
}

void del(node *q)
{
    int d;
    cout << "\nEnter Node data: ";
    cin >> d;

    if (search(q, d) == 0)
    {
        cout << "\nNo such Data Exists";
        return;
    }

    node *c = current;
    node *p = parent;
    node *a, *b;

    if (c->left == NULL && c->right == NULL)
    {
        if (p->left == c)
        {
            p->left = NULL;
            delete (c);
        }
        if (p->right == c)
        {
            p->right = NULL;
            delete (c);
        }

        return;
    }

    if (p->left == c)
    {
        if (c->left == NULL)
        {
        }
    }

    if (c->left == NULL && c->right != NULL)
    {
    }
}

void disleft(node *a)
{
    node *b = root;
    if (a != NULL)
    {
        inorder(a->left);
        if (a->data < b->data)
        {
            printf("%d ", a->data);
        }
        inorder(a->right);
    }
    else
    {
        return;
    }
}

void disright(node *a)
{
    node *b = root;

    if (a != NULL)
    {
        inorder(a->left);
        if (a->data > b->data)
        {
            printf("%d ", a->data);
        }
        inorder(a->right);
    }
    else
    {
        return;
    }
}

int main()
{
    int opt;
    init();

    while (1)
    {
        cout << "\nTree Menu\n1. Create Tree\n2. Preorder\n3. Inorder\n4. Postorder\n5. Display Left Children\n6. Display Right Children"
             << "\n7. Search\n8. Exit\nEnter Option: ";
        cin >> opt;

        if (opt >= 8)
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
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                disleft(root);
                break;
            case 6:
                disright(root);
                break;
            case 7:
                cout << "\nEnter Node data: ";
                int d;
                cin >> d;

                if (search(root, d) == 1)
                {
                    cout << "\nData Exists";
                }
                else
                {
                    cout << "\nData does not Exists";
                }
                break;
            }
        }
    }

    return 0;
}