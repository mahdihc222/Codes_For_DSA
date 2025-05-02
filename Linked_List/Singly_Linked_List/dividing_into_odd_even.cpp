#include<iostream>
#include "SLL_node.h"

using namespace std;

void partition_into(SLLNode *head, SLLNode* &oddHead, SLLNode* &evenHead){
    if(head==nullptr){
        oddHead = evenHead = nullptr;
        return;
    }
    if(head->next==nullptr){
        oddHead = head;
        evenHead = nullptr;
        return;
    }
    oddHead = head;
    evenHead = head->next;
    SLLNode *odd=oddHead, *even=evenHead;

    while(odd!=nullptr && even!=nullptr){
        odd->next = even->next;
        odd = odd->next;
        if(odd!=nullptr){
            even->next = odd->next;
            even = even->next;
        }
    }

}

void printSLL(SLLNode *head){
    SLLNode *temp = head;
    while(temp) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    SLLNode *head = new SLLNode(3);
    SLLNode *cur = head;
    cur->next = new SLLNode(4);
    cur = cur->next;
    cur->next = new SLLNode(9);
    cur = cur->next;
    cur->next = new SLLNode(5);
    cur = cur->next;
    cur->next = new SLLNode(8);
    cur = cur->next;
    cur->next = new SLLNode(10);
    cur = cur->next;

    SLLNode *evenHead, *oddHead;
    partition_into(head,oddHead, evenHead);
    printSLL(evenHead);
    printSLL(oddHead);

}