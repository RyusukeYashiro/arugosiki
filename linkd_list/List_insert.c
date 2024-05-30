#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createNode(int data)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode -> data = data;
    newNode -> next = NULL;
    return (newNode);
}

void insertTail(struct ListNode **head , int data)
{
    struct ListNode *newNode = createNode(data);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct ListNode *temp = *head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void insertHead(struct ListNode **head , int data)
{
    struct ListNode *newNode = createNode(data);
    newNode -> next = *head;
    *head = newNode;
}

void insertPosition(struct ListNode **head , int data , int position)
{
    if(position == 1)
    {
        insertHead(head , data);
        return ;
    }
    struct ListNode *newNode = createNode(data);
    struct ListNode *temp = *head;
    for(int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp -> next;
    if(temp == NULL)
    {
        printf("Position out of bounds\n");
        return ;
    }
    newNode -> next = temp -> next;
    // temp ノードがリスト内であるノードAを指していたとして、その次（temp->next）がノードBを指している場合（A -> B）
    // newNode->next = temp->next; とすることで、新しいノードはBを指すようになる。（newNode -> B）。
    temp -> next = newNode;
}

void printList(struct ListNode *head)
{
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d -> " , temp -> data);
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

    printList(head);
    return (0);
}