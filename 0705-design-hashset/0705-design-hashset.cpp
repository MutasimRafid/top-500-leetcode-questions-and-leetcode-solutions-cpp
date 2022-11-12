class MyHashSet {
public:
    /*
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
    */
    
     //solution2: Using chaining technique: Linked list
    
    vector<list<int>> m;
    int siz;
    MyHashSet() {
       siz = 10000;
       m.resize(siz); 
    }
    
    int hash(int key){
        return key%siz;
    }
    
    list<int> :: iterator search(int key){
        int i = hash(key); //index of the vector(there is a linked list in every particular index of vector)
        return find(m[i].begin(),m[i].end(),key); //returning iterator
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i = hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
       if(!contains(key))return;
        int i = hash(key);
        m[i].erase(search(key)); //search(key) will return iterator of the linked list
         
    }
    
    bool contains(int key) {
        int i = hash(key);
        if(search(key) != m[i].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */