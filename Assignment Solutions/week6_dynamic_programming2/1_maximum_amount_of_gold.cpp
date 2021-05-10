#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using std::vector;

int knapsack(int capacity, vector<int> weight, int n)
{
  vector<vector<int>> a(n, vector<int>(capacity+1));

  for(int i = 0; i < n; i++)
  {
    for(int w = 0; w <= capacity; w++)
    {
      if(i==0)
      {
        if(weight[i]>w)
        {
          a[i][w]=0;
        }
        else
        {
          a[i][w]=weight[i];
        }
      }
      else if(weight[i]>w)
      {
        a[i][w]=a[i-1][w];
      }
      else
      {
        a[i][w]=max(a[i-1][w],weight[i]+a[i-1][w-weight[i]]);
      }
      
    }
  }
  
  return a[n-1][capacity];



}

int main() {
  int n, capacity;
  std::cin >> capacity >> n;
  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    std::cin >> weight[i];
  }
  std::cout << knapsack(capacity, weight, n) << '\n';
}
