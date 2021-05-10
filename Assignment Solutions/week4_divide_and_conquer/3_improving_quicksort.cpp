#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

using std::vector;
using std::swap;

/*Task. To force the given implementation of the quick sort algorithm to efficiently process sequences with
few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new partition procedure should partition the array into three parts: < x part, = x part, and > x part.

Constraints. 1 ≤ n ≤ 10 5 ; 1 ≤ a i ≤ 10 9 for all 0 ≤ i < n.
------inside limits of int
.*/

void partition3(vector<int> &a, int l, int r, int &start, int &end) {
  
  //forward pointer
  start =l;
  //backward pointer
  end=r;
  //pivot element
  int pivot=a[l];

  //forward loop for placing all elements less than pivot in start
  for (int i = l; i <=r; i++)
  {
    //if element is less than pivot
    if (a[i]<pivot)
    {
      //it is swaped to start
      swap(a[i],a[start]);
      //start element is incremented to increase lenght of lesser array
      start++;
    }
  }

  //backward loop for placing all elements more than pivot in end
  for (int i = r; i >= l; i--)
  {
    //if element is more than pivot
    if (a[i]>pivot)
    {
      //swap it to end
      swap(a[i],a[end]);
      //and decrement end pointer
      end--;
    }

    //since we have already arranged all elements less than pivot in start
    //if element is less than pivot
    if (a[i]<pivot)
    {
      //break the loop
      break;
    }
  }

}


void randomized_quick_sort(vector<int> &a, int l, int r) {

  //sorting is done only when array have two or more elements
  if (r>l)
  {
    //two parameters for passing in partition which returns
    //start of the elements equal to pivot
    int start=0;
    //end of the elements equal to pivot
    int end=0;
    //selecting random pivot and swaping it to start
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);

    //calling partition3 function for partitions
    partition3(a, l, r, start, end);

    //recursively calling quick_sort function for start array and end array
    randomized_quick_sort(a, l, start-1);
    randomized_quick_sort(a, end+1, r);
  }

}

int main() {

  //Input Format:
  //The first line of the input contains an integer n.
  int n;
  std::cin >> n;
  // The next line contains a sequence of n integers  a 0 , a 1 , . . . , a n−1 .
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  //calling sort function
  randomized_quick_sort(a, 0, n-1);

  //Output Format:
  // Output this sequence sorted in non-decreasing order
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }

}
