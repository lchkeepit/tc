#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
double f[310][310];
double a[310];
int n;
class RandomPancakeStack
{
    public :
        double dfs(int i,int j)
        {
            if (i == n || j == 1) return f[i][j] = 0;
            if (f[i][j]) return f[i][j];
            double &res = f[i][j];
            for (int ii = 1;ii < j;ii++)
                res += dfs(i+1,ii) + a[ii];
            res /= n - i;
            return res;
        }
        double expectedDeliciousness(vector <int> d)
        {
        	memset(f,0,sizeof f);
        	n = d.size();
            for (int i = 0;i < d.size();i++) a[i+1] = d[i];
            return dfs(0,n+1);

        }
};