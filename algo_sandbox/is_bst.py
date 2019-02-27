''' Implements function that checks if binary tree is bst. '''

# Helper class created for debug purpose
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def is_bst(node, left=None, right=None):
    if node is None:
        return True

    if left!=None and node.data<left.data:
        return False

    if right!=None and node.data>right.data:
        return False

    return is_bst(node.left, left, node)\
            and is_bst(node.right, node, right)


##################
# Test program
##################
root = Node(10)
root.left = Node(8)
root.left.left = Node(2)
root.left.right = Node(9)
root.right = Node(20)
root.right.left = Node(15)
root.right.right = Node(30)
print("is BST: {}".format(is_bst(root)))
