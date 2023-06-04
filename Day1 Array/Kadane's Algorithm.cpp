class Solution {
public:
    /*
        Brute force : 
            Iterate through every possible sub array 
                1. Traverse through every index
                2. from every index traverse to every possible sub array 
                3. return the max sum
            TC : O(N X N)
            SC : O(1)
    */
    /*
        Kadane's Algorithm :
            1. initialize two variable max_sum, curr_sum;
            2. Iterate through the array  -> curr_sum += nums[i]
                                          -> max_sum = max(max_sum,curr_sum);
                                          -> if(curr_sum < 0 ) curr_sum = 0;
            3. return max_sum
    */
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN,curr_sum = 0;
        for(int i=0;i<nums.size();i++){
            curr_sum += nums[i];
            max_sum = max(max_sum,curr_sum);
            if(curr_sum < 0 )
                curr_sum = 0;
        }
        return max_sum;
    }
};