#include <iostream>
#include <vector>

using namespace std;



void ft_print(vector<int> hold , int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << hold[i] << " ";
    }
    cout << endl;
}
void quickSort(vector <int> &hold , int left , int right) 
{
    if(right - left <= 1)
        return;
    int pivot_index = (left + right) / 2;
    int pivot = hold[pivot_index];
    swap(hold[pivot_index] , hold[left]);
    int i = left + 1;
    for(int j = left + 1; j < right; j++)
    {
        if(hold[j] < pivot)
        {
            swap(hold[i] , hold[j]);
            i++;
        }
    }

    swap(hold[left] , hold[i - 1]);
    //ft_print(hold, hold.size());
    quickSort(hold, left, i - 1);
    quickSort(hold, i, right);
}
int main(void)
{
    int n;
    cin >> n;
    vector<int> hold(n);
    //vector<int> hold = {10 , 12 , 15 , 3 , 8 , 1 , 17 , 4 , 1};
    for(int i = 0; i < n; i++) 
        cin >> hold[i];
    quickSort(hold , 0 , n);
    ft_print(hold, hold.size());
    return (0);
}
