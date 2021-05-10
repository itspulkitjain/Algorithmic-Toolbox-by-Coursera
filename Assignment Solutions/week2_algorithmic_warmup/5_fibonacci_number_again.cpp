#include <iostream>
#include <vector>

using namespace std;
/*
For m = 2, the period
is 011 and has length 3, while for m = 3 the period is 01120221 and has length 8. Therefore, to compute,
say, F 2015 mod 3 we just need to find the remainder of 2015 when divided by 8. Since 2015 = 251 · 8 + 7, we
conclude that F 2015 mod 3 = F 7 mod 3 = 1.
This is true in general: for any integer m ≥ 2, the sequence F n mod m is periodic. The period always
starts with 01 and is known as Pisano period.
**/

long long get_fibonacci_huge(long long n, long long m) {
	//array to store fibo seq
		vector<long long> f;
		f.push_back(0);
		f.push_back(1);

		//period variable
		long long period=1;

		//iterator
		long long i=2;
		
		//loop to calculate period and fibo seq until period
		while(i<=n)
		{
			//calculation of fibo%m no for i
			f.push_back((f[i-1]+f[i-2])%m);

			//Checking if fibo seq has start repeating
			//if current f is 0
			if(f[i]==0)
			{
				//check next no
				long long next=(f[i]+f[i-1])%m;
				//if 1
				if(next==1)
				{
					//period is current i
					period=i;
					
					//value of new reduced n acc pisano period
					n=n%period;
				}
			}
			i++;
		}

		//return
		return f[n];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
	long long o=get_fibonacci_huge(n,m);
	std::cout<<o;
	return 0;
}
