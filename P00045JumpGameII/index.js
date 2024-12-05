/**
 * @param {number[]} nums
 * @return {number}
 */
const jump = (nums) => {
  if (nums.length <= 1) return 0;
  const d = new Array(nums.length).fill(Infinity);
  d[nums.length - 1] = 0;
  for (let i = nums.length - 2; i >= 0; i--) {
    if (nums[i] == 0) continue;
    d[i] = Math.min(...d.slice(i + 1, i + nums[i] + 1)) + 1;
  }
  return d[0];
};

//const res = jump([2,3,1,1,4]);
// const res = jump([2, 3, 0, 1, 4]);
const res = jump([2, 3]);

console.log(res);
