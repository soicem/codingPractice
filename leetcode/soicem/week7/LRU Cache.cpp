class DLinkedNode{
public:
    int key;
    int value;
    
    DLinkedNode * prev = NULL;
    DLinkedNode * next = NULL;

    DLinkedNode(int key, int value){
        this->key = key;
        this->value = value;
    }
};

unordered_map<int, DLinkedNode*> cache; // key, *DLinkedNode

class LRUCache {
public:
    int capacity = 0;
    int length = 0;
    
    DLinkedNode * head = NULL;
    DLinkedNode * tail = NULL;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void deleteNode(DLinkedNode* node){
        DLinkedNode* prevNode = node->prev;
        DLinkedNode* nextNode = node->next;
        
        if(prevNode){
            prevNode->next = nextNode;
            node->prev = NULL;
        } else {
            head = nextNode;
        }
        if(nextNode){
            nextNode->prev = prevNode;
            node->next = NULL;
        } else {
            tail = prevNode;
        }
    }
    
    void prependToHead(DLinkedNode* node){
        if(this->head == NULL){
            head = node;
            node->prev = NULL;
            node->next = NULL;
            tail = head;
            return;
        }
        node->next = this->head;
        this->head->prev = node;
        this->head = node;
    }
    
    void moveToHead(int key){
        deleteNode(cache[key]);
        prependToHead(cache[key]);
    }
    
    void evict(){
        DLinkedNode * prevTail = this->tail->prev;
        cache[tail->key] = NULL;
        tail = prevTail;
        tail->next = NULL;
    }
    
    void pushFront(int key, int value){
        if(head == NULL){
            head = new DLinkedNode(key, value);
            tail = head;
        } else {
            DLinkedNode * prevNode = new DLinkedNode(key, value);
            prevNode->next = this->head;
            this->head->prev = prevNode;
            this->head = prevNode;
        }
        cache[key] = this->head;
    }
    
    int get(int key) {
        if(cache[key] == NULL){
            return -1;
        }
        moveToHead(key);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if(cache[key] == NULL){
            pushFront(key, value);
            if(this->length == capacity){
                evict();
            } else {
                this->length += 1;
            }
        } else {
            cache[key]->value = value;
            moveToHead(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
