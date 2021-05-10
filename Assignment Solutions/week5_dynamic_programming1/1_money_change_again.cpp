#include <iostream>
#include <algorithm>

using namespace std;

/*
Output Format. The minimum number of coins with denominations 1, 3, 4 that changes money.
Constraints. 1 ≤ money ≤ 10 3 .*/

int get_change(int m) {
  //write your code here

  //taking denominations in an array
  //no of coins
  const int coins=3;
  //array of coins
  int coin[coins]={1, 3, 4};

  //taking value of m in money
  int money=m;

  //2d array for no of coins for all sum of money from 1....m
  int a[coins][money+1];

  //loop through all coins to fix 0 coins for sum =0
  for (int i = 0; i < coins; i++)
  {
    a[i][0]=0;
  }

  //loop through all coins
  for (int i = 0; i < coins; i++)
  {

    //loop through all sum of money from 1...m for each coin
    for (int j = 1; j <=money; j++)
    {

      //if coin value is greater than money value
      if(coin[i]>j)
      {
        /* then coins are equal to no of coins for the sum for the previous coin  */
        a[i][j]=a[i-1][j];
      }
      //if coin value is less or equal than money
      else
      {
        /* if coin is smallest coin */
        if(i==0)
        {
          //then coins = 1+ coins for prevoius sum
          a[i][j]=1+a[i][j-coin[i]];
        }
        else
        {
          //otherwise coins are minimum of coins for previous coin and 1+coins for money less than coin
          a[i][j]=min(a[i-1][j],1+a[i][j-coin[i]]);
        }
        //cout<<a[i][j]<<" ";
      }

    }

  }

  //the last entry in array gives minimum no of coins for change
  return a[coins-1][money];
}

int main() {

  //Input Format. Integer money.
  int m;
  std::cin >> m;

  //Output Format. The minimum number of coins with denominations 1, 3, 4 that changes money.
  std::cout << get_change(m) << '\n';
}
