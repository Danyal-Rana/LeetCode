class Solution {
public:
    int subarraySumTarget(int target, vector<int> &vv){
        int n = vv.size();
        vector<int> prefix(n);
        prefix[0] = vv[0];
        for(int i = 1 ; i<= n-1 ; i++){
            prefix[i] = prefix[i-1] + vv[i];
        }

        map<int,int> mm;
        mm[0] = 1;
        int ans = 0;
        for(auto i: prefix){
            if(mm.find(i - target)!=mm.end()){
                ans+= mm[i-target];
            }
            mm[i]++;
        }
        return ans; 
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<= m-1;i++){
            for(int j = 1;j <= n-1 ; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        int ans = 0;

        for(int c1 = 0 ; c1<= n-1 ; c1++){
            for(int c2 = c1 ; c2 <= n-1 ; c2++){
                vector<int> vv;
                for(int i = 0;i<= m-1;i++){
                    int val = 0;
                    if(c1>=1) val = matrix[i][c1-1];
                    vv.push_back(matrix[i][c2] - val);
                }

                ans+= subarraySumTarget(target, vv);

            }
        }

        return ans; 
        
    }
};