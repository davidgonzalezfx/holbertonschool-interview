#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    available = [0]
    for key in available:
        for key_list in boxes[key]:
            if key_list not in available:
                if key_list < len(boxes):
                    available.append(key_list)
    if len(available) == len(boxes):
        return True
    return False
