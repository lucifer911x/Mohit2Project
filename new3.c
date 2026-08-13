#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int val;
    struct node *next;
};
int main()
{
    char ans = 'Y';
    struct node *root,*nw,*start;
    root=nw=start=NULL;
    int v;
    while(ans == 'Y' || ans == 'y')
    {
        nw = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value for the new node: ");
        scanf("%d", &v);
        nw->val = v;
        nw->next = NULL;
        if(root == NULL)
            root = nw;
        else
        {
            start=root;
            while(start->next != NULL)
                start = start->next;
            start->next = nw;
        }
        start = root;
        while (start != NULL)
        {
            printf("%d -> ", start->val);
            start = start->next;
        }
        printf("Do you want to add another node? (Y/y): ");
        ans = getche();
    }
    return 0;
}