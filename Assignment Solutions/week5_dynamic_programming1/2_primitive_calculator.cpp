#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using std::vector;

/*Task. Given an integer n, compute the minimum number of operations needed to obtain the number n starting from the number 1.
.*/

int eval(int op, int sum)
{
  if(op==1)
  {
    sum=sum+1;
  }
  else if(op==2)
  {
    sum=sum*2;
  }
  else if(op==3)
  {
    sum=sum*3;
  }

  return sum;
}


vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;

  //taking operands in array
  //no of operations
  int ops=3;
  //array of operations
  int op[ops]={1, 2, 3};

  //taking final result in sum
  int sum=n;

  //2d array for no of operations required
  vector<int> a(sum+1,0);

  //looping variables
  int j=0;
  
    /* loop through all the sum between 1...n */
    for(j = 2; j <= sum; j++)
    {
      a[j]= numeric_limits<int>::max();

      if((j%2) ==0)
      {
        a[j]=min(min(a[j], a[j-1]), a[j/2])+1;
      }

      if((j%3)==0)
      {
        a[j]=min(min(a[j], a[j/3]), a[j-1])+1;
      }

      if(j%2!=0 && j%3!=0)
      {
        a[j]= a[j-1] + 1;
      }
      // end if statement
    }
    //end for loop sums

//Output Format:
//In the first line, output the minimum number k of operations needed to get n from 1.
//no of minimum operations is size of sequence -1 and can be calculated only by sequence in main 

//In the second line output a sequence of intermediate numbers. That is, the second line should contain positive integers a 0 , a 2 , . . . , a k−1 such that a 0 = 1, a k−1 = n and for all 0 ≤ i < k − 1, a i+1 is equal to either a i + 1, 2a i , or 3a i . If there are many such sequences, output any one of them
//backtracking for the sequence and filling intermediate numbers in sequence using while loop

sequence.push_back(n);
  while (n>0) {
    if (n%2!=0 && n%3!=0)
    {
      n=n-1;
    }
    else if(n%2==0 && n%3==0)
    {
      n=n/3;
    }
    else if(n%3==0)
    {
      if(a[n-1]<a[n/3])
      {
        n=n-1;
      }
      else
      {
        n=n/3;
      }
    }
    else if(n%2==0)
    {
      if(a[n-1]<a[n/2])
      {
        n=n-1;
      }
      else
      {
        n=n/2;
      }
    }
    if(n>0){
    sequence.push_back(n);
    }
  }
  //cout<<a[ops-1][sum]<<endl;
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {

  //Input Format. The input consists of a single integer 1 ≤ n ≤ 10 6
  int n;
  std::cin >> n;


//Output Format:

  //sequence array for output
  vector<int> sequence = optimal_sequence(n);

  //In the first line, output the minimum number k of operations needed to get n from 1
  std::cout << sequence.size() - 1 << std::endl;

  //In the second line output a sequence of intermediate numbers. That is, the second line should contain positive integers a 0 , a 2 , . . . , a k−1 such that a 0 = 1, a k−1 = n and for all 0 ≤ i < k − 1, a i+1 is equal to either a i + 1, 2a i , or 3a i . If there are many such sequences, output any one of them
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
