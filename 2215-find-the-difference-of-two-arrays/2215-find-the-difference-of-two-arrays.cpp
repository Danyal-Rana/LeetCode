class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        set <int> s1;
        set <int> s2;
        vector <vector<int>> myVector (2);

        for (int i : nums1)
        {
            s1.insert (i);
        }

        for (int i : nums2)
        {
            s2.insert (i);
        }

        for (int i : s1)
        {
            if (s2.count(i) == 0)
            {
                myVector[0].push_back (i);
            }
        }

        for (int i : s2)
        {
            if (s1.count(i) == 0)
            {
                myVector[1].push_back (i);
            }
        }

        return myVector;        
    }
};