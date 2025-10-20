class Solution {
private:
  int intersection(int axl, int axr, int bxl, int bxr) {
    if (axl > axr)
      swap(axl, axr);
    if (bxl > bxr)
      swap(bxl, bxr);

    if (axl > bxl) {
      swap(axl, bxl);
      swap(axr, bxr);
    }

    if (axr <= bxl)
      return 0;
    if (axr >= bxr)
      return bxr - bxl;

    return axr - bxl;
  }

public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int ix = intersection(ax1, ax2, bx1, bx2);
    int iy = intersection(ay1, ay2, by1, by2);
    return abs((ax1 - ax2) * (ay1 - ay2)) + abs((bx1 - bx2) * (by1 - by2)) -
           ix * iy;
  }
};
