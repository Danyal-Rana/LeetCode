class AllOne {
public:
    int mx = -1e9, mn = 1e9;
    string mx_a, mn_b;
    unordered_map<string, int> mp;
    AllOne() {}

    void inc(string key) {
        mp[key]++;
        if (mp[key] >= mx) {
            mx = mp[key];
            mx_a = key;
        }
        updateMinKey();
    }

    void dec(string key) {
        if (mp[key] >= 2) {
            mp[key]--;
            if (mp[key] <= mn) {
                mn = mp[key];
                mn_b = key;
            }
        } else {
            mp.erase(key);
        }
        if (mp.size() > 0) {
            if (key == mx_a || key == mn_b) {
                updateMaxMin();
            }
        } else {
            mx = -1e9;
            mn = 1e9;
            mx_a = "";
            mn_b = "";
        }
    }
    void updateMinKey() {
        mn = 1e9;
        for (auto& it : mp) {
            if (it.second < mn) {
                mn = it.second;
                mn_b = it.first;
            }
        }
    }
     void updateMaxMin() {
        mx = -1e9;
        mn = 1e9;
        for (auto& it : mp) {
            if (it.second >= mx) {
                mx = it.second;
                mx_a = it.first;
            }
            if (it.second <= mn) {
                mn = it.second;
                mn_b = it.first;
            }
        }
    }
    string getMaxKey() {
        return mx_a;
    }

    string getMinKey() {
        return mn_b;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */