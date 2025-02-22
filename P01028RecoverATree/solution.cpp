#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  TreeNode *reconstruct(map<__int128, int> &tree, __int128 current,
                        __int128 maxIndex) {
    TreeNode *v = new TreeNode(tree[current]);
    if (current * 2 <= maxIndex && tree.count(current * 2) != 0) {
      v->left = reconstruct(tree, current * 2, maxIndex);
    }

    if (current * 2 + 1 <= maxIndex && tree.count(current * 2 + 1) != 0) {
      v->right = reconstruct(tree, current * 2 + 1, maxIndex);
    }

    return v;
  }

public:
  TreeNode *recoverFromPreorder(string traversal) {
    vector<pair<int, int>> vertexes(1024);

    int size = 0;

    for (int i = 0; i < traversal.size(); i++) {
      int ts = 0;
      while (i < traversal.size() && traversal[i] == '-') {
        i++;
        ts++;
      }

      assert(i < traversal.size());

      string vs = "";

      while (i < traversal.size() && traversal[i] != '-') {
        vs += traversal[i++];
      }

      vertexes[size++] = {ts, stoi(vs)};

      i--;
    }

    __int128 maxVertex = 1;

    map<__int128, int> tree;

    __int128 current = 1;
    int currentLevel = 0;

    tree[1LL] = vertexes[0].second;

    for (int i = 1; i < size; i++) {
      auto [level, value] = vertexes[i];

      if (level == currentLevel) {
        ++current;
        tree[current] = value;
      } else if (level - currentLevel == 1) {
        current *= 2;
        tree[current] = value;
        currentLevel++;
      } else if (level < currentLevel) {
        while (level < currentLevel) {
          current /= 2;
          currentLevel--;
        }
        current++;
        tree[current] = value;
      } else {
        assert(false);
      }

      maxVertex = max(maxVertex, current);
    }

    return reconstruct(tree, 1LL, maxVertex);
  }
};

int main() {
  string s;
  cin >> s;

  Solution solution;

  solution.recoverFromPreorder(s);
}
