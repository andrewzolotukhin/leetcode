#include <bits/stdc++.h>
using namespace std;

static class DSU {
  vector<int> Parent, Rank;

public:
  DSU(int n) {
    Parent.resize(n);
    Rank.resize(n, 0);
    for (int i = 0; i < n; i++)
      Parent[i] = i;
  }
  int Find(int x) { return Parent[x] == x ? x : Parent[x] = Find(Parent[x]); }
  bool Union(int x, int y) {
    int xset = Find(x), yset = Find(y);
    if (xset == yset)
      return false;
    if (Rank[xset] < Rank[yset])
      swap(xset, yset);
    Parent[yset] = xset;
    if (Rank[xset] == Rank[yset])
      Rank[xset]++;
    return true;
  }
};

class Solution {
public:
  vector<int> groupStrings(vector<string> &words) {
    int n = words.size();
    DSU dsu(n);
    vector<int> masks(n);

    for (int i = 0; i < n; ++i) {
      int mask = 0;
      for (char c : words[i])
        mask |= (1 << (c - 'a'));
      masks[i] = mask;
    }

    unordered_map<int, int> maskToIndex;
    for (int i = 0; i < n; ++i) {
      int mask = masks[i];

      if (maskToIndex.count(mask))
        dsu.Union(i, maskToIndex[mask]);
      else
        maskToIndex[mask] = i;

      for (int b = 0; b < 26; ++b) {
        int toggled = mask ^ (1 << b);
        if (maskToIndex.count(toggled))
          dsu.Union(i, maskToIndex[toggled]);
      }

      for (int b1 = 0; b1 < 26; ++b1) {
        if (!(mask & (1 << b1)))
          continue; // skip bits not set
        int removed = mask ^ (1 << b1);
        for (int b2 = 0; b2 < 26; ++b2) {
          if (removed & (1 << b2))
            continue;
          int replaced = removed | (1 << b2);
          if (maskToIndex.count(replaced))
            dsu.Union(i, maskToIndex[replaced]);
        }
      }
    }

    unordered_map<int, int> groupSize;
    int maxSize = 0;
    for (int i = 0; i < n; ++i) {
      int root = dsu.Find(i);
      maxSize = max(maxSize, ++groupSize[root]);
    }

    return {(int)groupSize.size(), maxSize};
  }
};
