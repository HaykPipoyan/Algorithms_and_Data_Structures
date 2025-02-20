class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i < size1 && j < size2){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            } else if(nums1[i] < nums2[j]){
                ++i;
            } else {
                ++j;
            }
        }
        return -1;
    }
};
