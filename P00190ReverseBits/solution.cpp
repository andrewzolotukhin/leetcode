class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;

    uint32_t bit = 0;

    for (int i = 0; i < 32; i++) {
      bit = ((1 << i) & n) >> i;
      ans = ans | bit << (31 - i);
    }

    return ans;
  }
};
