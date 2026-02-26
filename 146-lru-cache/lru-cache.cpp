// LRU Cache Algorithm (Short Version)

// Data Structures:
// - Doubly Linked List (root = MRU, tail = LRU)
// - Hash Map (key → node pointer)
// - size = remaining capacity


// GET(key):

// 1. If key not in map → return -1
// 2. curr = m[key]
// 3. If curr != root:
//       - Detach curr from its position
//       - If curr == tail → update tail
//       - Move curr to front (make it root)
// 4. Return curr->value


// PUT(key, value):

// 1. If key exists:
//       - Move node to front
//       - Update value
//       - Return

// 2. If cache full (size == 0):
//       - Remove tail node
//       - Erase its key from map
//       - Update tail
//       - size++

// 3. Insert new node at front
// 4. size--
// 5. Add key → node in map


// Time Complexity:
// GET  → O(1)
// PUT  → O(1)

class LRUCache {
public:
// creating class for doubly linked list
    class node{
        public:
        int key, val;
        node* next, *prev;
        node(int key, int val){
            this->key = key;
            this->val = val;
            next = prev = nullptr;
        }
    };

    int size;
    unordered_map<int, node*> m;
    node* root, *tail;

    // intialised size, root & tail pointer
    LRUCache(int capacity) {
        size = capacity;
        root = tail = nullptr;
    }
    
    int get(int key) {

        // entry present in map
        if(m.count(key)){
            node* curr = m[key];

            if(curr != root){
                // when curr is tail node
                if(tail == curr) 
                    tail = curr->prev;

                if(curr->prev)
                    curr->prev->next = curr->next;

                if(curr->next)
                    curr->next->prev = curr->prev;    

                curr->next = root;
                root->prev = curr;
                curr->prev = nullptr;
                root = curr;
            }    

            return curr->val;
        }

        return -1;
    }
    
    void put(int key, int value) {

        // if entry is already present
        if(m.count(key)){
            node* curr = m[key];

            if(curr != root){
                // when curr is tail node
                if(tail == curr) 
                    tail = curr->prev;

                if(curr->prev)
                    curr->prev->next = curr->next;

                if(curr->next)
                    curr->next->prev = curr->prev;    

                curr->next = root;
                root->prev = curr;
                curr->prev = nullptr;
                root = curr;
            }    

            root->val = value;
            return;
        }

        // cache is full
        if(size == 0){
            node* temp = tail;
            m.erase(temp->key);

            // when capacity = 1
            if(root ==  tail){
                delete temp;
                root = tail = nullptr;
            }
            else{
                node* prevTail = tail->prev;
                prevTail->next = nullptr;
                delete temp;
                tail = prevTail;
            }

            size++;
        }


        // create new node and also create entry in map
        if(!root){
            root = new node(key, value);
            tail = root;
        }

        else{
            node* newNode = new node(key, value);
            newNode->next = root;
            root->prev = newNode;
            root = newNode;
        }

        size--;
        m[key] = root;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */