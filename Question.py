class Solution:
    def monkeyMove(self, n: int) -> int:
        ans = 2**n
        return (ans-2) % (10**9+7)
