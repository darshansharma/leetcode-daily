# question: https://leetcode.com/problems/middle-of-the-linked-list/description/
# difficulty: easy


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        items = []
        ptr = head
        while ptr:
            items.append(ptr)
            ptr = ptr.next
        middle_index = len(items) // 2
        return items[middle_index]