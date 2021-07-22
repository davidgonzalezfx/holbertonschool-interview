#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    util = list(boxes)
    available = []
    for idx, val in enumerate(boxes):
        for idx2, keys in enumerate(util):
            if idx > 0 and idx is not idx2:
                for key in keys:
                    available.append(key)
        if idx > 0 and not idx in available:
            return False
        available = []
    return True
