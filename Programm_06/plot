#!/usr/bin/python
# -*- coding: utf-8 -*-

# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

"""
Generates plots for the given data.
"""

import argparse
import matplotlib.pyplot as pl
import numpy as np
import scipy.optimize as op

__docformat__ = "restructuredtext en"

def main():
    options = _parse_args()

    plotargs = {
        "label": ur"Daten",
        "linestyle": "none",
        "marker": "x", 
    }

    data = np.genfromtxt("out/points.csv")
    interpolated = np.genfromtxt("out/interpolated.csv")
    pl.plot(data[:,0], data[:,1], **plotargs)
    pl.plot(interpolated[:,0], interpolated[:,1], label="Interpoliert", linestyle="none", marker=".", markersize=4)
    pl.title(ur"Empfindlichkeit des menschlichen Auges")
    pl.xlabel(ur"$\lambda / \mathrm{nm}$")
    pl.ylabel(ur"Empfindlichkeit")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/plot.pdf")
    pl.savefig("out/plot.png")
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
