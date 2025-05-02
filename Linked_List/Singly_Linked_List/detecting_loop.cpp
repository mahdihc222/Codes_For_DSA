#include<iostream>
#include<unordered_map>
#include "SLL_node.h"
using namespace std;


bool detect_cycle_using_hash(SLLNode *head){
    //Time complexity: O(N*lgN) , lgN for searching in map
    //space complexity: O(N)
    unordered_map<SLLNode*,int> mp;
    SLLNode *temp=head;
    while(temp){
        if(mp.find(temp)!=mp.end()) return true;
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

bool detect_cycle(SLLNode* head){
    //time complexity: O(N)
    //space compelxity: O(1)
    SLLNode *fast,*slow;
    fast = slow = head;
    while(fast!=nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int length_of_loop(SLLNode *head){
    SLLNode *fast=head;
    SLLNode *slow = head;
    int fc=1, sc=1;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        fc+=2;
        sc++;
        if(fast==slow){
            int count=0;
            do{
                slow= slow->next;
                count++;
            }while(fast!=slow);
            return count;
        }
    }
    return 0; 
}

SLLNode* startOfALoop(SLLNode* head){
    SLLNode* fast = head;
    SLLNode* slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}

int main(){

}