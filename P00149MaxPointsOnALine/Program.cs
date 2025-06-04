public class Solution {
    private int GCD(int a, int b) {
        a = Math.Abs(a);
        b = Math.Abs(b);
        while(b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    public int MaxPoints(int[][] points) {
        int ans = 0;
        if(points.Length == 1) return 1;
        for(int i = 0; i < points.Length; i++) {
            Dictionary<(int dx, int dy), int> slopes = [];
            for(int j = i + 1; j < points.Length; j++) {
              var dx = points[i][0]-points[j][0];
              var dy = points[i][1] - points[j][1];

              if(dx < 0 ) {
                (dx, dy) = (-dx, -dy);
              }

              if(dx != 0 && dy != 0) {
                (dx, dy) = (dx/GCD(dx, dy), dy/GCD(dx, dy));
              } else {
                if(dx == 0) {
                    (dx, dy) = (0, 1);
                } else {
                    (dx ,dy) = (1, 0);
                }
              }

              var key = (dx, dy);
              if(slopes.ContainsKey(key)) {
                slopes[key]++;
              } else {
                slopes[key] = 1;
              }
            }

            foreach(var k in slopes.Keys) {
                ans = Math.Max(slopes[k]+1, ans);
            }
        }
        return ans;
    }
}
