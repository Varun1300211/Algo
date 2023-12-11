#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
int vis[1003][1003];
int visNum[1003 * 1003];

struct node
{
    int num;
    vector<int> dir;
};

vector<struct node> data;

/*
    1    2     3    4
    up right down right
*/

void dfs(int parent, vector<int> ansArray)
{
    // ansArray.push_back(parent);
    visNum[parent] = 1;
    if (parent == n * m)
    {
        for (auto x : ansArray)
        {
            cout << x << " ";
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (data[parent].dir[i] == 1)
        {
            if (i == 0)
            {
                int newCurr = parent - m;
                if (visNum[newCurr] == 0 && 1 <= newCurr && newCurr <= n * m)
                {
                    vector<int> newArr = ansArray;
                    newArr.push_back(newCurr);
                    dfs(newCurr, newArr);
                }
            }

            if (i == 1)
            {
                int newCurr = parent + 1;
                if (visNum[newCurr] == 0 && 1 <= newCurr && newCurr <= n * m)
                {
                    vector<int> newArr = ansArray;
                    newArr.push_back(newCurr);
                    dfs(newCurr, newArr);
                }
            }

            if (i == 2)
            {
                int newCurr = parent + m;
                if (visNum[newCurr] == 0 && 1 <= newCurr && newCurr <= n * m)
                {
                    vector<int> newArr = ansArray;
                    newArr.push_back(newCurr);
                    dfs(newCurr, newArr);
                };
            }

            if (i == 3)
            {
                int newCurr = parent - 1;
                if (visNum[newCurr] == 0 && 1 <= newCurr && newCurr <= n * m)
                {
                    vector<int> newArr = ansArray;
                    newArr.push_back(newCurr);
                    dfs(newCurr, newArr);
                }
            }
        }
    }
}

void solve()
{
    ans.clear();
    memset(vis, -1, sizeof(vis));
    cin >> n >> m;
    int arr[n + 1][m + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    struct node temp;
    temp.num = 0;
    vector<int> tempArr;
    tempArr.push_back(0);
    tempArr.push_back(0);
    tempArr.push_back(0);
    tempArr.push_back(0);

    temp.dir = tempArr;

    data.assign(n * m + 1, temp);

    for (int i = 1; i <= n * m; i++)
    {
        cin >> data[i].num;
        for (int j = 0; j < 4; j++)
        {
            int x;
            cin >> x;
            data[i].dir[j] = x;
        }
    }

    vector<int> ansfinal;
    ansfinal.push_back(1);
    dfs(1, ansfinal);
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
  //  ios_base::sync_with_stdio(0);
   // cin.tie(NULL);
    //cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}