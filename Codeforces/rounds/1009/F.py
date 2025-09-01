from math import ceil, floor
for _ in range(int(input())):
    l1, r1, l2, r2 = map(int, input().split(' '))
    """
    start by assuming one node per unit squaare
    """
    area = (r1 - l1) * (r2 - l2)
    nodes = area
    size = 2 # size of quadtree
    while True:
        # amount of sizexsize blocks that fit in region
        blocks = (floor(r1/size) - ceil(l1/size)) * (floor(r2/size) - ceil(l2/size))
        # optimal reached
        if not blocks:
            break
        # i keep 1 node and get rid of 3 by this method (scale by blocks variable)

        nodes -= 3 * blocks
        size *= 2
    print(nodes)