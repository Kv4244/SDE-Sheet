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
        next_permutation(nums.begin(),nums.end());
    */
    /*
        How does this STL Work

        1. Find out the longest prefix match
            a[i] < a[i+1]
        2. find element > a[i] but the smallest one
            i.e iterate from last and find the element which is greater than curr a[i]
        3. try to place the remaining in sorted order
    */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // 1.Find out the longest prefix match
        int ind = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1)
            sort(nums.begin(),nums.end());
        else{
            // 2. find element > a[i] but the smallest one
            for(int i= n-1;i>ind;i--){
                if(nums[i] > nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            // try to place the remaining in sorted order
            sort(nums.begin()+ind+1,nums.end());
        }
    }
};