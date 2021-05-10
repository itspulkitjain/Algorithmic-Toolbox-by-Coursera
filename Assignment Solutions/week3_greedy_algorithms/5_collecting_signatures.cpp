#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

using std::vector;

struct Segment {
  int start, end;
};

bool cmp(Segment a, Segment b){
	return (a.end<b.end);}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(),segments.end(),cmp);
  int a=segments[0].end;
  points.push_back(a);
  for(int i = 0; i < segments.size(); i++)
  {
	  if(a<segments[i].start)
	  {
		  a=segments[i].end;
		  points.push_back(a);
	  }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] <<" ";
  }
}
