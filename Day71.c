#include <stdio.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int key, int m) {
    int index = hash(key, m);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }

    // table full case (optional)
    printf("Hash table is full\n");
}

void search(int table[], int key, int m) {
    int index = hash(key, m);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);   // size of hash table
    scanf("%d", &q);   // number of operations

    int table[m];

    // initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {        // INSERT
            insert(table, key, m);
        } else if (op[0] == 'S') { // SEARCH
            search(table, key, m);
        }
    }

    return 0;
}