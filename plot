#!/usr/bin/python
# -*- coding: utf-8 -*-

# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

"""
Generates plots for the given data.
"""

import argparse
import matplotlib.pyplot as pl
import numpy as np

__docformat__ = "restructuredtext en"

def main():
    options = _parse_args()

    data = np.genfromtxt("out-1.csv")
    x = data[:,0]
    y = data[:,1]
    plot_x = np.linspace(np.min(x), np.max(x), 2)
    pl.plot(plot_x, np.ones(plot_x.size) * (-3.23293), label=ur"erster Fixpunkt")
    pl.plot(plot_x, np.ones(plot_x.size) * 7.73293, label=ur"zweiter Fixpunkt")
    pl.plot(x, y, linestyle="none", marker="+", label=ur"Daten")
    pl.title(ur"Fehler bei Banach'schen Fixpunktverfahren")
    pl.xlabel(ur"Iterationszahl $n$")
    pl.ylabel(ur"Fixpunkt $x_n$")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out-1.pdf")
    pl.savefig("out-1.png")
    pl.clf()

    data = np.genfromtxt("out-4.csv")
    x = data[:,0]
    y = np.abs(data[:,1] - 7.5)
    pl.plot(x, y, linestyle="none", marker="+")
    pl.title(ur"Fehler bei Integration nach Simpson")
    pl.xlabel(ur"Unterteilungszahl $n$")
    pl.ylabel(ur"Fehler $\left|\int_{-2}^1 \mathrm{d}x \, f(x) - S(n)\right|$")
    pl.grid(True)
    pl.savefig("out-4.pdf")
    pl.savefig("out-4.png")
    pl.clf()

    data = np.genfromtxt("out-5.csv")
    x = data[:,0]
    T0 = 2 * np.pi / np.sqrt(9.81)
    y = np.abs(data[:,1] - T0)
    pl.plot(x, y, linestyle="none", marker="+")
    pl.title(ur"Abweichung von der harmonischen Oszillation")
    pl.xlabel(ur"Startwinkel $\phi_0 / \mathrm{rad}$")
    pl.ylabel(ur"Fehler $\left|T\left(k^2, l, g\right) - 2\pi \sqrt{\frac{l}{g}} \right| / \mathrm{s}$")
    pl.grid(True)
    pl.savefig("out-5.pdf")
    pl.savefig("out-5.png")
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
