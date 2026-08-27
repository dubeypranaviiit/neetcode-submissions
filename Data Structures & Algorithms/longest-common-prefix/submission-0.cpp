class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
              sort(strs.begin(),strs.end());
        int n=strs.size();
        string s=strs[0];
        string t=strs[n-1];
        string ans="";
        for(int i=0;i<min(s.size(),t.size());i++){
         if(s[i]!=t[i]) return ans;
         ans+=s[i];
        }
        return ans;
    }
};