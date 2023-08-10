#include <bits/stdc++.h>
  
using namespace std;

typedef pair<long long, int> pli;
class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  priority_queue<pli,vector<pli>, greater<pli>> pq;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    for (int i = 0; i < num_workers_; i++)
    {
      assigned_workers_.push_back(i);
      start_times_.push_back(0);
      pq.push(make_pair(jobs_[i], i));
    }
    int m = jobs_.size();
    for (int i = num_workers_; i < m; i++)
    {
      pli top = pq.top();
      pq.pop();
      assigned_workers_.push_back(top.second);
      start_times_.push_back(top.first);
      pq.push(make_pair(top.first + jobs_[i],top.second));
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
