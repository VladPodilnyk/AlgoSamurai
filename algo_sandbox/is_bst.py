''' Implements function that checks if binary tree is bst. '''
import sys
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


# Recursive solution
def is_bst(root):
    def _is_bst(node, left=None, right=None):
        if node is None:
            return True

        if (left is not None) and node.data<left.data:
            return False

        if (right is not None) and node.data>right.data:
            return False

        return _is_bst(node.left, left, node)\
                and _is_bst(node.right, node, right)

    if root is None:
        raise ValueError('root cannot be None')

    return _is_bst(root)


def display_nodes(root):
    if root is None:
        return

    if root.left is not None:
        display_nodes(root.left)

    print(root.data, end=' ')

    if root.right is not None:
        display_nodes(root.right)



#########################################################
# Test program for the recursive solution
#########################################################
print('Recursive solution')
root = Node(10)
root.left = Node(8)
root.left.left = Node(2)
root.left.right = Node(9)
root.right = Node(20)
root.right.left = Node(15)
root.right.right = Node(30)
#display_nodes(root)
print('is BST: {}'.format(is_bst(root)))






##########################################################
# Iterative solution (better than recursive), I'm considering it like more pythonic
##########################################################
class NodeInBounds:
    def __init__(self, tree_node, min=float('-inf'), max=float('inf')):
        self.tree_node = tree_node
        self.min = min
        self.max = max


def is_binary_tree(root):
    if root is None:
        return ValueError('root cannot be None')


    queue = [NodeInBounds(root)]
    while len(queue):
        head = queue.pop(0)
        if head.tree_node.data<=head.min and head.tree_node>=head.max:
            return False

        if head.tree_node.left is not None:
            queue.append(NodeInBounds(head.tree_node.left, head.min, head.tree_node.data))
        if head.tree_node.right is not None:
            queue.append(NodeInBounds(head.tree_node.right, head.tree_node.data, head.max))

    return True

###########################################################
# Test program for the iterative solution
###########################################################
print('\n\nIterative solution')
root = Node(10)
root.left = Node(8)
root.left.left = Node(2)
root.left.right = Node(9)
root.right = Node(20)
root.right.left = Node(15)
root.right.right = Node(30)
#display_nodes(root)
print('is BST: {}'.format(is_binary_tree(root)))
###########################################################


######################################################################################
# Iterative solution: in-order traversal must be ascending, so we are tracking this
######################################################################################
def is_bin_tree(root):
    current_node = root
    stack = list()
    prev_val = -sys.maxsize - 1

    while True:
        if current_node is not None:
            stack.insert(0, current_node)
            current_node = current_node.left
        else:
            if not len(stack):
                break

            current_node = stack.pop(0)
            if current_node.data > prev_val:
                prev_val = current_node.data
            else:
                return False

            #print("{} ".format(current_node.data)) #debug info
            current_node = current_node.right
    return True

###################################################
# Test program
###################################################
print('traversal')
root = Node(10)
root.left = Node(8)
root.left.left = Node(2)
root.left.right = Node(39)
root.right = Node(20)
root.right.left = Node(15)
root.right.right = Node(30)
#display_nodes(root)
print('is BST: {}'.format(is_bin_tree(root)))