#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;
using std::vector;
using std::string;
using std::max;
using std::min;


int n;
int siz;

long long great(long long maxVal, long long a, long long b, long long c, long long d)
{
  long long m;
  long long n;
  m=max(maxVal, a);
  n=max(b, c);
  m=max(m, n);
  m=max(m, d);
  return m;
}

long long les(long long minVal, long long a, long long b, long long c, long long d)
{
  long long m;
  long long n;
  m=min(minVal, a);
  n=min(b, c);
  m=min(m, n);
  m=min(m, d);
  return m;
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return (a*b);
  } else if (op == '+') {
    return (a+b);
  } else if (op == '-') {
    return (a-b);
  } else {
    assert(0);
  }
}


void minMax(int i, int j, vector<char> &ops, vector< vector<long long> > m, vector< vector<long long> > M, long long& minVal, long long& maxVal)
{
  minVal=numeric_limits<long long>::max();
  maxVal=numeric_limits<long long>::min();
  //cout<<"minVal= "<<minVal<<endl;
  //cout<<"maxVal= "<<maxVal<<endl;
  for(int k = i; k < j; k++)
  {
    long long a= eval( M[i][k], M[k+1][j], ops[k]);
    long long b= eval( M[i][k], m[k+1][j], ops[k]);
    long long c= eval( m[i][k], M[k+1][j], ops[k]);
    long long d= eval( m[i][k], m[k+1][j], ops[k]);
    minVal= les(minVal,a,b,c,d);
    maxVal= great(maxVal,a,b,c,d);
  }

      //cout<<"minVal= "<<minVal<<endl;
      //cout<<"maxVal= "<<maxVal<<endl;
}


long long get_maximum_value(vector<long long> no,vector<char> ops, int siz) {
  //write your code here

  vector< vector<long long> > m( (siz+1), vector<long long>(siz+1) );
  vector< vector<long long> > M( siz+1, vector<long long>(siz+1) );

 // cout<<"for ii "<<endl;
  for(int i = 0; i <=siz; i++)
  {
    m[i][i]=no[i];
    M[i][i]=no[i];
    /*cout<<"i= "<<i<<endl;
    cout<<"m= "<<m[i][i]<<endl;
    cout<<"M= "<<M[i][i]<<endl;*/
  }

  int j=0;

  for(int s = 1; s <= siz; s++)
  {
    for(int i = 0; i <= siz-s; i++)
    {
      long long minVal, maxVal;
      j=i+s;
      //cout<<"i= "<<i<<endl;
      //cout<<"j= "<<j<<endl;
      minMax(i, j, ops, m, M, minVal, maxVal);
      //cout<<"minVal= "<<minVal<<endl;
      //cout<<"maxVal= "<<maxVal<<endl;
      m[i][j]=minVal;
      M[i][j]=maxVal;
      //cout<<"m= "<<m[i][j]<<endl;
      //cout<<"M= "<<M[i][j]<<endl;
    }
  }
  
  return M[0][siz];
}

int main() {
  string s;
  std::cin >> s;

  n=s.size();
  //cout<<"n= "<<n<<endl;
  

  vector<long long> no;
  vector<char> ops;

  for(int i = 0; i <n; i++)
  {
    if(i%2==0)
    {
      no.push_back(s[i]-'0');
    }
    else{
      ops.push_back(s[i]);
    }
  }

  int siz=(n-1)/2;

  /*for(int i = 0; i <=siz; i++)
  {
    cout<<"no["<<i<<"] = "<<no[i]<<endl;
  }
  for(int i = 0; i <siz; i++)
  {
    cout<<"ops["<<i<<"] = "<<ops[i]<<endl;
  }*/

  std::cout << get_maximum_value(no, ops, siz) << '\n';

  return 0;
}
