const permute = (nums) => {
  if (nums.length <= 1) return [nums];
  // nums.sort((a, b) => a - b);
  const result = [];
  const work = (p, r) => {
    if (r.length === 1) {
      const res = Array.from(p);
      res.push(r[0]);
      result.push(res);
      return;
    }

    const k = Array.from(r);
    let map = new Map();

    for (let i = 0; i < r.length; i++) {
      if (map.has(k[0])) {
        k.push(k.shift());
        continue;
      }

      let t = k.shift();

      p.push(r[i]);
      work(p, k);
      p.pop();
      k.push(t);
      map.set(t, true);
    }
  };
  work([], nums);

  return result;
};

// const arr = [1, 2, 2, 3];
// const arr = [1, 1, 2];
const arr = [3, 3, 0, 3];

const x = permute(arr);
console.log(x);
console.log(x.length);
