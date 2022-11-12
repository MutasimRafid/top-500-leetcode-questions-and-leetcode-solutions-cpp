class MyHashSet {
public:
    //solution1: only valid for 10^6 dataset
    //As you can only create vector till 10^6
    vector<int> mp;
    int len;
    MyHashSet() {
       len = 1e6+1;
       mp.resize(len); 
    }
    
    void add(int key) {
        mp[key] = 1;
    }
    
    void remove(int key) {
        mp[key] = 0;
    }
    
    bool contains(int key) {
        return mp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */