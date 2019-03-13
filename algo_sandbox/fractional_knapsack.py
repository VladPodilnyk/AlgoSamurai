""" Solution for the fractional knapsack problem """

# Given weights and values of n items, we need to put these
# items in a knapsack of capacity W to get the maximum total
# value in kanpsack. Note: we can break items for maximizing
# the total value of kanpsack.
#
#
# Possible solutions:
# - brute-force aproach: try all possible subset with all different
#                        fractions but that will be too much time taking.

# - efficient solution: use 'Greedy' approach. The basic idea is to calculate
#                       the ratio value/weight for each item and sort
#                       the item on basis of this ratio. Then take the item
#                       with the highest ratio and add them until we can't
#                       add the next item as a whole and at the end add the
#                       next item as much as we can. This will always be
#                       the optimal solution.


class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

    def ratio(self):
        return self.value / self.weight


def pack_items(items, max_weight):
    """ Solve knapsack problem """
    if len(items)==0 or max_weight==0:
        return ValueError('An empty list given.')


    sorted_items = sorted(items, key=lambda item: item.ratio(), reverse=True)
    result = 0
    remain = max_weight

    for item in sorted_items:
        if remain-item.weight >= 0:
            result += item.value
            remain -= item.weight
        else:
            result += remain/item.weight * item.value
            break

    return result


# Simple test
if __name__ == '__main__':
    items = [Item(60, 10), Item(100, 20), Item(120, 30)]
    print('result: {}'.format(pack_items(items, 50)))
