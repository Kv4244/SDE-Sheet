class Solution {
public:
    /*
        Sorting :
            -> first sort intervals;
            -> Now traverse to all the elements in intervals & compare it with the prev answer and store it
            
            TC :   O( n log(n))
            SC :   O(n x n)
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        int ind = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= ans[ind][1])
                ans[ind][1] = max(intervals[i][1],ans[ind][1]);
            else{
                ans.push_back(intervals[i]);
                ind++;
            }
        }
        return ans;
    }
};