#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool inorder_traverse(const vector<Node>& tree, int i, long long &prev, bool pos, int root)
  {
    if (i == -1)
        return (1);
    if (!inorder_traverse(tree, tree[i].left, prev, 1, tree[i].key))
        return (0);
    if (pos && tree[i].key == root)
        return (0);
    if (tree[i].key < prev)
      return (0);
    prev = tree[i].key;
    return (inorder_traverse(tree, tree[i].right, prev, 0, tree[i].key));
  }
bool IsBinarySearchTree(const vector<Node>& tree) {
  if (tree.size() == 0)
      return 1;
  long long prev = (long long) INT_MIN - 1;
  return (inorder_traverse(tree, 0, prev, 1, -1));
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
