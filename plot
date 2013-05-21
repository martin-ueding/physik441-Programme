#!/usr/bin/python
# -*- coding: utf-8 -*-

# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
# Abgabe mit Jan Weber

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
        "marker": ".", 
    }

    data = np.genfromtxt("out-3a-data.csv")
    x = data[:,0]
    y = data[:,1]
    pl.plot(x, y, **plotargs)
    pl.title(ur"Zufallszahlen aus der Einheitssphäre")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$y$")
    pl.grid(True)
    pl.savefig("out-3a-data.pdf")
    pl.savefig("out-3a-data.png")
    pl.clf()


    data = np.genfromtxt("out-3a-transformed.csv")
    x = data[:,0]
    y = data[:,1]
    pl.plot(x, y, **plotargs)
    pl.title(ur"Zufallszahlen aus der Einheitssphäre")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$y$")
    pl.grid(True)
    pl.savefig("out-3a-transformed.pdf")
    pl.savefig("out-3a-transformed.png")
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
