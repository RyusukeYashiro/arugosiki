#include <type_traits>
#include <vector>
#include <iostream>

using namespace std;



void ft_print(vector<int> hold , int n)
{
   for(int i = 0; i < n; i++) 
       cout << hold[i] << " ";
   cout << endl;
}
int main(void)
{
    int n = 5; cin >> n;
    vector<int> hold(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> hold[i];
    }
    
    for(int i = 0 ; i < n - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < n; j++)
        {
            if(hold[min_index] > hold[j])
                min_index = j;
        }
         if(min_index != i)
         {
             int temp = hold[min_index];
             hold[min_index] = hold[i];
             hold[i] = temp;
         }     
         ft_print(hold , n);
     }
}


