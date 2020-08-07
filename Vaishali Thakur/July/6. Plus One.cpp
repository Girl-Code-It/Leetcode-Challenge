class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1;
        vector<int> v;
        for(int i = n - 1; i >= 0; i--){
            int sum = digits[i] + carry;
            carry = sum / 10;
            v.push_back(sum % 10);
        }
        if(carry) v.push_back(carry);
        reverse(v.begin(), v.end());
        return v;
    }
};