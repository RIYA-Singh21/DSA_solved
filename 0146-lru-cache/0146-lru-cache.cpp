class LRUCache {
public:
    class node{
        public:
            int key;
            int val;

            node*next;
            node*prev;
            node(int key_,int value_){
                key=key_;
                val=value_;
            }
        };
        //initialize a dummy head and tail
        node *head=new node(-1,-1);
        node *tail=new node(-1,-1);
    int cap;
    //initialize map to store the key and the node address
    unordered_map<int,node *>mpp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    //func to add node 
    void addnode(node *newnode){
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    //func to delete a node
    void dltnode(node *delnode){
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key) {
        //check if key already exists
        if(mpp.find(key)!=mpp.end()){
            node *resnode=mpp[key];
            int res=resnode->val;
            //delete the node from its current pos before returning res.val
            dltnode(resnode);
            addnode(resnode);
            mpp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //check whether the node already exists
         if(mpp.find(key)!=mpp.end()){
            node *currnode=mpp[key];
            mpp.erase(key);
            dltnode(currnode);
        }
        //check if the capacity is full or not 
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            dltnode(tail->prev);
        }
        addnode(new node(key,value));
        mpp[key]=head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */