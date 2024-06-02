#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

using namespace std;

void ft_print(vector<int> hold , int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << hold[i] << " ";
    }
    cout << endl;
}
int main(void)
{
    int n;
    cin >> n;
    vector<int>hold (n);

    for(int i = 0; i < n; i++)
        cin >> hold[i];

    for(int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for(int j = n -1; j > i; j-- )
        {
            if(hold[j - 1] > hold[j])
            {
                flag = true;
                int temp = hold[j];
                hold[j] = hold[j - 1];
                hold[j - 1] = temp;
            }
        }
        if(flag)ft_print(hold , n);
        else break;
    }
}

