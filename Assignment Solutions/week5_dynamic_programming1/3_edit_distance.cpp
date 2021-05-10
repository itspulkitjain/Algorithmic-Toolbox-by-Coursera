#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int lena=str1.length();
  int lenb=str2.length();

  int l[lena+1][lenb+1];

  for(int i=-1;i<lena;i++)
	{
		for(int j=-1;j<lenb;j++)
		{
			if(i==-1&&j==-1)
      {
				l[i+1][j+1] = 0;
      }
      else if(i==-1)
      {
        /* code */
        l[i+1][j+1]= 1+ l[i+1][j];
      }
      else if(j==-1)
      {
        /* code */
        l[i+1][j+1]=1+ l[i][j+1];
        
      }
			else if(str1[i] == str2[j])
      {
				l[i+1][j+1] = l[i][j];
        
      }
			else
      {
				l[i+1][j+1]= 1+ min( min(l[i][j], l[i+1][j]) , l[i][j+1]);
        
      }
		}
	}

  return l[lena][lenb];

}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
