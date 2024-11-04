#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// funcao para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// funcao para adicionar um nó ao final da lista
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// funcao para imprimir a lista
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// funcao para criar o bubble sort
void bubbleSortLinkedList(struct Node* head) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (head == NULL) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// funcao para criar o insertion sort
void insertionSortLinkedList(struct Node** head) {
    struct Node* sorted = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

// funcao auxiliar para o merge sort
struct Node* sortedMerge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void splitList(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// funcao para criar o merge sort
void mergeSortLinkedList(struct Node** head) {
    struct Node* h = *head;
    struct Node* a;
    struct Node* b;

    if (h == NULL || h->next == NULL) return;

    splitList(h, &a, &b);

    mergeSortLinkedList(&a);
    mergeSortLinkedList(&b);

    *head = sortedMerge(a, b);
}

// funcao auxiliar para o quick sort
struct Node* getTail(struct Node* cur) {
    while (cur != NULL && cur->next != NULL) cur = cur->next;
    return cur;
}

struct Node* partitionLast(struct Node* start, struct Node* end, struct Node** newHead, struct Node** newEnd) {
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = start, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL) *newHead = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            struct Node* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == NULL) *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

struct Node* quickSortRecur(struct Node* start, struct Node* end) {
    if (!start || start == end) return start;

    struct Node *newHead = NULL, *newEnd = NULL;

    struct Node* pivot = partitionLast(start, end, &newHead, &newEnd);

    if (newHead != pivot) {
        struct Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);

        temp = newHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSortLinkedList(struct Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

int main() {
    struct Node* originalList = NULL;
    appendNode(&originalList, 64);
    appendNode(&originalList, 34);
    appendNode(&originalList, 25);
    appendNode(&originalList, 12);
    appendNode(&originalList, 22);
    appendNode(&originalList, -10);
    appendNode(&originalList, 222);
    appendNode(&originalList, 4252);
    appendNode(&originalList, -3222);

    printf("Lista Original: ");
    printList(originalList);

    // copiar lista para bubble sort
    struct Node* bubbleList = NULL;
    struct Node* temp = originalList;
    while (temp != NULL) {
        appendNode(&bubbleList, temp->data);
        temp = temp->next;
    }
    bubbleSortLinkedList(bubbleList);
    printf("Bubble Sort: ");
    printList(bubbleList);

    // copiar lista para insertion sort
    struct Node* insertionList = NULL;
    temp = originalList;
    while (temp != NULL) {
        appendNode(&insertionList, temp->data);
        temp = temp->next;
    }
    insertionSortLinkedList(&insertionList);
    printf("Insertion Sort: ");
    printList(insertionList);

    // copiar lista para merge sort
    struct Node* mergeList = NULL;
    temp = originalList;
    while (temp != NULL) {
        appendNode(&mergeList, temp->data);
        temp = temp->next;
    }
    mergeSortLinkedList(&mergeList);
    printf("Merge Sort: ");
    printList(mergeList);

    // copiar lista para quick sort
    struct Node* quickList = NULL;
    temp = originalList;
    while (temp != NULL) {
        appendNode(&quickList, temp->data);
        temp = temp->next;
    }
    quickSortLinkedList(&quickList);
    printf("Quick Sort: ");
    printList(quickList);

    return 0;
}
