class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUnique=0;
        int n=nums.size();
         for(int i=1;i<n;i++){
            if(nums[i]!=nums[lastUnique]){
                lastUnique++;
                swap(nums[i],nums[lastUnique]);
            }
         }
         return lastUnique+1;

    }
};