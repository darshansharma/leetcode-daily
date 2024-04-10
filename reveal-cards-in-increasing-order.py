
#  QuestionLink: https://leetcode.com/problems/reveal-cards-in-increasing-order/
#  Difficulty:   Medium


class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        que = deque()

        for i in range(len(deck)):
            que.append(i)
        deck.sort()

        res = [0] * len(deck)
        for card in deck:
            res[que.popleft()] = card
            if que:
                que.append(que.popleft())
        return res