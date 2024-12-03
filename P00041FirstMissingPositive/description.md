# Intuition

It's evident that the missing positive number is in the range `[1, n+1]` where `n` is the size of the input array. We can use the input array to keep track of the missing positive number. We can iterate through the array and swap the numbers to their correct positions. We can then iterate through the array again to find the missing positive number.

# Approach

We have two variables `i` and `j` initialized to 0 and `n-1` respectively (you can also call them `left` and `right`). We start from the left most number and if it's in the range `[1, n]` we swap it to its correct position and then try to take the next number iteratively. While swapping values we also making sure that we don't overwrite correctly positioned numbers.

Once `i == j` we stop the cycle (in the worst case scenario it will be `n` iterations). It's important to check again if the element `i` pointing to should be moved to the right place (there are situations when `i` already equal to `j` but we still need to move the last element).

At this point we have all the numbers between `[1, n]` in their correct places, so what we need to do is to iterate through the array and find the first number element where `nums[i] != i + 1`, if there is such element we return `i + 1` otherwise return `n + 1` (this situation happens only when we have all the numbers between 1 and n in the array).

# Complexity

- Time complexity:
`O(n)` where `n` is the size of the input array.

- Space complexity:
`O(1)` we are not using any extra space proportional to the size of the input array, just a few auxiliary variables.

# Code

```cpp []
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = n - 1;
    if (n == 1) {
      return ((nums[0] == 1) ? 2 : 1);
    }

    while (i < j) {
      if ((nums[j] == j + 1) || (nums[j] < 1) || (nums[j] > n)) {
        j--;
        continue;
      }

      if (nums[i] != i + 1) {
        if (nums[i] < 1 || nums[i] > n) {
          if (nums[j] == nums[i]) {
            j--;
            continue;
          }
          int t = nums[j];
          nums[j] = nums[i];
          nums[i] = t;
          j--;
          // let's decrement i to be the same in the next iteration
          i--;
        } else {
          if (nums[i] != i + 1) {
            int ni = nums[i] - 1;
            if (nums[ni] == nums[i]) {
            } else {
              int t = nums[ni];
              nums[ni] = nums[i];
              nums[i] = t;
              // let's decrement i to be the same in the next iteration
              i--;
            }
          }
        }
      }
      i++;
    }

    if (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
      int t = nums[nums[i] - 1];
      nums[nums[i] - 1] = nums[i];
      nums[i] = t;
    }

    for (int k = 0; k < n; k++) {
      if (nums[k] != k + 1) {
        return k + 1;
      }
    }

    return n + 1;
}
```
