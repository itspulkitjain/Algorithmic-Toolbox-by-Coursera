#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

/*Task. The goal in this code problem is to check whether an input sequence contains a majority element.

Constraints. 1 ≤ n ≤ 10 5 ; 0 ≤ a i ≤ 10 9 for all 0 ≤ i < n.
*/

//to check count of element in subarray
int count_maj(vector<int> &a, int left, int right, int maj)
{
  //initialise count to 0
  int count=0;

  //loop through the array
  for (int i = left; i <= right; i++)
  {
    //if a[i] is same as major element increase the count
    if (a[i]==maj)
    {
      count++;
    }
  }

  //return the count of major element
  return count;
}

//get_majority_element returns the majority element
int get_majority_element(vector<int> &a, int left, int right) {

  //if only one element then always majority
  //if two elements and both are same then majority
  //when different anyone can be majority
  if (left==right||left+1==right){
    return a[left];
  }

  //if more than two elements
  if (left+1<right)
  {
    //calculate the middle index
    int mid=(right-left)/2 + left;

    //divide the array in subarrays left...mid and mid+1...right
    int left_major=get_majority_element(a,left,mid);
    int right_major=get_majority_element(a, mid+1, right);

    //if both sub array has same major element
    if (left_major==right_major)
    {
      /* then return that major element */
      return left_major;
    }
    
    //otherwise calculate count of major elements in whole array
    int left_count=count_maj(a,left,right,left_major);
    int right_count=count_maj(a,left,right,right_major);
    
    //return the element with greater count 
    return (left_count > right_count ? left_major : right_major);
  }

}

int main() {

  //Input Format
  //The first line contains an integer n,
  int n;
  std::cin >> n;

  //the next one contains a sequence of n non-negative integers a 0 , a 1 , . . . , a n−1.
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  //Output Format. Output 1 if the sequence contains an element that appears strictly more than n/2 times, and 0 otherwise.
  //call get_majority_element for majority element
  int element=get_majority_element(a, 0, a.size()-1);
  //now calculate it's count
  int count=count_maj(a,0,n-1,element);
  //if count is greater than n/2
  if(count>n/2)
  {
    //then sequence contain majority element thus return 1
    cout<<"1";
  }
  else
  {
    //otherwise no majority element return 0
    cout<<"0";
  }

  return 0;
}
