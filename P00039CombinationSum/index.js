/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  const result = [];

  const work = (start, n, t = []) => {
    for (let i = start; i < candidates.length && candidates[i] <= n; i++) {
      if (candidates[i] === n) {
        result.push([...t, candidates[i]]);
        break;
      } else {
        let c = [...t];
        let nn = n;

        do {
          c.push(candidates[i]);
          nn -= candidates[i];
          if (i < candidates.length - 1) {
            work(i + 1, nn, c);
          }
        } while (nn > 0);

        if (nn === 0) {
          result.push(c);
        }
      }
    }
  };

  candidates.sort((a, b) => a - b);
  work(0, target);

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

// combinationSum([8, 7, 4, 3], 11);

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
