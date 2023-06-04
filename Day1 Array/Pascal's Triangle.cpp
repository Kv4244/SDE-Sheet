class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> t;
            t.push_back(1);
            for(int j = 1;j <= i-1;j++){
                int curr = ans[i-1][j-1] + ans[i-1][j];
                t.push_back(curr);
            }
            if(i>0)
                t.push_back(1);
            ans.push_back(t);
        }
        return ans;
    }
};