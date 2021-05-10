#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long inversion_on_merging(vector<long long> &a, int start, int mid, int end)
{
  long long number_of_inversions=0;
    int i, j, k; 
    int n1 = mid - start+1; 
    int n2 =  end - mid; 
  
    long long L[n1], R[n2]; 
  
    for (i = 0; i <n1; i++){
        L[i] = a[start + i];
    }
    for (j = 0; j <n2; j++) {
        R[j] = a[mid + 1+ j];
    }

	  L[n1]= numeric_limits<long long>::max();
	  R[n2]= numeric_limits<long long>::max();
  
    i = 0;  
    j = 0; 
    k = start; 
    while (i<n1&&j<n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else if(L[i]>R[j])
        { 
            a[k] = R[j]; 
            j++;
            number_of_inversions+=n1-i;
        } 
        k++; 
    }
    while(i<n1){
		  a[k] = L[i];
		  i++;k++;
	  }
	  while(j<n2){
		  a[k]= R[j];
		  j++;k++;
	  }

    return number_of_inversions;

}


long long get_number_of_inversions(vector<long long> &a, int left, int right) {

  if(right<=left)
  {
    return 0;
  }
  

  long long number_of_inversions=0;


  int ave = left + (right - left) / 2;

  number_of_inversions += get_number_of_inversions(a, left, ave);

  number_of_inversions += get_number_of_inversions(a, ave+1, right);

  number_of_inversions += inversion_on_merging(a,left,ave,right);

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  std::cout << get_number_of_inversions(a, 0, a.size()-1) << '\n';
}
