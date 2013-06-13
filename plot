#!/usr/bin/python
# -*- coding: utf-8 -*-

# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
# Abgabe mit Jan Weber

"""
Generates plots for the given data.
"""

import argparse
import matplotlib.pyplot as pl
import mpl_toolkits.mplot3d.axes3d as p3
import numpy as np
import scipy.optimize as op

__docformat__ = "restructuredtext en"

def main():
    options = _parse_args()

    plotargs = {
        "linestyle": "none",
        "marker": ".", 
    }

    for omega, filename in [
	(.01, "out/1b-1"),
	(1.8, "out/1b-2"),
	(1.93, "out/1b-3"),
	(2.0, "out/1b-4"),
    ]:
        data = np.genfromtxt("{}.txt".format(filename))
        pl.plot(data[:, 0], data[:, 1], label=ur"$\varphi(t)$", **plotargs)
        pl.plot(data[:, 0], data[:, 2], label=ur"$\omega(t)$", **plotargs)
        pl.title(ur"Integration mit Runge-Kutta, feste Schrittweite, $\omega(0) = {:.3f}$".format(omega))
        pl.xlabel(ur"Zeit $t$")
        pl.ylabel(ur"$\varphi(t)$ und $\omega(t)$")
        pl.legend(loc="best")
        pl.grid(True)
        pl.savefig("{}.pdf".format(filename))
        pl.savefig("{}.png".format(filename))
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
