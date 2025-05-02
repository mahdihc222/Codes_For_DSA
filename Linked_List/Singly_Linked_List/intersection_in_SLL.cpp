#include<iostream>
#include<unordered_map>
#include "SLL_node.h"
using namespace std;

//first way: Use a map to store
//this uses the concept of hashing
SLLNode* findIntersection_using_hashmap(SLLNode *head1, SLLNode *head2){
    unordered_map<SLLNode*,int> mp;
    SLLNode *temp;
    temp = head1;
    while(temp){
        mp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        if(mp.find(temp)!=mp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}


//this way uses two pointers, do a dry run to understand better
SLLNode* findIntersection(SLLNode *head1, SLLNode *head2){  
    if(head1==nullptr || head2==nullptr ) return nullptr;
    SLLNode* temp1 = head1;
    SLLNode* temp2 = head2;
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1==nullptr) temp1 = head2;
        if(temp2==nullptr) temp2 = head1;
    }
    return temp1;
}