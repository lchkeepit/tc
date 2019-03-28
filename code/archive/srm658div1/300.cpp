#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
ll bit[60];
ll ans[60];
int root[60];
map <ll,int> ok;
int so(int n,ll aa,ll bb)
{
    for (int i = 1;i < n;i++)
    {
        if (((aa & 1) ^ (bb & 1)) == 0) return 0;

        aa >>= 1;
        bb >>= 1;
    }
    return 1;
}
class OddEvenTree
{
public:
    vector <int> getTree(vector <string> x)
    {
        vector <int> res;
        ok.clear();
        for (int i = 0;i < x.size();i++)
        {
        	root[i] = 0;
        	if (x[i][i] != 'E')
        	{
        		res.push_back(-1);
        		return res;
        	}
        }
        for (int i = 0;i < x.size();i++)
        	for (int j = 0;j < x.size();j++)
        		if (x[i][j] != x[j][i])
        		{
        			res.push_back(-1);
        			return res;
        		}
        for (int i = 0;i < x.size();i++)
        {
            string tmp = x[i];
            bit[i] = 0;
            for (int j = 0;j < tmp.size();j++)
            {
                if (tmp[j] == 'E')
                    bit[i] ^= (1ll<<j);
            }
        }
        int cnt = 0;
        for (int i = 0;i < x.size();i++)
        if (ok[bit[i]] == 0)
        {
            ok[bit[i]] ++;
            cnt++;
            ans[cnt] = bit[i];
            root[cnt] = i;
        }
        if ((cnt != 2) || ((so(x.size(),ans[1],ans[2])) == 0))
        {
            res.push_back(-1);
            return res;
        }
        for (int i = 0;i < x.size();i++)
        {
         	if (bit[i] == ans[1])
         	{
         		res.push_back(i);
         		res.push_back(root[2]);
         	}  
         	if (bit[i] == ans[2] && i != root[2])
         	{
         		res.push_back(i);
         		res.push_back(root[1]);
         	}  
        }
/*        printf("%lld %lld\n",bit[0],bit[1]);
        for (int i = 0;i < res.size();i++)
        	printf("%d ",res[i]);*/
        return res;
    }

};