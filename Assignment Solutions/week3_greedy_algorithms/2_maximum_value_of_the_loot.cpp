#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

using std::min;
using std::vector;
using std::sort;
using std::endl;
struct ITEM
{
	int weight;
	int value;
	ITEM(){}
	ITEM(int a, int b){
		weight=a;
		value=b;
	}
};
bool cmp(struct ITEM a, struct ITEM b)
{
	double r1=(double)a.value/a.weight;
	double r2=(double)b.value/b.weight;
	return r1>r2;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	int n=weights.size();
	double value=0.0;
	struct ITEM arr[n];
	for(int i=0;i<n;i++)
		arr[i]=ITEM(weights[i],values[i]);
	sort(arr, arr + n, cmp);
	for(int i=0;i<n;i++)
	{
		if(capacity==0)
			return value;
		int a;
		a=min(arr[i].weight,capacity);
		value=value+a*((double)arr[i].value/arr[i].weight);
		arr[i].weight=arr[i].weight-a;
		capacity=capacity-a;
	}
	return value;
 }

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double req_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << req_value << std::endl;	
  return 0;
}
