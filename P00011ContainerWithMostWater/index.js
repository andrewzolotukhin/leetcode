/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  const v2 = (h) => {
    let l = 0,
      r = h.length - 1;
    const getSize = (i, j) => Math.abs((i - j) * Math.min(h[i], h[j]));
    let maxSize = 0;
    do {
      let size = getSize(l, r);
      if (size > maxSize) maxSize = size;
      if (h[l] < h[r]) {
        l++;
      } else {
        r--;
      }
    } while (l < r);

    return maxSize;
  };

  return v2(height);
};

console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7])); // 49
//console.log(maxArea([1,1]));
//console.log(maxArea([8,7,2,1]));
//console.log(maxArea([5,2,12,1,5,3,4,11,9,4]));
