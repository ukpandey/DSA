#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int key;
    int value;
    int count; // to store the frequency of the node which is accessed.
    Node* next;
    Node* prev;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        count = 1; // initial frequency of the node 
        next = nullptr;
        prev = nullptr;
    }
};

class LFUCache{
  public: 
    int capacity, minFrequency;
    unordered_map<int, Node*> cacheMap;
    // {1, head<->tail} // this will store LRU on the basis of frequency;
    unordered_map<int, pair<Node*, Node*>> freqMap;

    LFUCache(int capacity){
        this->capacity = capacity;
        minFrequency = 0;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node* node, int count){
        // initialize the freqMap for the count, if count (assume 2) doesn't exist
        if(freqMap.find(count) == freqMap.end()){
            Node* head = new Node(-1,-1);
            Node* tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            freqMap[count] = {head, tail};
        }

        Node* headNode = freqMap[count].first;
        Node* nextNode = headNode->next;
        headNode->next = node;
        node->next = nextNode;
        nextNode->prev = node;
        node->prev = headNode;
    }

    void updateFreq(Node* node){
        int prevFreq = node->count;
        node->count++;
        
        // before removing 0 -> head(first)<->(1,10)<->tail(second)
        deleteNode(node);
        // after 0 -> head<->tail 0th freq list is empty has erase 0th key 
        if(freqMap[prevFreq].first->next == freqMap[prevFreq].second){
            freqMap.erase(prevFreq);

            // if min freq was 0, but we deleted 0th key hence 0 doesn't exist.
            if(minFrequency == prevFreq){
                minFrequency++;
            }
        }
        addNode(node,node->count);
    }

    int get(int key){
        if(cacheMap.find(key) != cacheMap.end()){
            Node* node = cacheMap[key];
            int val = node->value;
            updateFreq(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value){
        if(capacity == 0) return;

        if(cacheMap.find(key) != cacheMap.end()){
            Node* node = cacheMap[key];
            node->value = value;
            updateFreq(node);
        }
        else{
            if(capacity == cacheMap.size()){
                // get the lru node which is less frequent haha
                Node* node = freqMap[minFrequency].second->prev;
                cacheMap.erase(node->key);
                deleteNode(node);

                // after 0 -> head<->tail 0th freq list is empty has erase 0th key 
                if(freqMap[minFrequency].first->next == freqMap[minFrequency].second){
                    freqMap.erase(minFrequency);
                } 
                delete node;
            }

            Node* newNode = new Node(key,value);
            cacheMap[key] = newNode;
            minFrequency = 1;
            addNode(newNode,minFrequency);
        }
    }
};

int main(){
    LFUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << " ";
    cache.put(3, 3);
    cout << cache.get(2) << " ";
    cache.put(4, 4);
    cout << cache.get(3) << " ";
    cout << cache.get(4) << " ";
    cache.put(5, 5);

    return 0;
}