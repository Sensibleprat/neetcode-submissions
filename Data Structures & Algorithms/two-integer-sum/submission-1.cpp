class Solution {
public:
    bool replaceable(vector<int>a, vector<int>b){
        if(a[0]<b[0] || (a[0] == b[0] && a[1] < b[1])) return false;
        return true;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // // Brute force has to be just checking each pair of numbers.
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] + nums[j] == target) return {i, j};
        //     }
        // }
        // return {};
        
        // Other idea is to store all the values in an unordered_map one by one({number, number's index}). In that same iterative loop look for value "target - nums[i]" inside that same unordered hash.
        int n = nums.size();
        vector<int> ans = {n, n};
        unordered_map<int, int> numbers;

        for(int i=n-1;i>=0;i--){
            if(numbers.find(target - nums[i]) != numbers.end()){
                vector<int> prospect_ans = {i, numbers[target - nums[i]]};
                if(replaceable(ans, prospect_ans)) ans = prospect_ans;
            }
            numbers[nums[i]] = i;
        }
        return ans;
    }
};
