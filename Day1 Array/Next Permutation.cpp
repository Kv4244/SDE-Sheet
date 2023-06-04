class Solution {
public:
    /*
        Brute force :
            1. Find all permutation
            2. search for curr nums
            3. return next index

            TC : N! X N
    */
    /*
        Use inbuilt STL
    */
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};