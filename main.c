#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int searchNode(Node* head, int key) {
    Node* temp = head;
    int i = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return 0;
}

Node * insertByIndex(Node *head, int number) {
    int index;
    printf("Vi tri muon them la: ");
    scanf("%d", &index);
    printf("vi tri da chen la %d", index);
    printf("\n");

    if (head != NULL) {
        Node *temp = head;
        int i = 0;
        while (temp != NULL) {
            // 9 5 10 11
            if (i == index - 1) {
                if (temp -> next == NULL) {
                    temp -> next = createNode(number);
                    break;
                }else {
                    Node *newNode = createNode(number);
                    newNode -> next = temp -> next;
                    temp -> next = newNode;
                }
            }
            temp = temp -> next;
            i++;
        }
    }
    printf("\n");
    return NULL;
}

void printLL(Node* head) {
    int i =0;
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
}

int main(void) {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // printf("%d ", head->data);


    // int key;
    // printf("nhap so muon tim kiem: ");
    // scanf("%d", &key);
    //
    // if (searchNode(head, key)) {
    //     printf("true");
    // } else {
    //     printf("false");
    // }

    // printf("\nDSLK co %d phan tu", i);

    printLL(head);

    int num;
    printf("nhap gia tri muon chen");
    scanf("%d", &num);

    insertByIndex(head, num);

    printLL(head);


    return 0;
}