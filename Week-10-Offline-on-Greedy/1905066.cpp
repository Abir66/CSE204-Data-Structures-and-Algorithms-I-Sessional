#include <iostream>
#include <algorithm>

int main()
{

    int n, k, price[100];

    std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> price[i];

    std::sort(price, price + n);

    long long int sum = 0;
    for (int i = n - 1, plant = 0, mul = 1; i >= 0; i--)
    {
        sum += mul * price[i];
        plant++;
        if (plant == k)
        {
            mul++;
            plant = 0;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}