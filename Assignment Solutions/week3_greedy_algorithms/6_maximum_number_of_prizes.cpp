#include <iostream>
#include <vector>
using namespace std;

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  for(int i=1; i<=n;i++){
	  if(n-i>i){
		  summands.push_back(i);
		  n=n-i;
	  } 
	  else if(n-i==0){
		  summands.push_back(i);
		  n=n-i;
	  }
	  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
