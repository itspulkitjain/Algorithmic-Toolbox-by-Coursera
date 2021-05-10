#include <iostream>
#include <vector>
using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	long long first=0, second;
	for (int i = 0; i < n; ++i){
		if(numbers[i]>first){
			second=first;
			first=numbers[i];}
		else if(numbers[i]>second){
			second=numbers[i];}
	}
	max_product=first*second;
	return max_product;
}
int main(){
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
	long long result=MaxPairwiseProduct(numbers);
    std::cout<<result;
    return 0;
}
