#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void largest_number(vector<string> &a, int n) {

  for(int i = 0; i < n; i++)
  {
    for(int j = i; j < n; j++)
    {
      if(a[i]+a[j]<a[j]+a[i])
      {
        swap(a[i],a[j]);
      }
    }
  }
  
}

int main() {
  //The first line of the input contains an integer n.
  int n;
  std::cin >> n;

  // The second line contains integers a1 , a2 , . . . , an .
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  largest_number(a, n);

  for(int i = 0; i < a.size(); i++)
  {
    cout<<a[i];
  }
  
}
