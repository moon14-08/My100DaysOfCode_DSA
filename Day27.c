#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}


int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1; 
}

int main() {
    int n, m, val;

    printf("Enter size of first list: ");
    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    printf("Enter size of second list: ");
    scanf("%d", &m);

    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;

    printf("Enter %d elements: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);


        struct Node* temp = head1;
        int found = 0;
        while (temp != NULL) {
            if (temp->data == val) {
                if (head2 == NULL) {
                    head2 = temp;
                    tail2 = temp;
                } else {
                    tail2->next = temp;
                    tail2 = temp;
                }
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            struct Node* newNode = createNode(val);
            if (head2 == NULL) {
                head2 = newNode;
                tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    int result = findIntersection(head1, head2);
    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);

    return 0;
}
