#include <iostream>
#include <vector>

using namespace std;

//照準（pos)を決めて、どこに値を挿入できるのかをpos--して０になるまで見ていく.途中で[pos-1] > [pos]になった場合はswap

void ft_print(int n , vector<int> hold)
{
    for(int i = 0; i < n; i++)
    {
        cout << hold[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> hold(n);

    for(int i = 0 ; i < n; i++)
        cin >> hold[i];
    for(int k = 1; k < n; k++)
    {
        int pos = k;
        while(pos && hold[pos - 1] > hold[pos])
        {
            int temp = hold[pos - 1];
            hold[pos - 1] = hold[pos];
            hold[pos] = temp;
            pos--;
        }
        ft_print(n , hold);
    }
    return (0);
}

