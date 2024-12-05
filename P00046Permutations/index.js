const permute = (nums) => {
  if (nums.length <= 1) return [nums];
  const result = [];
  const work = (p, r) => {
    if (r.length === 1) {
      result.push([...p, r[0]]);
      return;
    }
    for (let i = 0; i < r.length; i++) {
      let n = [...(i === 0 ? [] : r.slice(0, i)), ...r.slice(i + 1)];
      work([...p, r[i]], n);
    }
  };
  work([], [...nums]);

  return result;
};

const x = permute([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
console.log(x.length);
