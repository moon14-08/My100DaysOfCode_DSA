#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i;
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("List is empty.\n");
        return 0;
    }

    printf("Enter %d elements: ", n);

    for (i = 0; i < n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    temp->next = head;

    // Traversal
    printf("Circular Linked List: ");
    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    while (temp != head);

    return 0;
}