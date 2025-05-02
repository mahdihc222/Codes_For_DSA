#include<iostream>
#include "SLL_node.h"
using namespace std;

SLLNode* deleteMiddleNode(SLLNode *head){
    if(head==nullptr && head->next == nullptr) return nullptr;
    SLLNode *fast = head->next->next;
    SLLNode* slow = head;
    while(fast!=nullptr && fast->next!=nullptr){
        //this loop will make slow to point to the node before middle
        slow = slow->next;
        fast = fast->next->next;
    }
    SLLNode *mid = slow->next;
    slow->next = mid->next;
    mid->next = nullptr;
    delete mid;
    return head;
}

int main(){

}