class Solution {
public:
    /*
        eg 
            1  2  3  4              13 9  5 1
            5  6  7  8      =>      14 10 6 2
            9  10 11 12             15 11 7 3
            13 14 15 16             16 12 8 4

        Observation :
            First row goes to last column
            second row -> second last col
            ...

            1st col -> reverse -> 1st row
    */
    /*
        Brute force :
            make a new matrix
                    void rotate(vector<vector<int>>& matrix) {
                    int n = matrix.size();
                    vector<vector<int>> ans(n,vector<int>(n));
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            ans[j][n-i-1] = matrix[i][j];
                        }
                    }
                    matrix = ans;
                }
                TC : O(N x N)
                SC : O(N x N)
    */
    /*
        To do inplace
            -> first we do the transpose of the matrix ( change row to col and col to row)
            -> reverse every row

                1  2  3  4                          1 5 9  13                                   13 9  5 1
                5  6  7  8      -- Transpose -->    2 6 10 14       -- Reverse every row -->    14 10 6 2
                9  10 11 12                         3 7 11 15                                   15 11 7 3
                13 14 15 16                         4 8 12 16                                   16 12 8 4

            => To Transpose
                Observation : Diagonal elemets remain the same and other swap keeping it as a mirror
            => To reverse 
                just use reverse(v.begin(),v.end())
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose 
        // TC : O(N/2 * N/2)
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Reverse
        // TC : O(N*N/2)
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};