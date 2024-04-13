#include <iostream>
using namespace std;
int main()
{
    string str;
    cin >> str;

    long long ans = 0;
    int dig = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            dig = str[i] - 'a' + 1;
        }
        else
        {
            dig = str[i] - 'A' + 1;
        }
        ans += dig;
    }

    cout << ans << endl;

    int num = ans;

    int sum;
    while (num >= 10)
    {
        sum = 0;
        while (num)
        {
            dig = num % 10;
            sum += dig;
            num /= 10;
        }
        num = sum;
    }

    cout << sum;

    return 0;
}