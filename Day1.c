//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space
#include <stdio.h>
int main() {
    int n, pos, x;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    for (int i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = x;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
