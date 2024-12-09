#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Hàm thêm mot nút vào cuoi danh sách liên ket ðôi
void append(struct Node** head, int data) {
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
    newNode->prev = temp;
}

// Hàm chèn phan tu vào danh sách tai vi trí chi dinh
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int index = 0;

    // Neu vi trí yêu cau chèn vào dau danh sách (vi trí 0)
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Duyet danh sách de tim vi trí chèn
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    // Neu vi trí không hop le
    if (temp == NULL) {
        printf("Loi vi trí không hop le\n");
        free(newNode);
        return;
    }

    // Chèn phan tu vào danh sách tai vi trí chi dinh
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Hàm duyet danh sách và in ra các phan tu
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, position;

    printf("Nhap so luong phan tu trong danh sách: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sách ban dau:\n");
    printList(head);

    // Nhap giá tri và vi trí can chèn
    printf("Giá tri can chèn: ");
    scanf("%d", &value);
    printf("Vi trí can chèn: ");
    scanf("%d", &position);

    // Chèn phan tu vào danh sách tai vi trí chi dinh
    insertAtPosition(&head, value, position);

    printf("Danh sách sau khi chèn:\n");
    printList(head);

    // Giai phóng b?o nho
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

