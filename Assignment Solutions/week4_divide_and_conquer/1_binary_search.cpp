#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
using namespace std;

using std::vector;

int binary_search(const vector<int> &a, int x, int left, int right) {

  //write your code here

  //base case-if only one element in array
  if(left==right){
    //if it is equal to x then return index
    if (a[left]==x)
    {
      return left;
    }
  }

  //if more than one element
  if(right>left){

    //find mid point
    int mid=(left+right)/2;

    //if middle element is equal to x return the index
    if (a[mid]==x)
    {
      return mid;
    }

    //otherwise divide array by calling two binary search
    //for left...mid-1
    if (a[mid]>x)
    {
      return binary_search(a,x,left,mid-1);
    }
    
    //and for mid+1...right
    if (a[mid]<x)
    {
      return binary_search(a,x,mid+1,right);
    }
  }

  //if result is not found -1 is returned
  return -1;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], 0, n-1) << ' ';
  }
}
