class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int freq = 1;
        int maxF = 0;
        int idx = nums[0];

        for(int i = 0; i < n - 1; i++) {

            if(nums[i] == nums[i + 1]) {
                freq++;
            }
            else {
                freq = 1;
            }

            if(freq > maxF) {
                maxF = freq;
                idx = nums[i];
            }
        }

        return idx;
    }
};
