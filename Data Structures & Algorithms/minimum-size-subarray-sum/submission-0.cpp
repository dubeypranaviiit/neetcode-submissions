class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     int l=0;
     int n=nums.size();
     int r=0;
     int preSum=0;
     int ans=INT_MAX;
     while(r<n){
      preSum+=nums[r];
    while(preSum>=target){
        ans=min(ans,r-l+1);
        preSum-=nums[l++];

    }
    r++;
     }
       return ans==INT_MAX ?0:ans;
    }
};