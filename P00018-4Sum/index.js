var fourSum = function (nums, target) {
  const result = [];
  nums.sort((a, b) => a - b);

  for (let i = 0; i < nums.length - 3; i++) {
    if (nums[i] >= 0 && nums[i] > target) break;
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    for (let j = i + 1; j < nums.length - 2; j++) {
      const ps2 = nums[i] + nums[j];
      if (nums[j] >= 0 && ps2 > target) break;
      if (j > i + 1 && nums[j] === nums[j - 1]) continue;
      let k = j + 1,
        l = nums.length - 1;
      while (k < l) {
        if (k > j + 1 && nums[k] === nums[k - 1]) {
          k++;
          continue;
        }
        const total = ps2 + nums[k] + nums[l];
        if (total === target) {
          result.push([nums[i], nums[j], nums[k], nums[l]]);
          k++;
          l = nums.length - 1;
          continue;
        } else if (total > target) {
          l--;
        } else {
          do {
            k++;
          } while (nums[k] === nums[k - 1] && k < nums.length - 1);
        }
      }
    }
  }
  return result;
};
