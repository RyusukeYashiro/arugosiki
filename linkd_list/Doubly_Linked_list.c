#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct ListNode 
{
    int data;
    struct ListNode *next;
    struct ListNode *pre;
};


struct ListNode *create(int data)
{
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode -> data = data;
    return (newNode);
}

void insertHead(struct ListNode **head , int data)
{
    struct ListNode *newNode = create(data);
    newNode -> next = *head;
    newNode -> pre = NULL;
    if(*head != NULL)
        (*head) -> pre = newNode;
    *head = newNode;
}

void insertTail(struct ListNode **head , int data)
{
    struct ListNode *newNode = create(data);
    newNode -> next = NULL;
    if(*head == NULL)
    {
        newNode -> pre = NULL;
        *head = newNode;
        return;
    }

    struct ListNode *temp = *head;
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = newNode;
    newNode -> pre = temp;
}

void insetPosition(struct ListNode **head , int data , int position)
{
    struct ListNode *newNode = create(data);
    if(position == 1)
    {
        insertHead(head ,data);
        return;
    }
    struct ListNode *temp = *head;
    for(int i = 1; temp != NULL && i < position -1; i++)
        temp = temp -> next;
    if(temp == NULL)
        return;
    newNode -> next = temp -> next;
    newNode -> pre = temp;
    if(temp -> next != NULL)
        temp -> next -> pre = newNode;
    temp -> next = newNode;
}

void PrintList(struct ListNode *head)
{
    struct ListNode *temo = head;
    while(temo -> next != NULL)
    {
        printf("%d -> " , temo -> data);
       temo = temo -> next;
    }
    printf("NULL\n");
}

void deleteHead(struct ListNode **head)
{
    if(*head == NULL)
        return;
    struct ListNode *temp = *head;
    *head = temp -> next;
    if(*head != NULL)
    {
        (*head) -> pre = NULL;
    }
    free(temp);
}

void deleteTail (struct ListNode **head)
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
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> pre -> next = NULL;
    free(temp);
}

void deletePosition(struct ListNode **head , int position)
{
    if(*head == NULL)
        return;
    if(position == 1)
    {
        deleteHead(head);
        return;
    }

    struct ListNode *temp = *head;
    for(int i = 1; temp != NULL && i < position; i++)
        temp = temp -> next;
    if(temp == NULL)
        return;
    if(temp -> next != NULL)
        temp -> next -> pre = temp -> pre;
    if(temp -> pre != NULL)
        temp -> pre -> next = temp -> next;
    free(temp);
}

int main()
{
    struct ListNode *head = NULL;

    insertHead(&head , 10); // 10 -> NULL;
    insertTail(&head , 20); // 10 -> 20 -> NULL;
    insertTail(&head , 30); // 10 -> 20 -> 30 -> NULL;
    insetPosition(&head , 15 , 2); // 10 -> 15 -> 20 -> 30 -> NULL;

    // リストを表示
    printf("Original List: ");
    PrintList(head);

    // リストの末尾を削除
    deleteTail(&head);
    printf("List after deleting tail: ");
    PrintList(head);

    // リストの先頭を削除
    deleteHead(&head);
    printf("List after deleting head: ");
    PrintList(head);

    // リストの特定の位置を削除
    deletePosition(&head, 2);
    printf("List after deleting at position 2: ");
    PrintList(head);
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
