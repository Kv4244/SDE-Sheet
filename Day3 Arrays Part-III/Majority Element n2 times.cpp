class Solution {
public:
    /*
        Brute force :
            traverse through all the elements and count the number of occurrence of each elements

            TC : O(N x N)
            SC : O(1)
    */
    /*
        Using sorting 
            sort the array and return the element at the middle of the array

            int majorityElement(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                return nums[nums.size()/2];
            }

            TC : O(N x log(N))
            SC : O(1)
    */
    /*
        Using map : 
            Traverse through each element and store it in a map as key and at value place increment its occurrence
     
                int majorityElement(vector<int>& nums) {
                    unordered_map<int,int> mp;
                    for(int i=0;i<nums.size();i++)
                        mp[nums[i]] += 1;
                    for(auto it:mp){
                        if(it.second > nums.size()/2)
                            return it.first;
                    }
                    return -1;
                }

            TC : O(N)
            SC : O(N)
    */
    
    /*
        Optimized
            WE know there is an element which is present more than n/2n/2n/2 times so keep a counter and elemnt varaible which will track if element is same as previous then counter will be incremnted else decremented.
            
            If our counter becomes 0 somewhere we will change the element because its lead is over now we will take another element (give chance to other as well) and keep doing the same with it but we will think that we might lost our element by taking the new element but no it will come again latter Since we know there is an element whose occurence is more than n/2 n/2n/2 times . So no matter What how many times will change the elemnt it will come again , either its counter will not become zero or it will come agian in lead because rest elemnts can have max n/2−1 n/2 -1n/2−1 occurence so they can't win form it.

        TC : O(N)
        SC : O(1)
    */
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == element)
                count ++;
            else if(nums[i] != element && count == 0)
                element = nums[i];
            else
                count--;
        }
        return element;
    }
};