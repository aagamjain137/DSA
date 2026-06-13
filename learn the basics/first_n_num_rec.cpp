#include <iostream>
using namespace std;

int sumN(int n) {
    if (n == 1)
        return 1;
    return n + sumN(n-1);

}
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The sum of first " << n << " numbers is: " << sumN(n) << endl;
    return 0;
}