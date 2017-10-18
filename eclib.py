"""Python bindings for John Cremona's eclib."""

import itertools as it
import _eclib

def mwrank(ai):
    """
    Find Mordell-Weil baisis of the given curve (a1, a2, a3, a4, a6)
    where each ai is of the form (num, den).
    """
    return tuple(
        (tuple(map(int, x)), tuple(map(int, y)))
        for x, y
        in _eclib.mwrank(*(map(str, it.chain.from_iterable(ai))))
    )

_test_curve = ((-20, 9), (236, 81), (-1064, 729), (8092, 6561), (0, 1))
