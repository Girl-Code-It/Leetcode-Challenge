class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int arr[32];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                if(nums[i] & (1 << j))
                    arr[j]++;
            }
        }
        
        for(int i = 0; i < 32; i++){
            cout << arr[i] << " ";
            arr[i] %= 3;
            if(arr[i]) 
                ans += (1 << i);
        }
        return ans;
    }
};