#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node
{
    struct Node* prev;
    int val;
    struct Node* next;
};

// Function to insert a node at the end
struct Node* addlastdoubly(struct Node* root, int v)
{
    struct Node *nw, *start;

    nw = (struct Node*)malloc(sizeof(struct Node));
    nw->val = v;

    if (root == NULL)
    {
        nw->next = NULL;
        nw->prev = NULL;
        root = nw;
    }
    else
    {
        start = root;
        while (start->next != NULL)
        {
            start = start->next;
        }

        start->next = nw;
        nw->prev = start;
        nw->next = NULL;
    }

    return root;
}

// Function to display the list
void display(struct Node* root)
{
    struct Node* temp = root;

    if (root == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d", temp->val);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

// Main function
int main()
{
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter value of node %d: ", i);
        scanf("%d", &value);

        root = addlastdoubly(root, value);
    }

    printf("\n");
    display(root);

    return 0;
}