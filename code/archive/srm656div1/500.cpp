#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll fac[1001000];
ll inv[1001000];
ll s[1001000];
ll f[21000];
ll pow(ll a,ll x)
{
    ll now = 1;
    ll tmp = a;
    while (x)
    {
        if (x & 1) now = (now * tmp) % MOD;
        x = (x >> 1);
        tmp = (tmp * tmp) % MOD;
    }
    return now;
}
void init()
{
    fac[0] = inv[1] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        fac[i] = fac[i-1] * i % MOD;
    for (int i = 2; i <= 1000000; i++)
        inv[i] = pow(fac[i],MOD-2);
}
ll cnm(ll a,ll b)
{
    if (a < b) return 0;
    return (fac[a] * inv[b] % MOD) * inv[a-b] % MOD;
}
class PermutationCounts
{
public:
    int countPermutations(int n,vector <int> pos)
    {
        init();
        sort(pos.begin(),pos.end());
        int K = pos.size();
        for (int i = 0; i < K; i++) s[i+1] = pos[i];
        if (s[K] < n)
        {
            s[++K] = n;
        }
        f[0] = 1;
        for (int i = 1; i <= K; i++)
            for (int j = i-1; j >= 0; j--)
            {
                int flag = 1;
                if ((i - j) % 2 == 0) flag = -1;
                f[i] = (f[i] + flag * f[j] * cnm(s[i],s[i]-s[j])) % MOD;
            }
      //  printf("%lld %lld %lld\n",inv[0],fac[3],inv[3]);
        int ans = (f[K]%MOD + MOD) % MOD;
       
        return ans;
    }
};