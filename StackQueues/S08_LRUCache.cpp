#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache{
    public:
        int capacity;
        unordered_map<int, Node*> mp;
        Node* head;
        Node* tail;

        LRUCache(int capacity){
            this->capacity = capacity;
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
        }

        void deleteNode(Node* node){
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

        void addNode(Node* node){
            Node* temp = head->next;
            head->next = node;
            node->prev = head;
            node->next = temp;
            temp->prev = node;
        }

        int get(int key){
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                int result = node->value;
                deleteNode(node);
                addNode(node);
                mp[key] = head->next;
                return result;
            }
            return -1;
        }

        void put(int key, int value){
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                deleteNode(node);
                delete node;
                mp.erase(key);
            }
            if(mp.size() == capacity){
                Node* node = mp[tail->prev->key];
                mp.erase(node->key);
                deleteNode(tail->prev);
                delete node;
            }

            addNode(new Node(key, value));
            mp[key] = head->next;
        }
};

int main(){
        // Create cache with capacity 2
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl; 

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl; 

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl; 

    // Key 3 should be present
    cout << cache.get(3) << endl; 

    // Key 4 should be present
    cout << cache.get(4) << endl; 

    return 0;
}