class Solution {
public:
    /*
        Brute Force :
            Traverse through each element and at each element traverse through the array and check its count

            vector<int> majorityElement(vector<int>& nums) {
                int n = nums.size(), check = floor(n/3);
                vector<int> ans;
                unordered_set<int> us;
                for(int i=0;i<n;i++){
                    int element = nums[i], count = 0;
                    if(us.find(element) != us.end())
                        continue;
                    for(int j=0;j<n;j++)
                        if(nums[j] == element) count++;
                    if(count > check){
                        us.insert(element);
                        ans.push_back(element);
                    }
                }
                return ans;
            }

            TC : O(N x N)
            SC : O(N) + O(N)    // ans + us
    */
    /*
        Using map : 

            vector<int> majorityElement(vector<int>& nums) {
                int n = nums.size(), check = floor(n/3);
                vector<int> ans;
                unordered_map<int,int> ump;
                for(int i=0;i<n;i++)
                    ump[nums[i]]++;
                for(auto it:ump){
                    if(it.second > check)
                        ans.push_back(it.first);
                }
                return ans;
            }

            TC : O(N)
            SC : O(N) + O(N) // ans + map
    */
    /*
        Most optimal : Moore's Vooty Algorithm
            See Video for explanation
        TC : O(N)
        SC : O(1)

    */
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), check = floor(n/3);
        int count1 = 0, element1 = 1e9+2, count2 = 0, element2 = 1e9+3;
        for(int i=0;i<n;i++){
            if(count1 == 0 && nums[i] != element2){
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != element1){
                count2 = 1;
                element2 = nums[i];
            }
            else if(nums[i] == element1)
                count1++;
            else if(nums[i] == element2)
                count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == element1) count1++;
            if(nums[i] == element2) count2++;
        }
        if(count1 > check && count2 > check)
            return {element1,element2};
        else if(count1 > check)
            return {element1};
        else if(count2 > check)
            return {element2};
        else 
            return {};
    }
};