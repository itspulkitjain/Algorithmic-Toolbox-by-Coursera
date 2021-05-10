#include <iostream>
using namespace std;

long long EuclideanGCD(int a, int b) {
	int c;
	if(b==0)
		return (long long) a;
	else{
		int a1=a%b;
		return EuclideanGCD(b,a1);}
}

	long long lcm_fast(int a, int b) {
	long long c;
	c = EuclideanGCD(a,b);
	long long d,e,f;
	d = b/c;
	e = a/c;
	f=d*e*c;
	return f;
}
		
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b);
  return 0;
}
