#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> q;

void max_sliding_window(vector<int> const &A, int w) {
    for (size_t i = 0; i < w; ++i) {
        while (!q.empty() && A[i]>= A[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (size_t i = w; i < A.size(); i++)
    {
        cout<<A[q.front()]<<" ";
        while (!q.empty() && q.front() <= i - w)
        {
            q.pop_front();
        }
        while (!q.empty() && A[i] >= A[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<A[q.front()]<<" ";

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
