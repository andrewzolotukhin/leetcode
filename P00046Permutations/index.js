const permute = (nums) => {
  if (nums.length <= 1) return [nums];
  const result = [];
  const work = (p, r) => {
    if (r.length === 1) {
      const res = Array.from(p);
      res.push(r[0]);
      result.push(res);
      return;
    }

    const k = Array.from(r);
    let t = k.shift();
    for (let i = 0; i < r.length; i++) {
      p.push(r[i]);
      work(p, k);
      p.pop();
      k.push(t);
      t = k.shift();
    }
  };
  work([], nums);

  return result;
};

const x = permute([1, 2, 3, 4, 5]);
console.log(x);
console.log(x.length);
