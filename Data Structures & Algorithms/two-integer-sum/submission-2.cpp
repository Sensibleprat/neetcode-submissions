class Solution {
public:
    bool replaceable(vector<int>a, vector<int>b){
        if(a[0]<b[0] || (a[0] == b[0] && a[1] < b[1])) return false;
        return true;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // // Brute force has to be just checking each pair of index_of.
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
        unordered_map<int, int> index_of;

        for(int i=0;i<n;i++){
            int first_number = target - nums[i];
            if(index_of.find(first_number) != index_of.end()){
                return {index_of[first_number], i};
            }
            index_of[nums[i]] = i;
        }
        return ans;
    }
};
