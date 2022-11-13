class MyHashMap {
public:
    //solution 1: using vector
    //limitations: works till dataset 10^6 as maximum size of vector is 10^6
    vector<int> m;
    int siz;
    MyHashMap() {
        siz = 1e6+1;
        m.resize(siz);
        fill(m.begin(),m.end(),-1); //initialize vector with -1(all elements)
    }
    
    void put(int key, int value) {
        m[key] = value; // add value and update
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */