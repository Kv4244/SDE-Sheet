class Solution {
public:
    // ** 7 approaches are presented here **
    /*
        1. Sort 
            int findDuplicate(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                for(int i=0;i<nums.size()-1;i++){
                    if(nums[i] == nums[i+1])
                        return nums[i];
                }
                return -1;
            }

            TC : O(n log(n))
            SC : O(1)
        2. Set
            int findDuplicate(vector<int>& nums) {
                unordered_set<int> us;
                for(int i=0;i<nums.size();i++){
                    int size = us.size();
                    us.insert(nums[i]);
                    if(us.size() == size)
                        return nums[i];
                }
                return -1;
            }

            TC : O(n)
            SC : O(n)
            
        3.Negative Marking
            int findDuplicate(vector<int>& nums) {
                for(int i=0;i<nums.size();i++){
                    int index = abs(nums[i]);
                    if(nums[index] < 0)
                        return index;
                    else
                        nums[index] *= -1;
                }
                return -1;
            }

            TC : O(n)
            SC : O(1)
    }


        
    */

    
    int findDuplicate(vector<int>& nums) {
        
    }

};
