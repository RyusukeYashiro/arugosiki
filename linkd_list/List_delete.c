#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

void deleteHead(struct ListNode **head)
{
    if(*head == NULL)
        return ;
    struct ListNode *temp = *head;
    *head = (*head) -> next;
    free(temp);

}

void deleteTail(struct ListNode **head)
{
    if(*head == NULL)
        return;
    if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
        return ;
    }
    struct ListNode *temp = *head;
    while(temp -> next -> next != NULL)
        temp = temp -> next;
    free(temp -> next);
    temp -> next = NULL;

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


}