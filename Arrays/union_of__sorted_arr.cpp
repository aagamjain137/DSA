// #include <bits/stdc++.h>
// using namespace std;

// vector<int> sortedArray(vector<int> a, vector<int> b) {
//     int n1 = a.size();
//     int n2 = b.size();

//     set<int> st;

//     for(int i = 0; i < n1; i++)
//         st.insert(a[i]);

//     for(int i = 0; i < n2; i++)
//         st.insert(b[i]);

//     vector<int> temp;

//     for(auto it : st)
//         temp.push_back(it);

//     return temp;
// }

// int main() {
//     vector<int> a = {1,2,2,3,4};
//     vector<int> b = {2,3,4,5};

//     vector<int> ans = sortedArray(a,b);

//     for(auto x : ans)
//         cout << x << " ";

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    vector<int> ans;

    while(i < a.size() && j < b.size()) {

        if(a[i] <= b[j]) {
            if(ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        else {
            if(ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()) {
        if(ans.empty() || ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }

    while(j < b.size()) {
        if(ans.empty() || ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }

    return ans;
}

int main() {
    vector<int> a = {1,2,2,3,4};
    vector<int> b = {2,3,4,4,5};

    vector<int> ans = sortedArray(a,b);

    for(auto x : ans)
        cout << x << " ";
}