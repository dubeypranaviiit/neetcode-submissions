class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int nRotate=k%n;
        reverse(nums.begin(),nums.begin()+n-nRotate);
        reverse(nums.begin()+n-nRotate,nums.end());
        reverse(nums.begin(),nums.end());
    }
};