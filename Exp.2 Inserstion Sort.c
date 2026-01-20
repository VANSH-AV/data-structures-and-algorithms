#include <stdio.h>

void insertionSort(int a[], int n) {
    //write your code here...
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i]; // The element to be inserted
        j = i - 1;

        /* Move elements of a[0..i-1] that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    
    
    
}

int main() {
    int a[20], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
