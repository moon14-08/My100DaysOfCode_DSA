#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, value;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        pop();
    }

    printf("Remaining stack elements (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}