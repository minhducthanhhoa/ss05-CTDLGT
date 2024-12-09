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

// Hàm duyet danh sách tu cuoi ve dau và in ra giá tri
void printReverse(struct Node* head) {
    if (head == NULL) {
        printf("Danh sách rong.\n");
        return;
    }

    // Duyet den phan tu cuoi cùng
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Duyet nguoc tu cuoi ve dau
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) {
            printf(" <-> ");
        }
        temp = temp->prev;
    }
    printf(" <-> NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu trong danh sách: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sách sau khi duyet nguoc:\n");
    printReverse(head);  

    // Giai phóng bo nho
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

