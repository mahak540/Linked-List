class LRUCache {
  private:
  public:
  int cap;
  list<pair<int,int>>List;
  unordered_map<int,list<pair<int,int>>::iterator>cacheMap;
    LRUCache(int cap) {
        // code here
        this->cap=cap;
        
    }

    int get(int key) {
        auto it=cacheMap.find(key);
        if(it==cacheMap.end())
        {
            return -1;
        }
        int value=it->second->second;
        List.erase(it->second);
        List.push_front({key,value});
         cacheMap[key]=List.begin();
         return value;
        
        // code here
    }

        
    void put(int key, int value) {
        // code here
        auto it=cacheMap.find(key);
        if(it!=cacheMap.end())
        {
            List.erase(it->second);
            cacheMap.erase(it);
        }
        List.push_front({key,value});
        cacheMap[key]=List.begin();
        
        if(cacheMap.size()>cap)
        {
            auto lastNode=List.back().first;
            List.pop_back();
            cacheMap.erase(lastNode);
        }
    }
};
