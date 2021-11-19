#!/usr/bin/python3
"""Rain Module
    """


def rain(walls):
    """Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.

    Args:
        walls (List): ist of non-negative integers.

    Returns:
        Int: Integer indicating total amount of rainwater retained.
    """
    if(not len(walls)):
        return 0

    size = len(walls) - 1
    prev = walls[0]
    index = 0
    aux = 0
    water_retained = 0

    for i in range(1, size + 1):
        if (walls[i] >= prev):
            aux = 0
            index = i
            prev = walls[i]
        else:
            aux += prev - walls[i]
            water_retained += prev - walls[i]

    if (index < size):
        prev = walls[i]
        water_retained -= aux

        for i in range(size, index - 1, -1):
            if (walls[i] >= prev):
                prev = walls[i]
            else:
                water_retained += prev - walls[i]

    return water_retained
