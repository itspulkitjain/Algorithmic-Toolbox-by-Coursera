#include <iostream>
using namespace std;

int EuclideanGCD(int a, int b) {
	if(b==0)
		return a;
	else{
		int a1=a%b;
	return EuclideanGCD(b,a1);}
}
//int main() {
  /*int a, b;
  std::cin >> a >> b;
  std::cout << EuclideanGCD(a, b) << std::endl;
  return 0;*/
  
//}

#include <stdio.h>
#include <iostream>

using std::cout;

int main()
{
    int a = 339;

    char b = a;

    char c = (char)a;

    int d = (int)b;

    int e = a & 0xff;

    cout << a << " " << b << " " << c << " " << d << " " << e << std::endl;
}
