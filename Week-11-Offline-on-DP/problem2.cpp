#include <iostream>

int INF = 1000000000;

int bit(int mask, int i) { return mask & 1 << i; }
int clearBit(int mask, int i) { return mask & ~(1 << i); }

int calculateCost(int mask, int n, int c[])
{
    int cost = 0;
    for (int i = 0; i < n; i++)
        if (bit(mask, i)) cost += c[i];
    return cost;
}

int main()
{
    int n, c[10][10], dp[1024];
    
    std::cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> c[i][j];
    
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int cost = INF;
        for (int j = 0; j < n; j++)
            if (bit(mask, j)) cost = std::min(cost, calculateCost(mask, n, c[j]) + dp[clearBit(mask, j)]);
        
        dp[mask] = cost;
    }

    std::cout << dp[(1 << n) - 1] << std::endl;

    return 0;
}
