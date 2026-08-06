#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int mini=0, maxi=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            mini++;
            maxi++;
        }
        else if(s[i] == ')'){
            mini--;
            maxi++;
        }
        else{
            mini--;
            maxi++;
        }
        if(mini < 0) mini = 0;
        if(maxi < 0) return false;
    }
    return mini == 0;
}
int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    if(isValid(s)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}