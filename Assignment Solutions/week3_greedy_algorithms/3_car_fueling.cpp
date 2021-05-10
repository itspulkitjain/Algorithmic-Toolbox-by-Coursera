#include <iostream>
#include <vector>
using namespace std;

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, int n, vector<int> & stops) {
	if(dist<=tank){
		return 0;
	}
	int numRefill=0, currentRefill=0;
	while(currentRefill<n)
	{
		int lastRefill=currentRefill;
		while(currentRefill<n){
			if((stops[currentRefill+1]-stops[lastRefill])<=tank)
			{
				currentRefill++;
			}
			else 
			{
				break;
			}
		}	
		if(lastRefill==currentRefill)
			return -1;
		if(currentRefill<=n)
			numRefill++;
	}
    return numRefill;
}


int main() {
    int d,m,n;
	cin>>d;
	cin>>m;
	cin>>n;

    vector<int> stops(n+1);
	stops.at(0)=0;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);
    cout << compute_min_refills(d, m, n, stops) << "\n";
    
	return 0;
}