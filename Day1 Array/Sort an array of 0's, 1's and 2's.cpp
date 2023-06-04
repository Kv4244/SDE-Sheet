class Solution {
public:
    /*
        brute force:
            sort the array
                sort(nums.begin(),nums.end())

            TC : O(N log(N))
            SC : O(1)
    */
    /*
        Counting    
            1. count number of zero ,one ,two
            2. fill array with zero -> one -> two

                void sortColors(vector<int>& nums) {
                    int countZero = 0, countOne = 0, countTwo = 0;
                    for(auto it : nums){
                        if(it == 0) countZero++;
                        else if(it == 1) countOne++;
                        else countTwo++;
                    }
                    int k = 0;
                    for(int i=0; i<countZero; i++) nums[k++] = 0;
                    for(int i=0; i<countOne; i++) nums[k++] = 1;
                    for(int i=0; i<countTwo; i++) nums[k++] = 2;
                }
            TC : O(N) + O(N)
            SC : O(1)
    */
    /*
        Pointers
            _   _   _   _   _   _   _   _   _   _   _   _   _   _   
            0           low             mid-1 mid            high high+1        n-1

            0-low-1 => all 0
            low - mid-1 => all 1
            high+1 - n-1 => all 2

            mid - high => solve

            1. make 3 pointer low,mid,high  // low pointing to 0, mind to 1, high to 2
            2. start from low = 0, mid = 0, high = n-1
            3. if(nums[mid] == 0)
                    swap(nums[low],nums[mid])
                    low++
                    mid++
               if(nums[mid] == 1)
                    mid++
               if(nums[mid] == 2)
                    swap(nums[mid],nums[high])
                    high--;

    */
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(high >= mid){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};