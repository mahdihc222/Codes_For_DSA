#include<iostream>
#include "SLL_node.h"

using namespace std;

//this function inserts a new Node at the beginning of the SLL and returns new head
SLLNode *insertAtBeginning(SLLNode *head, int x){
    SLLNode *temp = new SLLNode(x,head);
    if(temp==NULL){
        cout<<"Error allocating memory...";
        exit(-1);
    }
    head = temp;
    return head;
}

//this function inserts a node at the last of the SLL
SLLNode *insertAtLast(SLLNode *head, int x){
    SLLNode *temp;
    temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new SLLNode(x,nullptr);
    return head;
}


//inserts a node at a specific position
SLLNode *insertAtPosition(SLLNode *head, int x, int pos){
    SLLNode *temp=head;
    pos--;
    while(pos){
        temp = temp->next;
        pos--;
    }
    SLLNode *newNode = new SLLNode(x);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

//insert a node after a given value
SLLNode *insertAfterThis(SLLNode *head, int x, int given){
    SLLNode* temp =head;
    while(temp){
        if(temp->value==given) break;
        temp = temp->next;
    }
    if(temp!=nullptr){
        SLLNode *newItem = new SLLNode(x);
        newItem->next = temp->next;
        temp->next = newItem;
    }
    return head;
}

//this function deletes the first node
SLLNode* deleteFirst(SLLNode *head){
    if(head==nullptr) return nullptr;
    SLLNode *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

//this function deletes from last
SLLNode* deleteLast(SLLNode *head){
    if(head==nullptr ) return nullptr;
    if(head->next==nullptr){
        free(head);
        return nullptr;
    }
    SLLNode *temp=head;
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

//deleting a node that has the value x
SLLNode* deleteNode(SLLNode *head, int x){

    SLLNode *cur = head;
    SLLNode* prev = nullptr;
    while(cur!=nullptr){
        if(cur->value==x) break;
        prev = cur;
        cur = cur->next;
    }
    if(cur==nullptr) return head;
    
    if(prev) prev->next = cur->next;
    else head = head->next;
    free(cur);
    return head;

}


void printSLL(SLLNode *head){
    SLLNode *temp = head;
    while(temp) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}

int main(){
    SLLNode *head = new SLLNode(3);
    head = insertAtBeginning(head,4);
    insertAtLast(head,9);
    insertAtPosition(head,7,2);
    insertAfterThis(head,6,7);
    printSLL(head);
    return 0;

}