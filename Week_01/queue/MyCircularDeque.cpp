class MyCircularDeque {
public:
    struct Note {
        Note* pre;
        Note* next;
        int val;
        Note()  {val=-9999;pre=NULL;next=NULL;}
        Note(int val_ini) {val=val_ini;pre=NULL;next=NULL;}
    };
    int size;
    int capacity;
    Note* head ;
    Note* tail ;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = 0;
        capacity = k;
        head = new Note();
        tail = new Note();
        head->next = tail;
        tail->pre = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        auto node = new Note(value);
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        auto node = new Note(value);
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        head->next->next->pre = head;
        head->next = head->next->next;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        tail->pre->pre->next = tail;
        tail->pre = tail->pre->pre;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return head->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return tail->pre->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(size == 0) return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(size == capacity) return true;
        return false;
    }
// private:
    // struct Note {
    //     Note* pre;
    //     Note* next;
    //     int val;
    //     Note() {val=-9999;pre=Null;next=Null}
    // };
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */