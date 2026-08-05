class MyHashSet {
public:
static int const SIZE=1009;
vector<list<int>>buckets;
int hash(int key){
    return key%SIZE;
}
    MyHashSet() {
        buckets.resize(SIZE);
    }
    
    void add(int key) {
        int idx=hash(key);
        for(int x:buckets[idx]){
            if(x==key)
            return;
        }
        buckets[idx].push_back(key);
        
    }
    
    void remove(int key) {
        int idx=hash(key);
        buckets[idx].remove(key);
    }
    
    bool contains(int key) {
        int idx=hash(key);
        for(int x:buckets[idx]){
            if(x==key)
            return true;
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */