 class SLLNode{
    public:
        int value;
        SLLNode *next;
    public:
        SLLNode(int val, SLLNode *nxt=nullptr){
            value = val;
            next = nxt;
        }    
};