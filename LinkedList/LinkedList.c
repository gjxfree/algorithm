/*带有头节点的单向链表，头节点的数据为链表的长度*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    unsigned int data;
    struct LinkedList * next;
}LinkedList;

//初始化一个长度为len的单向链表
LinkedList * new_linkedlist(unsigned int len){
    LinkedList * head = (LinkedList *)malloc(sizeof(LinkedList));
    head->data = len;

    LinkedList * now = head;
    LinkedList * next = NULL;
    do
    {
        next = (LinkedList *)malloc(sizeof(LinkedList));
        next->data = 0;
        next->next = NULL;
        now->next = next;
        now = next;
    } while (--len);
    return head;
}

//删除一个单向链表
void del_linkedlist(LinkedList * head){
    LinkedList * now = head;
    LinkedList * next = now->next;
    do
    {
        free(now);
        now = next;
        next = now->next;
    } while (now->next);
    head = NULL;
}

void main(){
    LinkedList * myLinkedList = new_linkedlist(10);
    LinkedList * p = myLinkedList;
    do
    {
        p = p->next;
        printf("%d\n",p->data);
    } while (p->next);
    del_linkedlist(myLinkedList);
}