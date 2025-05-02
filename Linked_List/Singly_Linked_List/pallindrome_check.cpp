#include<iostream>
#include<stack>
#include"SLL_node.h"

using namespace std;
//this program checks if a SLL is a plaindrome
//Using extra space
bool isPallindrome(SLLNode *head){
    if(head==nullptr || head->next == nullptr) return true;
    SLLNode *temp = head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->value);
        temp = temp->next;
    }
    temp = head;
    while(!st.empty()){
        if(temp->value !=st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
    //Time complexity: O(2N), Space Complexity: O(N)
}

//more optimized solution
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
bool isPallindrome_opt(SLLNode *head){
    //using tortoise-hare algorithm
    if(head==nullptr || head->next == nullptr) return true;
    SLLNode *fast, *slow;
    fast = slow = head;
    //the following codes will put slow at the middle node or just after the middle node
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast!=nullptr) slow = slow->next;

    //using fast to check from the beginning
    //reversing the last half of the list and then first one and last one would be identical if pallindrome
    SLLNode *newHead = reverseSLL(slow); //head of the newly reversed half
    slow = newHead;
    fast = head; //oldhead
    while(slow!=nullptr){
        if(fast->value != slow->value){
            reverseSLL(newHead);
            return false;
        } 
        fast = fast->next;
        slow = slow->next;
    }
    reverseSLL(newHead);
    return true;
}