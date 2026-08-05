#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s){
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int l=0, r=0;
    while(l<m && r<n){
        if(g[r] <= s[l]){
            r++;
        }
        l++;
    }
    return r;
}
int main(){
    int n,m;
    cout << "Enter the number of children: ";
    cin >> n;
    vector<int> g(n);
    cout << "Enter greed factors :";
    for(int i=0;i<n;i++){
        cin >> g[i];
    }

    cout << "Enter the number of cookies: ";
    cin >> m;
    vector<int> s(m);
    cout << "Enter cookie sizes :";
    for(int i=0;i<m;i++){
        cin >> s[i];
    }
    cout << "Maximum number of content children: " << findContentChildren(g, s) << endl;
    return 0;
}