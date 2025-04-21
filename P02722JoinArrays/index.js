/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
  const ans = [];
  let i = 0, j = 0;
  arr1.sort((a, b) => a.id - b.id);
  arr2.sort((a, b) => a.id - b.id);
  while (i < arr1.length || j < arr2.length) {
    if (i < arr1.length && j < arr2.length) {
      if (arr1[i].id == arr2[j].id) {
        ans.push({ id: arr1[i].id, ...arr1[i], ...arr2[j] });
        i++; j++;
      } else if (arr1[i].id < arr2[j].id) {
        ans.push(arr1[i]);
        i++;
      } else {
        ans.push(arr2[j]);
        j++;
      }
      continue;
    }
    if (i < arr1.length) {
      ans.push(arr1[i]);
      i++;
    } else {
      ans.push(arr2[j]);
      j++;
    }
  }

  return ans;
};
