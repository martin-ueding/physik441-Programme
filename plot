#!/usr/bin/python
# -*- coding: utf-8 -*-

# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

import argparse
import matplotlib.pyplot as pl
import numpy as np

__docformat__ = "restructuredtext en"

def main():
    options = _parse_args()

    data = np.genfromtxt("out-4.csv")

    x = data[:,0]
    y = np.abs(data[:,1] - 7.5)

    pl.plot(x, y, linestyle="none", marker="+")
    pl.grid(True)
    pl.savefig("out-4.pdf")
    pl.clf()


def _parse_args():
    """
    Parses the command line arguments.

    :return: Namespace with arguments.
    :rtype: Namespace
    """
    parser = argparse.ArgumentParser(description="")
    #parser.add_argument("args", metavar="N", type=str, nargs="*", help="Positional arguments.")
    #parser.add_argument("", dest="", type="", default=, help=)
    #parser.add_argument("--version", action="version", version="<the version>")

    return parser.parse_args()


if __name__ == "__main__":
    main()
