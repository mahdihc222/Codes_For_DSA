#include<iostream>
#include "SLL_node.h"

using namespace std;
//this function removes/deletes the nth node from back in a SLL
SLLNode* removenthFromBack(SLLNode *head, int n){
    if(head==nullptr) return nullptr;
    SLLNode *slow=head;
    SLLNode* fast = head;
    for(int i=0; i<n; i++) fast = fast->next;
    if(fast==nullptr){
        //in this case, it means that n is equal to the length of the LL meaning we need to dlt head
        head = head->next;
        delete slow;
        return head;
    }
    while(fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    SLLNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

int main(){

}