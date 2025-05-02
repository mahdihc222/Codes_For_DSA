#include<iostream>
#include "SLL_node.h"
using namespace std;

//using reverse to reverse the linked list and then add 1
// then again reverse it and give it back

SLLNode *reverseSLL(SLLNode *head){
    if(head==nullptr || head->next==nullptr) return head;
    SLLNode *front, *prev, *cur;
    cur = head;
    prev = nullptr;
    while(cur!=nullptr){
        front = cur->next;
        cur->next = prev;
        prev = cur;
        cur = front;
    }
    return prev;
}

SLLNode* addoneToTheSLL(SLLNode *head){
    //Time complexity: O(N), Space-complexity: O(1)
    if(head==nullptr) return new SLLNode(1,nullptr);

    head = reverseSLL(head);
    SLLNode *temp = head;
    int carry=1;
    while(temp!=nullptr){
        temp->value+=carry;
        carry = temp->value/10;
        temp->value = temp->value%10;
        if(carry==0) break;
        temp = temp->next;
    }
    if(carry==1){
        head = new SLLNode(1,head);
    }
    head = reverseSLL(head);
    return head;
}

//recursive approach

int helperFunc(SLLNode *head){
    if(head==nullptr) return 1;
    int carry = helperFunc(head->next);
    head->value+=carry;
    carry = head->value/10;
    head->value = head->value%10;
    return carry;
}

SLLNode *addonetoSLL_rec(SLLNode *head){
    //Time complexity: O(N)
    //Space complexity: O(N) , auxilliary stack space
    int carry = helperFunc(head);
    if(carry==1){
        head = new SLLNode(1,head);
    }
    return head;
}

