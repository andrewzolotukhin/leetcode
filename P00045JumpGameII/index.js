/**
 * @param {number[]} nums
 * @return {number}
 */
const jump = (nums) => {
  if (nums.length <= 1) return 0;
  let longest = nums[0];
  let longestEndIndex = nums[0];
  let c = 1;

  for (let i = 1; i < nums.length - 1; i++) {
    longest = Math.max(longest, i + nums[i]);
    if (i === longestEndIndex) {
      c++;
      longestEndIndex = longest;
    }
  }

  return c;
};

// const res = jump([2, 3, 1, 1, 4]);
// const res = jump([2, 3, 0, 1, 4]);
const res = jump([2, 3]);

console.log(res);
