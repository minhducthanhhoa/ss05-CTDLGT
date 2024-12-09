#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Loi cap ph�t bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m phan tu v�o cuoi danh s�ch
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// H�m x�a mot phan tu tai vi tr� chi dinh
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Danh s�ch li�n ket rong. Kh�ng the x�a.\n");
        return;
    }

    struct Node* temp = *head;

    // X�a phan tu dau danh s�ch
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Tim phan tu ngay truoc vi tr� can x�a
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Vi tr� kh�ng hop le\n");
            return;
        }
        temp = temp->next;
    }

    // Neu vi tr� vuot qu� pham vi
    if (temp->next == NULL) {
        printf("Vi tr� kh�ng hop le\n");
        return;
    }

    // X�a phan tu tai vi tr� chi dinh
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// H�m hien thi danh s�ch li�n ket
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Danh s�ch li�n ket rong.\n");
        return;
    }
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

// H�m x�a to�n bo danh s�ch de giai ph�ng bo nho 
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Tao danh s�ch li�n ket: 10 -> 20 -> 30 -> 40
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    printf("Danh s�ch ban dau: ");
    printList(head);

    // X�a tai vi tr� 2
    printf("X�a tai vi tr� 2:\n");
    deleteAtPosition(&head, 2);
    printList(head);

    // X�a tai v? tr� 0
    printf("X�a tai vi tr� 0:\n");
    deleteAtPosition(&head, 0);
    printList(head);

    // X�a tai vi tr� 5 (kh�ng hop le)
    printf("X�a tai vi tr� 5:\n");
    deleteAtPosition(&head, 5);
    printList(head);

    // Giai ph�ng bo nho 
    freeList(&head);
    return 0;
}

