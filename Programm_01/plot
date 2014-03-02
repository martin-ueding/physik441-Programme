#!/usr/bin/python
# -*- coding: utf-8 -*-

# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

import argparse
import matplotlib.pyplot as pl
import numpy as np

__docformat__ = "restructuredtext en"

def main():
    options = _parse_args()

    data = np.genfromtxt("sin.csv")
    pl.plot(data[:,0], data[:,1])
    pl.title(ur"Plot der Funktion $g(x) = \left| \sin(x) + 0.2 \right|$")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$g(x)$")
    pl.grid(True)
    pl.savefig("plot-2.pdf")
    pl.clf()

    data = np.genfromtxt("pi_a.csv")
    pl.plot(data[:,0], data[:,1], label=ur"Reihe 1")
    data = np.genfromtxt("pi_b.csv")
    pl.plot(data[:,0], data[:,1], label=ur"Reihe 2")
    pl.title(ur"Plot der Reihenbeziehungen für $\pi$")
    pl.xlabel(ur"$k$")
    pl.ylabel(ur"$\pi_k$")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("plot-4.pdf")
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
