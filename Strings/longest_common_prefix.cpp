#include<bits/stdc++.h>
using namespace std;

string LongestCommonPrefix(vector<string>& strs){
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size() - 1];
    string ans = "";
    int len = min(first.size(), last.size());

    for(int i=0;i<len;i++){
        if(first[i] == last[i]){
            ans += first[i];
        }else{
            break;
        }
    }
    return ans;
}
int main(){
    int n;
    cout << "enter the number of strings:" ;
    cin >> n;

    vector<string>  strs(n);
    cout << "Enter Strinf\n";
    for(int i=0;i<n;i++){
        cin >> strs[i];
    }
    cout << "Longest Common Prefix : " << LongestCommonPrefix(strs);
    return 0;

}