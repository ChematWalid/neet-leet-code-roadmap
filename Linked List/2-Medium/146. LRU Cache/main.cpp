#include <iostream>
#include <list>
#include <unordered_map>


class LRUCache {
private:
    int cap;
    std::list<std::pair<int, int>> lru; 

    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    //return key and make it recently used (to the left) left = most recent
    int get(int key) {
        if (cacheMap.count(key) == 0) { 
            return -1;
        }
        //get the value(pointer/iterator in the list)
        auto listIt = cacheMap[key]; 
        //move it to the beginning because it's the most recently used
        lru.splice(lru.begin(), lru, listIt);
        return listIt->second; //return the value
    }

    
    void put(int key, int value) {
        //the value exists, update and make it recently used
        if (cacheMap.count(key) > 0) {
            auto listIt = cacheMap[key];
            listIt->second = value;
            lru.splice(lru.begin(), lru, listIt);
            return;
        }
        //reached capacity , remove least recently used
        if (lru.size() == cap) {
            int lruKey = lru.back().first;
            cacheMap.erase(lruKey);
            lru.pop_back();
        }
        //now insert to front because it's the most recently used now because we have capacity
        lru.push_front({key, value});
        cacheMap[key] = lru.begin();
    }

};