#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    util = list(boxes)
    available = [0]
    for idx in range(len(boxes)):
        for idx2, keys in enumerate(util):
            if idx is not idx2:
                for key in keys:
                    available.append(key)
        if not idx in available:
            return False
        available = []
    return True
