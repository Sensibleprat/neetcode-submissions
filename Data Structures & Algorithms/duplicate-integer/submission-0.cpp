class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        // Few approaches that I can think of - 
        // Sorting the array and making sure that if we find any value equal to it's next value until the second last value
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};