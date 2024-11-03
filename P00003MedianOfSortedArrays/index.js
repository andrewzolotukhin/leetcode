var findMedianSortedArrays = function (nums1, nums2) {
  const totalLength = nums1.length + nums2.length;
  const isMedianIndex =
    totalLength & 1
      ? (idx) => ({
          isMedian: idx === (totalLength - 1) / 2,
          isLast: true,
        })
      : (idx) => ({
          isMedian: idx === totalLength / 2 - 1 || idx === totalLength / 2,
          isLast: idx === totalLength / 2,
        });

  let isDone = false;
  let index = 0;
  let i1 = 0,
    i2 = 0;
  let medians = 0;
  let median = 0;

  while (!isDone) {
    let value;
    if (nums1.length && !nums2.length) {
      value = nums1.shift();
    } else if (!nums1.length && nums2.length) {
      value = nums2.shift();
    } else {
      value = nums1[0] <= nums2[0] ? nums1.shift() : nums2.shift();
    }

    const { isMedian, isLast } = isMedianIndex(index++);

    if (isMedian) {
      median += value;
      medians++;
      if (isLast) {
        isDone = true;
      }
    }
  }

  return median / medians;
};

console.log(findMedianSortedArrays([], [2, 3]));
