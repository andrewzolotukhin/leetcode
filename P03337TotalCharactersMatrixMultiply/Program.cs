public class Solution {
    private const int MOD = (int)1e9 + 7;
    private const int L = 26;

    private class Mat {
        public int[,] a = new int[L, L];

        public Mat() {}

        public Mat(Mat copyFrom) {
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    this.a[i, j] = copyFrom.a[i, j];
                }
            }
        }

        public Mat Mul(Mat other) {
            Mat result = new Mat();
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    for (int k = 0; k < L; k++) {
                        result.a[i, j] =
                            (int)((result.a[i, j] +
                                   (long)this.a[i, k] * other.a[k, j]) %
                                  MOD);
                    }
                }
            }
            return result;
        }
    }
    /* identity matrix */
    private Mat I() {
        Mat m = new Mat();
        for (int i = 0; i < L; i++) {
            m.a[i, i] = 1;
        }
        return m;
    }
    /* matrix exponentiation by squaring */
    private Mat QuickMul(Mat x, int y) {
        Mat ans = I();
        Mat cur = new Mat(x);
        while (y > 0) {
            if ((y & 1) == 1) {
                ans = ans.Mul(cur);
            }
            cur = cur.Mul(cur);
            y >>= 1;
        }
        return ans;
    }

    public int LengthAfterTransformations(string s, int t, IList<int> nums) {
        Mat T = new Mat();
        for (int i = 0; i < L; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                T.a[(i + j) % L, i] = 1;
            }
        }

        Mat res = QuickMul(T, t);
        int[] f = new int[L];
        foreach (char ch in s) {
            f[ch - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                ans = (int)((ans + (long)res.a[i, j] * f[j]) % MOD);
            }
        }
        return ans;
    }
}
