class MyHashMap {
public:
static int const SIZE=1009;
vector<list<pair<int,int>>>buckets;
int hash(int key){
    return key%SIZE;
}
    MyHashMap() {
          buckets.resize(SIZE);  
    }
    
    void put(int key, int value) {
        int idx=hash(key);
        for(auto &p:buckets[idx]){
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        buckets[idx].push_back({key,value});
        
    }
    
    int get(int key) {
        int idx=hash(key);
        for(auto &p:buckets[idx]){
            if(p.first==key){
                return p.second;
            }
        }
        return -1;

        
    }
    
    void remove(int key) {
        int idx=hash(key);
        auto &bucket=buckets[idx];
        for(auto it=bucket.begin();it!=bucket.end();it++){
            if(it->first==key){
                 bucket.erase(it);
            return;
            }
           
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */