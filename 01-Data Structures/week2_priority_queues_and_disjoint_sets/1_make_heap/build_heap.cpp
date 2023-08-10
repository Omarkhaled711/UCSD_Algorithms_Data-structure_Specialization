#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  void consider_element(int i, int n)
  {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int min_index = i;
    if (left < n && data_[left] < data_[min_index])
    {
      min_index = left;
    }
    if (right < n && data_[right] < data_[min_index])
    {
      min_index = right;
    }
    if (min_index != i)
    {
      swaps_.push_back(make_pair(i, min_index));
      swap(data_[min_index], data_[i]);
      consider_element(min_index, n);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    int n = data_.size();
    for (int i = n/2; i >= 0; i--)
      consider_element(i, n);
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
