''' Implements function that checks if binary tree is bst. '''
from collections import deque

# Helper class created for debug purpose
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def add(node, root):
    if root is None:
        raise ValueError('root cannot be None')

    nodes_found = deque([root])

    while len(nodes_found) > 0:
        current_node = nodes_found.popleft()
        if current_node.left is not None:
            current_node.left = node
            break
        elif current_node.right is not None:
            current_node.right = node
            break

        nodes_found.append(current_node.left)
        nodes_found.append(current_node.right)


def is_bst(root):
    def _is_bst(node, left=None, right=None):
        if node is None:
            return True

        if left!=None and node.data<left.data:
            return False

        if right!=None and node.data>right.data:
            return False

        return is_bst(node.left, left, node)\
                and is_bst(node.right, node, right)

    if root is None:
        return True
    
    return _is_bst(root, None, None)


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
