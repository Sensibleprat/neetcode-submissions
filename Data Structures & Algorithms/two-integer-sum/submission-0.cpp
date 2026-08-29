class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute force has to be just checking each pair of numbers.
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};
        // if a 
    }
};
