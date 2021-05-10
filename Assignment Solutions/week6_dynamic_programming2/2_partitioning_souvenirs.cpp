#include <iostream>
#include <vector>

using namespace std;

int partition3(int start, vector<int> a,vector<bool> &used, int k, int curBucketSum, int targetSum) {

  //if only one bucket is left
  if(k==1)
  {
    //return 1 as solution is possible since all buckets reached target, last bucket also reached target as total sum is divisible among k
    return 1;
  }

  //if current bucket gets full
  if(curBucketSum==targetSum)
  {
    return partition3(0, a, used, k-1, 0, targetSum);
  }
    
    

  //otherwise try items
  for(int i = start; i < a.size(); i++)
  {
    if(used[i])
    {
      continue;
    }
    if((curBucketSum+a[i])<=targetSum){
      
      used[i]=1;
      curBucketSum+=a[i];
      bool temp=partition3(i+1,a,used,k,curBucketSum,targetSum);
      
      used[i]=0;
      curBucketSum-=a[i];

      if(temp)
      {
        return 1;
      }
    }
    
  }
  
  return 0;
}

int main() {

  //Input Format:
  // The first line contains an integer n.
  int n;
  std::cin >> n;

  //for calculating total sum
  int sum=0;

  //The second line contains integers v1 , v2 , . . . , vn separated by spaces.
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
    sum=sum+a[i];
  }

  //no of friends
  int k=3;

  //if sum is not divisible by k can't distribute it in k friend's
  if(sum%k!=0)
  {
    cout<<0;
  }

  else 
  {
  //vector which stores if item is used or not
  vector<bool> used(n, 0);

  std::cout<< partition3(0,a,used,k,0,sum/k) << '\n';
  }

  return 0;
}
