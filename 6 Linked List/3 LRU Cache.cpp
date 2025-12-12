#include <bits/stdc++.h>
using namespace std;

/* Approach: Doubly Linked List and Hash Map
*/

/* We use:
1️) Doubly Linked List -> used to achieve LRU cache
 - Stores elements in most-recently-used → least-recently-used order
 - Fast remove & insert (O(1))

2️) Hash Map -> used to achieve O(1) in finding and updating/retrieving the element
 - Stores keys → iterator to Node in doubly linked list
 - Fast lookup (O(1)) */

class LRUCache {
public:
    
    int capacity; // Capacity of the cache

    // Doubly linked list to maintain usage order:
    // Front/Left  --> Most Recently Used (MRU)
    // Back/Right   --> Least Recently Used (LRU)

    // Each node in the Doubly linked list is a pair(key, value)
    list<pair<int, int>> dll;

    // Hash map: key -> iterator pointing to the node in dll
    unordered_map<int, list<pair<int,int>>::iterator> hash;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Move a key-value pair to the front (mark as Most Recently Used)
    void makeMostRecent(int key) {
        // Get iterator of the key
        auto it = hash[key];

        // Store the element before erasing
        pair<int,int> temp = *it;

        // Erase node from OLD position and Insert at front (MRU position)
        dll.erase(it);
        dll.push_front(temp);

        // Udate the hash for newly moved key
        hash[key] = dll.begin();
    }

    int get(int key) {
        // If key does not exist
        if (hash.find(key) == hash.end())
            return -1;

        // Key exists → move to MRU position
        makeMostRecent(key);

        // Return the value
        return hash[key]->second;
    }

    void put(int key, int value) {

        // Base_case:
        if(capacity == 0)
            return; 

        // Case 1: Key doesnt exist. Remove and insert at MRU position
        if (hash.find(key) == hash.end()) {

            if (dll.size() == capacity)  // capacity is full → remove LRU item
            { 
                // Back of DLL has least recently used key
                auto lruNode = dll.back();
                int lruKey = lruNode.first;

                // Remove from hash map and linked list
                hash.erase(lruKey);
                dll.pop_back();
            }

            // Insert new (key, value) at MRU position
            dll.push_front({key, value});
            
            // Udate the hash for newly inserted key
            hash[key] = dll.begin();
        }
        
        // Case 2: Key already exists → update value & move to MRU
        else {
            hash[key]->second = value;  // update value in list using hash
            makeMostRecent(key);      // move to MRU
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/***************************************************
 * Time Complexity : O(1)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    
*/

/* Question:
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:

    - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    - int get(int key) Return the value of the key if the key exists, otherwise return -1.
    - void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
      add the key-value pair to the cache. If the number of keys exceeds the capacity from this
      operation, evict the least recently used key.
      
      The functions get and put must each run in O(1) average time complexity.

    Example 1:
    Input:
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output:
    [null, null, null, 1, null, -1, null, -1, 3, 4]

    Explanation:
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
*/