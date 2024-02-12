class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        int element1 = nums[0];
        int count1 = 1;

        int element2 = 0;
        int count2 = 0;

        for(int i = 1; i < nums.size() ; i++ ){
            if(element1 == nums[i]) {
                count1++;
            }
            else if(element2 == nums[i]) {
                count2++;
            }
            else if(count1 == 0) {
                element1 = nums[i];
                count1++;
            }
            else if(count2 == 0) {
                element2 = nums[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(int i = 0 ; i< nums.size() ; i++) {
            if(element1 == nums[i]) count1++;
            else if(element2 == nums[i])count2++;
        }

        if(count1 > (nums.size() / 3)) ans.push_back(element1);
        if(count2 > (nums.size() / 3)) ans.push_back(element2);
        return ans;
    }
};