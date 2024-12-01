/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  var result = [];

  var work = (start, n, t) => {
    if (n == 0) {
      result.push(t);
      return;
    }
    if (start > candidates.length - 1) return;

    var copy = [];
    for (var i = start; i < candidates.length && candidates[i] <= n; i++) {
      copy = t.slice();
      copy.push(candidates[i]);
      if (i == start || (i > start && candidates[i] !== candidates[i - 1])) {
        work(i + 1, n - candidates[i], copy);
      }
    }
  };

  candidates.sort((a, b) => a - b);
  work(0, target, []);

  return result;
};

let n = 0;
let target = 0;
let arr = [];

// read n and target from stdin
// and then read n numbers from stdin and push them to arr
// without promts and using readline function, one number per line
const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

// combinationSum([2, 5, 2, 1, 2], 5);

readline.on("line", (line) => {
  if (n === 0) {
    n = parseInt(line);
  } else if (target === 0) {
    target = parseInt(line);
  } else {
    arr.push(parseInt(line));
  }

  if (arr.length === n) {
    readline.close();
    const result = combinationSum(arr, target);
    result.forEach((element) => {
      console.log(element.join(" "));
    });
  }
});
