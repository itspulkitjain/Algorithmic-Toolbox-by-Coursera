#include <iostream>
#include <vector>

using namespace std;
	
int fibonacci_sum(long long n) {
	if(n==0){
		return 0;
	}
	
	//since last digit is required
	//we'll calculate mod 10 values
	const long long m=10;

	//array to store fibo seq
	vector<long long> f;
	f.push_back(0);
	f.push_back(1);

	//period variable
	long long period=1;

	//q is how many periods occur in n
	//rem is how many extra values of fibo seq are required after q periods
	long long rem=n, q=0;
	
	//for calculating the  req sum where intial sum=f[1]=1
	long long sum=1;

	//iterator
	long long i=2;
		
	//loop to calculate period and fibo seq until period
	while(i<=n&&i<=rem)
	{
		//calculation of fibo%m no for i
		f.push_back((f[i-1]+f[i-2])%m);

		sum=sum+f[i];
		if(sum>=10)
		{
			sum=sum%10;
		}

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
					
				//value of no on periods and no of extra no
				q=n/period;
				rem=n%period;

			}
		}
		
		//inc iterator
		i++;
	}
	
	//sum of q periods
	sum=sum*q;
	if(sum>=10)
	{
		sum=sum%10;
	}

	//sum of rem fibo no
	for( i = 0; i <=rem; i++)
	{
		sum=sum+f[i];
		if(sum>=10)
		{
			sum=sum%10;
		}
	}	

	return sum;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
