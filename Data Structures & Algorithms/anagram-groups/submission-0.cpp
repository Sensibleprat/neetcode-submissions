class Solution {
    vector<vector<string>> output(unordered_map<string, vector<int>> mp, vector<string>& strs){
        vector<vector<string>> ans;

        for(auto x:mp){
            vector<string> anagram;
            for(int i=0;i<x.second.size();i++){
                anagram.push_back(strs[x.second[i]]);
            }
            ans.push_back(anagram);
        }

        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Brute Force Approach
        * We'll maintain a 26 sized array for each string and will 
        * keep on noting down the frequency map for each string. 
        * At the end, we can compare those arrays among themselves.
        */
        
        /*
        Optimisation 1:
        * We are basically maintaing what the dumb-ed down version of string looks like
        * and that simplified version will anyday look same. 
        * Talking about Simplified, we can simplify the same strings by sorting them first
        * before comparing them among themselves.
        * Once each string is sorted, we can start off with a map and it will maintain a 
        * sorted_string -> [index...] key-value mapping in itself which will signify the 
        * sorted string and the indexes of strings that have that mapping. 
        * Finally we'll print in combination the strings at those indexes.
        */
        unordered_map<string, vector<int>> mp;
        
        for(int i=0;i<strs.size();i++){
            string base_string = strs[i];
            sort(base_string.begin(), base_string.end());
            mp[base_string].push_back(i);
        }

        return output(mp, strs);
    }
};
