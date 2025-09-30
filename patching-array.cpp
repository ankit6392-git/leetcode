class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long reach=1,patch=0,i=0;
        while(reach<=n){
            if(i<nums.size()&&nums[i]<=reach){
                reach+=nums[i];
                i++;
            }
            else{
                reach+=reach;
                patch++;
            }
        }
       return patch;
    }
};
