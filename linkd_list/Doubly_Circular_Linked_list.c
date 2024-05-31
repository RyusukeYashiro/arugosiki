#include <complex.h>
#include <iso646.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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
    if(*head == NULL)
    {
        newNode -> next = newNode;
        newNode -> pre = newNode;
        *head = newNode;
        return;
    }
    //最後のリストを習得。双方向循環リストのため、最初のノードのpreがリストの
    //最後のノードを指すことになる
    struct ListNode *last = (*head) -> pre;
    newNode -> next = *head;
    newNode -> pre = last;
    (*head) -> pre = newNode;
    last -> next = newNode;
    *head = newNode; 
}

void insertTail(struct ListNode **head , int data)
{
    struct ListNode *newNode = create(data);

    if(*head == NULL)
    {
        newNode -> next = newNode;
        newNode -> pre = newNode;
        *head =  newNode;
        return;
    }

    struct ListNode *last = (*head) -> pre;
    newNode -> next = *head;
    newNode -> pre = last;
    (*head) -> pre = newNode;
    last -> next = newNode;

}

void insertPosition(struct ListNode **head ,int position, int data)
{
    if(position == 1)
        insertHead(head,data);
    if(*head == NULL)
        return;
    struct ListNode *newNode = create(data);
    struct ListNode *temp = *head;
    for(int i = 1; temp -> next != *head && i < position - 1; i++)
        temp = temp -> next;
    newNode -> next = temp -> next;
    newNode -> pre = temp;
    temp -> next -> pre = newNode;
    temp -> next = newNode;
}

void deleteHead(struct ListNode **head)
{
    if(*head == NULL || (*head) -> next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct ListNode *last = (*head) -> pre;
    struct ListNode *temp = *head;

    last -> next = temp -> next;
    temp -> next -> pre = last;
    *head = temp -> next;
    free(temp);
}

void deleteTail(struct ListNode **head)
{
    if(*head == NULL || (*head) -> next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct ListNode *last = (*head) -> pre;

    last -> pre -> next = *head;
    (*head) -> pre = last -> pre;
    free(last);
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
    for(int i = 1; temp -> next != *head && i < position; i++)
        temp = temp -> next;
    if(temp == *head)
        return;
    temp -> pre -> next = temp -> next;
    temp -> next -> pre = temp -> pre;
   free(temp); 
}

void PrintList(struct ListNode *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
        return;
    }
    struct ListNode *temp = head;

    printf("%d -> ", temp -> data);
    temp = temp -> next;

    while(temp  != head)
    {
        printf("%d -> " , temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main(void)
{
    struct ListNode *head = NULL;

    insertHead(&head , 10); // 10 -> NULL;
    insertTail(&head , 20); // 10 -> 20 -> NULL;
    insertTail(&head , 30); // 10 -> 20 -> 30 -> NULL;
    insertPosition(&head , 15 , 2); // 10 -> 15 -> 20 -> 30 -> NULL;

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

    struct ListNode *temp;
    while(temp != head)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
    return (0);
}
