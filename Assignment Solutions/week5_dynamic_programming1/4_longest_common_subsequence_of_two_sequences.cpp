#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here

  int lena=a.size(), lenb=b.size();

  int l[lena+1][lenb+1];

	for(int i=0;i<=lena;i++)
	{
		for(int j=0;j<=lenb;j++)
		{
			if(i==0||j==0)
				l[i][j] = 0;
			else if(a[i-1]==b[j-1])
				l[i][j] = l[i-1][j-1] + 1;
			else
				l[i][j]=max(l[i][j-1],l[i-1][j]);
		}
	}

  return l[lena][lenb];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
