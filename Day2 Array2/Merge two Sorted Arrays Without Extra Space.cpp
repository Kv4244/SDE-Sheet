class Solution {
public:
    /*
        Brute force :
            -> make a new vector ans
            -> add all elements of num1 and num2 in ans
            -> sort(ans)
            -> num1 = ans

                void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                    vector<int> ans;
                    for(int i=0;i<m;i++){
                        ans.push_back(nums1[i]);
                    }
                    for(int i=0;i<n;i++){
                        ans.push_back(nums2[i]);
                    }
                    sort(ans.begin(),ans.end());
                    nums1 = ans;
                }

            TC : O( (m+n)*(log(m+n)) )
            SC : O( m+n )

    */
    /*
        Using extra space
            -> make a new vector and two pointer starting from num1 and num2 
            -> compare the pointer at each point and add number to the ans
            -> also add loop so that ans contains elements till end for both the arrays
            -> make num1 = ans

                void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                    vector<int> ans;
                    int i = 0, j = 0;
                    while(i<m && j<n){
                        if(nums1[i] < nums2[j]){
                            ans.push_back(nums1[i]);
                            i++;
                        }
                        else{
                            ans.push_back(nums2[j]);
                            j++;
                        }
                    }
                    while(i<m){
                        ans.push_back(nums1[i]);
                        i++;
                    }
                    while(j<n){
                        ans.push_back(nums2[j]);
                        j++;
                    }
                    nums1 = ans;
                }
            
            TC : O( m + n )
            SC : O( m + n )
    */
    /*
        Without extra space
            -> use 3 pointers   --> i for nums1
                                --> j for nums1
                                --> k for merged array
            -> run a loop while i>=0 && j>=0
                --> if nums1[i] > nums2[j] then  nums1[i] is in correct position
                    else    nums2 is in correct position
            -> run a loop for remaining elements in nums2

            TC : O(m+n)
            SC : O(1)
    */  
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Index of last element in nums1
        int j = n - 1;  // Index of last element in nums2
        int k = m + n - 1;  // Index of last element in the merged array

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        // If there are any remaining elements in nums2, they should be copied to nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    
};