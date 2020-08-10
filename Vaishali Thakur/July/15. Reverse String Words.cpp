class Solution {
public:
    string reverseWords(string S) {
        string ans;
        int s = 0, e = S.size();

        while(s < e){
            while(s < e && S[s] == ' ') 
                s++;
            if(s >= e) 
                break;
            int i = s + 1;
            while(i < e && S[i] != ' ') 
                i++;
            string str = S.substr(s, i - s);
            if(ans.size() == 0) 
                ans = str;
            else 
                ans = str + " " + ans;
            s = i + 1;
        }
        return ans;
    }
};