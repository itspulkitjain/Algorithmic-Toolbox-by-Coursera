#include <iostream>
#include <vector>

using namespace std ;


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
   
  int lena=a.size(), lenb=b.size(), lenc=c.size();

  int l[lena+1][lenb+1][lenc+1];

	for(int i=0;i<=lena;i++)
	{
		for(int j=0;j<=lenb;j++)
		{
      for(int k = 0; k <=lenc; k++)
      {
        if(i==0||j==0||k==0){
          l[i][j][k] = 0;
        }
			  else if(a[i-1]==b[j-1]&&a[i-1]==c[k-1]){
				  l[i][j][k] = l[i-1][j-1][k-1] + 1;
        }
			  else{
				  l[i][j][k]=max(max(l[i][j-1][k],l[i-1][j][k]), l[i][j][k-1]);
        }
      }
		}
	}

  return l[lena][lenb][lenc];

}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
