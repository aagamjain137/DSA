#include <iostream>
using namespace std;

int fact(int n){
    if(n ==0 || n ==1)
        return 1;
    return fact(n-1) * n;
}
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "the factorial of " << n <<" is: "<< fact(n) << endl;
    return 0;
}