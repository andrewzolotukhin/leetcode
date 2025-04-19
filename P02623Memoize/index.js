/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {

  const m = new Map();

  return function (...args) {
    let k = args[0];
    if (args.length == 2) {
      k = `${k}_${args[1]}`;
    }

    if (m.has(fn)) {
      const vs = m.get(fn);

      if (vs.has(k)) {
        return vs.get(k);
      }

      const nv = fn(...args);
      vs.set(k, nv);
      return nv;
    }

    const nm = new Map();
    const nv = fn(...args);
    nm.set(k, nv);
    m.set(fn, nm);
    return nv;
  }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
