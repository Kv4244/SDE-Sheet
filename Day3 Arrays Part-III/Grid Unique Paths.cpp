class Solution {
public:
    /*
        Brute Force -- Recursion
            Try out all possible ways

                int f(int i,int j,int m,int n){
                    // base case
                    if(i == m-1 && j == n-1) return 1;
                    if(i == m || j == n) return 0;
                    // recursion
                    return f(i+1,j,m,n) + f(i,j+1,m,n);
                }
                int uniquePaths(int m, int n) {
                    return f(0,0,m,n);
                }

            TC : O( 2^(M x N)) 
            SC : O( 2^(M x N)) 
    */
    /*
        Memorization

            int f(int i,int j,int m,int n,vector<vector<int>> &dp){
                // base case
                if(i == m-1 && j == n-1) return 1;
                if(i == m || j == n) return 0;
                if(dp[i][j] != -1) return dp[i][j];
                // recursion
                return dp[i][j] = f(i+1,j,m,n,dp) + f(i,j+1,m,n,dp);
            }
            int uniquePaths(int m, int n) {
                vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
                return f(0,0,m,n,dp);
            }

        TC : O(M x N) 
        SC : O(M x N) + O(M x N)  // dp + Auxilary stack space
    */
    /*
        Tabulation 
            int uniquePaths(int m, int n) {
                vector<vector<int>> dp(m,vector<int>(n,0));
                dp[m-1][n-1] = 1;
                for(int i=m-1;i>=0;i--){
                    for(int j=n-1;j>=0;j--){
                        if(i+1 <= m-1) dp[i][j] += dp[i+1][j];
                        if(j+1 <= n-1) dp[i][j] += dp[i][j+1];
                    }
                }
                return dp[0][0];
            }
        TC : O(M x N) 
        SC : O(M x N) // dp 
    */
    /*
        Space Optimization 

        TC : O(M x N) 
        SC : O(N) 
    */
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1);
        for(int i=m-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=n-1;j>=0;j--){
                if(i+1 <= m-1) curr[j] += prev[j];
                if(j+1 <= n-1) curr[j] += curr[j+1];
            }
            prev = curr;
        }
        return prev[0];
    }
};