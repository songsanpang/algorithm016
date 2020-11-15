// // hsah+双向链表
struct DLinkedNode {
    DLinkedNode *pre,*next;
    int key,val;
    DLinkedNode():key(0),val(0),pre(nullptr),next(nullptr){}
    DLinkedNode(int inkey,int inval):key(inkey),val(inval),pre(nullptr),next(nullptr){}
};
class LRUCache {
private:
    DLinkedNode *head,*tail;
    unordered_map<int,DLinkedNode*> cache;
    int size,capacity;
public:
    LRUCache(int capacity) : capacity(capacity),size(0){
        head = new DLinkedNode(),tail = new DLinkedNode();
        head->next = tail;tail->pre = head;//伪头尾指针
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key,value);
            cache[key] = node;
            addToHead(node);
            size++;
            if(size>capacity){
                DLinkedNode * removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        } 
        else {
            DLinkedNode *node = cache[key];
            node -> val = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode *node){
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }
    void moveToHead(DLinkedNode * node){
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail(){
        DLinkedNode *node = tail->pre;
        removeNode(node);
        return node;
    }
    void removeNode(DLinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
};

    





