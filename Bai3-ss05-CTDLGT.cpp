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

// Hàm xóa phan tu cuoi cùng trong danh sách liên ket doi
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("Danh sách rong\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // Neu chi có mot phan tu trong danh sách
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    // Duyet den phan tu cuoi cùng
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Cap nhat con tro cua phan tu truoc phan tu cuoi
    temp->prev->next = NULL;
    
    // Giai phóng bo nho phan tu cuoi
    free(temp);
}

// Hàm duyet danh sách và in ra các phan tu
void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Danh sách rong\n");
        return;
    }
    
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
    int n, value;

    printf("Nhap so luong phan tu trong danh sách: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sách ban dau:\n");
    printList(head);

    // Xóa phan tu cuoi cùng
    deleteLast(&head);

    printf("Danh sách sau khi xóa phan tu cuoi:\n");
    printList(head);

    // Giai phóng bo nho
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

