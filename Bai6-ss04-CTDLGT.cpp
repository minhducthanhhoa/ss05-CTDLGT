#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Loi cap phát bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phan tu vào cuoi danh sách
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

// Hàm xóa mot phan tu tai vi trí chi dinh
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sách liên ket rong. Không the xóa.\n");
        return;
    }

    struct Node* temp = *head;

    // Xóa phan tu dau danh sách
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Tim phan tu ngay truoc vi trí can xóa
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Vi trí không hop le\n");
            return;
        }
        temp = temp->next;
    }

    // Neu vi trí vuot quá pham vi
    if (temp->next == NULL) {
        printf("Vi trí không hop le\n");
        return;
    }

    // Xóa phan tu tai vi trí chi dinh
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Hàm hien thi danh sách liên ket
void printList(struct Node* head) {
    if (head == NULL) {
        printf("Danh sách liên ket rong.\n");
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

// Hàm xóa toàn bo danh sách de giai phóng bo nho 
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

    // Tao danh sách liên ket: 10 -> 20 -> 30 -> 40
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    printf("Danh sách ban dau: ");
    printList(head);

    // Xóa tai vi trí 2
    printf("Xóa tai vi trí 2:\n");
    deleteAtPosition(&head, 2);
    printList(head);

    // Xóa tai v? trí 0
    printf("Xóa tai vi trí 0:\n");
    deleteAtPosition(&head, 0);
    printList(head);

    // Xóa tai vi trí 5 (không hop le)
    printf("Xóa tai vi trí 5:\n");
    deleteAtPosition(&head, 5);
    printList(head);

    // Giai phóng bo nho 
    freeList(&head);
    return 0;
}

