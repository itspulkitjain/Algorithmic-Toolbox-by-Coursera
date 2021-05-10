#include <iostream>

#include <vector>

using namespace std;

int get_fibonacci_partial_sum(long long from, long long to) {
	if(to==0)
		return 0;
	
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
	long long remt=to, qt=0, remf=from, qf=0;
	
	//for calculating the  req sum
	long long sum=1;
	//res as sum have to be calculated in steps
	long long res=1;

	//iterator
	long long i=2;
		
	//loop to calculate period and fibo seq until period
	while((i<=to)&&(i<=remt))
	{
		//calculation of fibo%m no for i
		f.push_back((f[i-1]+f[i-2])%m);

		sum=sum+f[i];
		//sum=sum%m;

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
				qt=to/period;
				remt=to%period;

				qf=from/period;
				remf=from%period;

			}
		}
		
		//inc iterator
		i++;
	}

	//sum of qt periods
	res=(sum*qt);
	//res=res%m;

	//sum of qf periods
	sum=(sum*qf);
	//sum=sum%m;

	//sum of remt fibo no
	for( i = 0; i <=remt; i++)
	{
		res=(res+f[i]);
		//res=res%m;
	}

	//sum of remf fibo no
	for( i = 0; i <remf; i++)
	{
		sum=(sum+f[i]);
		//sum=sum%m;
	}

	res =(res-sum)%m;

	return res;

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
