class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        int set; 

        vector<int> v(2, 0);
        for(int i = 1; i < n; i++)  
            x ^= nums[i];  

        set = x & ~ (x - 1);  

        for(int i = 0; i < n; i++) {  
            if(nums[i] & set)  
                v[0] = v[0] ^ nums[i]; 
            else
                v[1] = v[1] ^ nums[i]; 
        } 
        return v;
    }
};