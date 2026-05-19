// class Solution {
// public:
// int f(int idx, string &s, vector<int>& dp) {
  
//     if (idx == s.size()) return 1; 
//     if (idx > s.size()) return 0;
//     if (dp[idx] != -1) return dp[idx]; 
//     if (s[idx] == '0') return dp[idx] = 0; 
//     int take1 = f(idx + 1, s, dp); 
//     int take2 = 0;
//     if (idx + 1 < s.size() && (s[idx]=='1' || s[idx]=='2' && s[idx+1]<='6')) {
//             take2 = f(idx + 2, s, dp);
        
//     }
    //  we can write like this 
//     if (idx + 1 < s.size()) {
//     int value = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
//     if (value >= 10 && value <= 26) {
//         take2 = f(idx + 2, s, dp);
//     }
// }
//     return dp[idx] = take1 + take2; 
// }
//     int numDecodings(string s) {
//         int n=s.size();
//         vector<int>dp(n+1,-1);
//         int ans=f(0,s,dp);
//         return ans;
//     }



class Solution {
public:


      int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;

          for(int idx=n-1;idx>=0;idx--){
       if (s[idx] == '0') {
         dp[idx] = 0; 
         continue;
       }
     int take1 = dp[idx+1]; 
     int take2 = 0;
     if (idx + 1 < s.size() && (s[idx]=='1' || s[idx]=='2' && s[idx+1]<='6')) {
            take2 = dp[idx+2];
        
     }
    dp[idx]=take1+take2;
          }
        return dp[0];
    }
};