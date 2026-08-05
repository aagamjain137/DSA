#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k){
        vector<int> hash(26, 0);
        int l = 0, r = 0;
        int maxfreq = 0, maxlen = 0;
        while (r < s.size())
        {
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r] - 'A']);
            while ((r - l + 1) - maxfreq > k)
            {
                hash[s[l] - 'A']--;
                maxfreq = 0;
                for (int i = 0; i < 26; i++)
                {
                    maxfreq = max(maxfreq, hash[i]);
                }

                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
}
int main()
{
    string s;
    int k;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Length of the longest substring after replacement = " << characterReplacement(s, k);
    return 0;
}
