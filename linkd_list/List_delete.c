#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int data;
    struct ListNode *next;
};


struct ListNode *create(int data)
{
    struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newnode -> data = data;
    newnode -> next = NULL;
    return (newnode);
}

void insertHead(struct ListNode **head , int data)
{
    struct ListNode *newnode = create(data);
    newnode -> next = *head;
    *head = newnode;
}

void insertTail(struct ListNode **head , int data)
{
    struct ListNode *newnode = create(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct ListNode *temp = *head;
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = newnode;
}

void insertPosition(struct ListNode **head , int data , int position)
{
    if(position == 1)
    {
        insertHead(head, data);
        return;
    }
    struct ListNode *newnode = create(data);
    struct ListNode *temp = *head;
    for(int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp -> next;
    }
    if(temp == NULL || temp -> next == NULL)
        return;
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void deleteAtHead(struct ListNode **head)
{
    if(*head == NULL)
        return;
    struct ListNode *temp = *head;
    *head = (*head) -> next;
    free(temp);
}

void deleteAtTail(struct ListNode **head)
{
    if(*head == NULL)
        return;
    if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct ListNode *temp = *head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
}

void deleteAtPosition(struct ListNode **head , int position)
{
    if(*head == NULL)
        return;
    if(position == 1)
    {
        deleteAtHead(head);
        return;
    }
    struct ListNode *temp = *head;
    for(int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp -> next;
    if(temp == NULL || temp -> next == NULL)
        return;
    struct ListNode *deleteNode = temp -> next;
    temp -> next = deleteNode -> next;
    free(deleteNode);
}

void printList(struct ListNode *head)
{
    struct ListNode *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}



int main()
{
    struct ListNode *head = NULL;

    insertHead(&head , 10); // 10 -> NULL;
    insertTail(&head , 20); // 10 -> 20 -> NULL;
    insertTail(&head , 30); // 10 -> 20 -> 30 -> NULL;
    insertPosition(&head , 15 , 2); // 10 -> 15 -> 20 -> 30 -> NULL;

    // リストを表示
    printf("Original List: ");
    printList(head);

    // リストの末尾を削除
    deleteAtTail(&head);
    printf("List after deleting tail: ");
    printList(head);

    // リストの先頭を削除
    deleteAtHead(&head);
    printf("List after deleting head: ");
    printList(head);

    // リストの特定の位置を削除
    deleteAtPosition(&head, 2);
    printf("List after deleting at position 2: ");
    printList(head);
    return (0);

    struct ListNode *temp;
    while(head != NULL)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
    return (0);
}
