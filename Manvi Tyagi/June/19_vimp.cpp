/* APPROACH

    string = _ _ _ _ _ _ (len = 6)
    
    Maximum possible ans = 5, 
    Minimum possible ans = 1;

    Binary Search (to find the duplicate substring length optimally in logn time)
    For example:
    1. Search for duplicate substring of length (0+6)/2 = 3 first
        a. If found
            Search for duplicate substring of length (4+6)/2 = 5 
        b. If not found 
            Search for duplicate substring of length (4+6)/2 = 5 

*/

#include <bits/stdc++.h>
using namespace std;
#define base 26
#define LL long long
#define random_prime 31
#define mod 10000007
class Solution
{
public:
    vector<int> base_pow;

    //storing all hashes for substring of length window_size in S
    int string_match(int window_size, string S)
    {
        int n = S.size();
        unordered_map<int, int> myset;
        int hash = 0;
        for (int i = 0; i < window_size; i++)
        {
            hash = (hash * 26 + (S[i] - 'a')) % mod;
        }
        myset[hash] = 0;

        for (int i = window_size; i < n; i++)
        {
            hash = ((hash - base_pow[window_size - 1] * (S[i - window_size] - 'a')) % mod + mod) % mod;
            hash = (hash * 26 + (S[i] - 'a')) % mod;
            if (myset.find(hash) != myset.end())
            {
                string temp = S.substr(myset[hash], window_size);
                string curr = S.substr(i - window_size + 1, window_size);
                if (temp.compare(curr) == 0)
                    return i - window_size + 1;
            }
            myset[hash] = i - window_size + 1;
        }

        return -1;
    }
    string longestDupSubstring(string S)
    {
        int n = S.size();
        if (n == 0)
            return S;
        int st = 1, end = n;
        base_pow.resize(n);
        base_pow[0] = 1;
        for (int i = 1; i < n; i++)
            base_pow[i] = (26 * base_pow[i - 1]) % mod;

        int start_idx_of_duplicate_string = 0;
        int len_of_longest_duplicate_string = 0;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            int match_pos = string_match(mid, S);
            if (match_pos != -1)
            {
                start_idx_of_duplicate_string = match_pos;
                len_of_longest_duplicate_string = mid;
                st = mid + 1;
            }
            else
                end = mid - 1;
        }
        return S.substr(start_idx_of_duplicate_string, len_of_longest_duplicate_string);
    }
};