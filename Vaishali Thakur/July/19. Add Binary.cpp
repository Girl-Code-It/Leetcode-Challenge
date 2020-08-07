class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        char carry = '0';
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 && j >= 0){
            if(a[i] == '1' && b[j] == '1'){
                if(carry == '0'){
                    s += '0';
                    carry = '1';
                } else {
                    s += '1';
                }
            } else if(a[i] == '0' && b[j] == '0'){
                if(carry == '0'){
                    s += '0';
                } else {
                    s += '1';
                    carry = '0';
                }
            } else {
                if(carry == '0'){
                    s += '1';
                } else {
                    s += '0';
                }
            }
            i--;
            j--;
        }
        
        while(i >= 0){
            if(a[i] == '1'){
                if(carry == '0'){
                    s += '1';
                } else {
                    s += '0';
                }
            } else {
                if(carry == '0'){
                    s += '0';
                } else {
                    s += '1';
                    carry = '0';
                }
            }
            i--;
        }
        
        while(j >= 0){
            if(b[j] == '1'){
                if(carry == '0'){
                    s += '1';
                } else {
                    s += '0';
                }
            } else {
                if(carry == '0'){
                    s += '0';
                } else {
                    s += '1';
                    carry = '0';
                }
            }
            j--;
        }
        
        if(carry == '1')
            s += carry;
        reverse(s.begin(), s.end());
        return s;
    }
};