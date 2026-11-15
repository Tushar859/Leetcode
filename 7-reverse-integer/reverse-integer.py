class Solution(object):
    def reverse(self, x):
        ans = 0
        y = abs(x)

        while(y != 0):
            rem = y % 10
            ans = ans * 10 + rem
            y = y // 10

        if(x < 0):
            ans = -ans

        if(ans < -2147483648 or ans > 2147483647):
            return 0

        return ans