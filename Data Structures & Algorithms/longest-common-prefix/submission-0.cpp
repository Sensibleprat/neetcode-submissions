class Solution {
    void comp(string &a, string &b){
        string common_prefix = "";
        for(int i=0;i<a.size();i++){
            if(i+1 > b.size()){
                a = common_prefix;
                return;  
            }
            
            if(a[i] == b[i]) common_prefix += a[i];
            else break;
        }

        a = common_prefix;
        return;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        // pick up a pair of strings and try to find the longest common string from them. 
        // That will be called our candidate string and we'll now go on comparing that with other strings in the array and finally reach our target after scoping it further down.
        string ans = strs[0];

        int n = strs.size();
        if(n==1) return strs[0];

        for(int i=0;i<n;i++){
            comp(ans, strs[i]);
        }

        return ans;
    }
};