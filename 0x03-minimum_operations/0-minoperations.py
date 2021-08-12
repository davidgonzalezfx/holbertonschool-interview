#!/usr/bin/python3

""" Minimum Operations """


def minOperations(n):
    """Given a number n, Calculates the fewest number of operations
    needed to result in exactly n H characters in the file. """
    if not isinstance(n, int):
        return 0

    op = 0
    i = 2
    while (i <= n):
        if not (n % i):
            n = int(n / i)
            op += i
            i = 1
        i += 1
    return op
