class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach=0;
        int i=0;
        int n=nums.size();
        while(i<n){
         if(i>max_reach)return false;  
         max_reach=max(max_reach,i+nums[i]);
        i++;          
        }
        return true;
    }
};
