# question link - https://leetcode.com/problems/largest-perimeter-triangle
# difficulty - easy


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        addressSeen = set()
        
        while head is not None:
            if head in addressSeen:
                return True
            addressSeen.add(head)
            head = head.next
        
        return False
        