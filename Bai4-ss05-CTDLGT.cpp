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

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Danh sách r?ng\n");
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

    int count = countNodes(head);

    if (count == 0) {
        printf("Danh sách rong\n");
    } else {
        printf("So luong phan tu trong danh sách: %d\n", count);
    }

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

