class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        // Few approaches that I can think of - 

        // // Sorting the array and making sure that if we find any value equal to it's next value until the second last value
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<n-1;i++){
        //     if(nums[i] == nums[i+1]) return true;
        // }
        // return false;

        // This approach will maintain a unordered_set and if any value that was already in the set shows up, we'll return true, false otherwise
        // S.C. - O(n)
        // T.C. - O(n)
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(s.contains(nums[i])) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};