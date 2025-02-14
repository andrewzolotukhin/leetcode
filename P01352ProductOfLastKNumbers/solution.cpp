#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
public:
  vector<long long> prefix;
  int size = 0;

  ProductOfNumbers() {
    prefix.push_back(1LL);
    size = 0;
  }

  void add(int num) {
    if (num == 0) {
      prefix = {1LL};
      size = 0;
      return;
    }
    prefix.push_back(prefix[size] * num);
    size++;
  }

  int getProduct(int k) {
    if (k > size)
      return 0;
    return (int)(prefix[size] / prefix[size - k]);
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
