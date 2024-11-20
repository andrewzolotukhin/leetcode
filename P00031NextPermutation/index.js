/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
  const swap = (nums, i, j) => {
    let temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  };
  const reverse = (nums, start) => {
    let i = start;
    let j = nums.length - 1;
    while (i < j) {
      swap(nums, i, j);
      i++;
      j--;
    }
  };
  let ind1 = -1,
    ind2 = -1;
  for (let i = nums.length - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      ind1 = i;
      break;
    }
  }
  if (ind1 == -1) {
    reverse(nums, 0);
  } else {
    for (let i = nums.length - 1; i >= 0; i--) {
      if (nums[i] > nums[ind1]) {
        ind2 = i;
        break;
      }
    }

    swap(nums, ind1, ind2);
    reverse(nums, ind1 + 1);
  }
};
