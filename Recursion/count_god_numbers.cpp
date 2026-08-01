#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const long long MOD = 1000000007;

    long long power(long long x, long long n)
    {
        long long ans = 1;

        while (n > 0)
        {
            if (n % 2)
                ans = (ans * x) % MOD;

            x = (x * x) % MOD;
            n /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n)
    {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};

int main()
{
    Solution obj;
    long long n;
    cout << "Enter n:";
    cin >> n;
    cout << "Answer = " << obj.countGoodNumbers(n) << endl;
}