# questionLink - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# questionDifficulty - Easy
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buyingDay = 0
        sellingDay = 0
        profit = 0
        for i in range(len(prices)):
            if prices[i] >= prices[sellingDay]:
                sellingDay = i
                if profit < prices[sellingDay] - prices[buyingDay]:
                    profit = prices[sellingDay] - prices[buyingDay]
            if prices[i] < prices[buyingDay]:
                buyingDay = i
                if sellingDay < buyingDay:
                    sellingDay = i
        return profit
