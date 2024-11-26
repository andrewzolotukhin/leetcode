/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
  if (nums.length < 2) return target == nums[0] ? 0 : target < nums[0] ? 0 : 1;
  if (target < nums[0]) return 0;

  let i = 0,
    j = nums.length - 1;

  while (i < j && i < nums.length && nums[i] !== target) {
    const k = Math.round(Math.ceil((j - i) / 2));
    if (nums[i + k] > target) {
      j -= k;
    } else if (nums[i + k] < target) {
      i += k;
    } else {
      i += k;
      break;
    }
  }

  if (nums[i] == target) return i;

  return i + 1;
};
