#include <stdio.h>


// criando a funcao para o bubble sort
void BubbleSort(int B[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (B[j] > B[j + 1]) {
                int temp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = temp;
            }
        }
    }
}

// criando a funcao para o insertion sort
void InsertionSort(int I[], int n) {
    for (int i = 1; i < n; i++) {
        int c = I[i];
        int j = i - 1;

        while (j >= 0 && I[j] > c) {
            I[j + 1] = I[j];
            j = j - 1;
        }
        I[j + 1] = c;
    }
}

//criando a funcao para o merge sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//criando a funcao para o quick sort
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, -1, 90, 142, 482, 83, 720, 800, 992};
    int n = sizeof(arr) / sizeof(arr[0]);

    // criando copias da lista original
    int bubbleArr[n], insertionArr[n], mergeArr[n], quickArr[n];
    for (int i = 0; i < n; i++) {
        bubbleArr[i] = arr[i];
        insertionArr[i] = arr[i];
        mergeArr[i] = arr[i];
        quickArr[i] = arr[i];
    }

    // aplicando cada algoritmo de ordenação e imprimindo o resultado
    BubbleSort(bubbleArr, n);
    printf("Array ordenado com Bubble Sort: ");
    printArray(bubbleArr, n);

    InsertionSort(insertionArr, n);
    printf("Array ordenado com Insertion Sort: ");
    printArray(insertionArr, n);

    mergeSort(mergeArr, 0, n - 1);
    printf("Array ordenado com Merge Sort: ");
    printArray(mergeArr, n);

    quickSort(quickArr, 0, n - 1);
    printf("Array ordenado com Quick Sort: ");
    printArray(quickArr, n);

    return 0;
}
