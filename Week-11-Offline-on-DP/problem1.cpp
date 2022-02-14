#include <iostream>
#include <cstring>

int lcs(char *x, char *y, char *r)
{

    int L[50][50] = {0}, m = strlen(x), n = strlen(y);

    // constructing table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int len = L[m][n];
    r[len] = '\0';

    // constructing lcs
    for (int i = m, j = n; i > 0 && y > 0;)
    {
        if (x[i - 1] == y[j - 1] && L[i - 1][j - 1] == L[i][j] - 1)
        {
            r[--len] = x[i - 1]; // going diagonal
            i--;
            j--;
        }

        else if (L[i - 1][j] >= L[i][j - 1]) i--; // going up
        else j--; //  going left
    }
    return L[m][n];
}

int main()
{
    char x[51], y[51], r[51];

    std::cin >> x >> y;

    std::cout << lcs(x, y, r) << std::endl;
    std::cout << r << std::endl;

    return 0;
}
