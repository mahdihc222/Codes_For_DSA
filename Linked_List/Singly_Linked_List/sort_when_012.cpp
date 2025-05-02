//this program will sort a linked list with 0's, 1's and 2's
#include<iostream>
#include "SLL_node.h"
using namespace std;

SLLNode *sortSLL(SLLNode *head){
    if(head==nullptr) return nullptr;
    //these are dummy heads
    SLLNode *zeroHead = new SLLNode(-1);
    SLLNode *oneHead = new SLLNode(-1);
    SLLNode *twoHead = new SLLNode(-1);
    SLLNode *zeroCur = zeroHead;
    SLLNode *oneCur = oneHead;
    SLLNode *twoCur = twoHead;
    SLLNode *temp;
    while(temp!=nullptr){
        if(temp->value==0){
            zeroCur->next = temp;
            zeroCur = zeroCur->next;
        }
        else if(temp->value==1){
            oneCur->next = temp;
            oneCur = oneCur->next;
        }
        else if(temp->value==2){
            twoCur->next = temp;
            twoCur = twoCur->next;
        }
    }
    zeroCur->next = oneHead->next?oneHead->next : twoHead->next;
    twoCur->next=nullptr;
    oneCur->next= twoHead->next;
    delete oneHead;
    delete twoHead;
    return zeroHead->next;
}

int main(){

}