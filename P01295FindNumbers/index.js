/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function (nums) {
  return nums.reduce((a, v) => a + ((Math.floor(Math.log10(v)) % 2) ? 1 : 0), 0);
};
