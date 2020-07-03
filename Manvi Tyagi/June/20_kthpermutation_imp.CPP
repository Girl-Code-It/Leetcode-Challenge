class Solution {
public:
    string ans;
    
    long long fact(int n){
        if(n == 1){
            return n;
        }
        
        return n * fact(n-1);
    }
    
  void helper(string &avail, int &k){
      
      cout << " call " << avail << " " << k << endl;
        //base case
        if(avail.size() == 0){
            return;
        }
        if(k == 1 || k == 0){ //crosscheck for k = 0
            ans += avail;
            return;
        }
        int n = avail.size();
        int index = (k-1)/fact(n-1); 
      
        if(index < n)
        ans += avail[index];
        
        string newavail = avail.substr(0,index);
        if(index < n-1) newavail += avail.substr(index+1);
        int newk = k - (index*fact(n-1));
        helper(newavail,newk);
    }
    
    string getPermutation(int n, int k) {
        string avail;
        for(int i = 1; i <= n; i++){
            avail += to_string(i);
        }
         helper(avail,k);
        
        return ans;
    }
};