class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int> arr;
    int i;
    RandomizedSet() {
        i=0;
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            arr.push_back(val);
            mp[val]=i++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int x=arr.back();
            arr[mp[val]]=x;
            arr.pop_back();
            mp[x]=mp[val];
            mp.erase(val);
            i--;
            return true;
        }
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */