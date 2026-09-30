#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node *root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node* minValueNode(struct Node *root)
{
    struct Node *current = root;

    while(current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node *root, int key)
{
    struct Node *temp;

    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        /* No left child */
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        /* No right child */
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Two children */
        temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");

    if(search(root, 40) != NULL)
        printf("40 found\n");
    else
        printf("40 not found\n");

    root = deleteNode(root, 70);

    printf("Inorder after deletion: ");
    inorder(root);

    return 0;
}