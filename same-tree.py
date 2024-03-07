#   questionLink: https://leetcode.com/problems/same-tree/
#   difficulty  : Easy



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    arr1 = []
    arr2 = []
    def traverseTree(self,root,arr):
        if root == None:
            arr.append(None)
            return
        arr.append(root.val)
        self.traverseTree(root.left,arr)
        self.traverseTree(root.right,arr)

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        self.arr1 = []
        self.arr2 = []
        if p == None and q == None:
            return True
        if p == None and q != None:
            return False
        if q == None and p != None:
            return False
        if p.val != q.val:
            return False
        self.traverseTree(p,self.arr1)
        self.traverseTree(q,self.arr2)
        print(self.arr1, self.arr2)
        for i in range (0,len(self.arr1)):
            if self.arr1[i] != self.arr2[i]:
                return False
        return True        