class Solution {
public:
    /*
        Brute Force : 
            TC : O(N x M)
            SC : O(1)
    */
    /*
        Better : 
            Traversing through each row and checking if element is present or not by binary search
            TC : O(N x log(M))  || O(log(N) X M)
            SC : O(1)
    */
    /*
        Optimized
            Binary search to row and col simultaneously 
            TC : O(log(N) x log(M))
            SC : O(1)
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int start = 0,end = m*n -1;
        while(start <= end){
            int ind = start + (end-start)/2;
            int curr = matrix[ind/n][ind%n];
            
            if(curr == target) return true;
            if(curr > target) end = ind-1;
            else start = ind+1;
        }
        return false;
    }
};