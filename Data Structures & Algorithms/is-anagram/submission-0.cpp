class Solution {
public:
    bool isAnagram(string s, string t) {
        // Couple of approaches that I can think of
        // BruteForce Solution:
        // Maintain an array for each element of second string. Now iterate over the first string element one by one and try to find whether there is any same alphabet in second string which has not been visited before. 
        // If yes, mark that as visited and move on. If absent return false directly.

        // Other probable solution would be to have two arrays, one for each string, of size 26(lowercase English letters). 
        // I'll iterate over each string and go on incremeting the frquency for that element. 
        // And finally make sure to match these values across these two arrays and return false as soon as I see any inequality.

        // Further optimisation in this will be to use just a single array and make sure no value goes to below zero while decrementing the frequency map array built from first string onto second string.
        int len_s = s.size(), len_t = t.size();
        if(len_s != len_t) return false;

        vector<int>frequency_map(26, 0);

        for(int i=0;i<len_s;i++){
            frequency_map[s[i]-'a']++;
        }

        for(int i=0;i<len_t;i++){
            frequency_map[t[i]-'a']--;
            if(frequency_map[t[i]-'a'] < 0) return false;
        }        

        for(int i=0;i<frequency_map.size();i++){
            if(frequency_map[i] != 0) return false;
        }

        return true;
    }
};
