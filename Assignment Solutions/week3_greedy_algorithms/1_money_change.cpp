#include <iostream>
using namespace std;

int get_change(int m) {
	int ReqChange=0;
	if(m>=10)
	{
		ReqChange=m/10;
		m=m%10;
	}
	if(m>=5)
	{
		ReqChange++;
		m=m-5;
	}
	ReqChange+=m;
	return ReqChange;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
