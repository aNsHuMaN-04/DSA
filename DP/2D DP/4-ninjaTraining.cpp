#include bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& points, int day, int last)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int task = 0; task < 3; task++)
        {
            if(task != last)
                maxi = max(maxi, points[day][task]);
        }
        return maxi;
    }
    if(dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    for(int task = 0; task < 3; task++)
    {
        if(task != last)
        {
            int point = points[day][task] + solve(points, day - 1, task);
            maxi = max(maxi, point);
        }
    }
    
    dp[day][last] = maxi;
    return maxi;
}

int ninjaTraining(vector<vector<int>>& points)
{
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, n - 1, 3);
}