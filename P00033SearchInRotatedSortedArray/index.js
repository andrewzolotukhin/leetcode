/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
  const findRotationPoint = () => {
    var i = 0,
      j = nums.length - 1;

    if (nums[i] <= nums[j]) return i;

    while (i < j && nums[i] > nums[j]) {
      const k = Math.max(1, Math.floor((j - i) / 2));

      if (nums[i + k] < nums[i]) {
        j -= k;
      } else {
        i += k;
      }
    }

    return i + 1;
  };

  const find = (s, e, t) => {
    let i = s,
      j = e;

    if (i === j) return nums[i] === t ? s : -1;

    while (i < j) {
      const k = Math.max(1, Math.floor((j - i) / 2));
      if (nums[i + k] === t) return i + k;
      if (nums[i + k] < t) {
        i += k;
      } else {
        j -= k;
      }
    }

    //i = i + 1 > e ? i : i + 1;

    return nums[i] === t ? i : -1;
  };

  const rp = findRotationPoint();

  if (rp === 0) {
    return find(0, nums.length - 1, target);
  }

  const ll = find(0, rp - 1, target);
  const l = ll > -1 ? ll : find(rp, nums.length - 1, target);

  return l;
};

console.log(search([3, 1], 1)); // 1
console.log(search([1, 2, 3, 4], 0)); // -1
console.log(search([4, 5, 6, 7, 0, 1, 2], 0)); // 4
console.log(search([4, 5, 6, 7, 0, 1, 2], 0)); // 4
console.log(search([4, 5, 6, 7, 0, 1, 2], 2)); // 6
console.log(search([1, 2, 4, 5, 6, 7, 0], 2)); // 1
console.log(search([0, 1, 2, 4, 5, 6, 7], 2)); // 2
console.log(search([0, 1, 2, 4, 5, 6, 7], 7)); // 6
console.log(search([0, 1, 2, 4, 5, 6, 7], 0)); // 0
console.log(search([1], 0)); // -1
