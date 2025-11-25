#include <stdio.h>

void show(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5, pos, key, cap = 100, i;

    printf("Array: ");
    show(arr, n);


    key = 30;
    for (i = 0; i < n && arr[i] != key; i++);
    if (i < n)
        printf("Found %d at index %d\n", key, i);
    else
        printf("%d Not found\n", key);

    pos = 2;
    if (n < cap) {
        for (i = n; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = 60;
        n++;
    }
    printf("After insertion: ");
    show(arr, n);

    pos = 3;
    if (pos >= 0 && pos < n) {
        for (i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
    }
    printf("After deletion: ");
    show(arr, n);

    return 0;
}

