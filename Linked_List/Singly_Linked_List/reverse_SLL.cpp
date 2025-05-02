#include<iostream>
#include "SLL_node.h"
using namespace std;

SLLNode* reverseSLL(SLLNode* head){
    SLLNode *temp = head;
    SLLNode *prev = nullptr;
    SLLNode *front;

    while(temp!=nullptr){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    head = prev;
    return head;

}