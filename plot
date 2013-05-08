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

    data = np.genfromtxt("out-1.csv")
    x = data[:,0]
    y = np.abs(data[:,1] - np.pi)
    pl.loglog(x, y, **plotargs)
    pl.title(ur"$\pi$ mit Monte-Carlo-Algorithmus")
    pl.xlabel(ur"Iterationszahl $n$")
    pl.ylabel(ur"Fehler $\left|\pi_n - \pi\right|$")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out-1.pdf")
    pl.savefig("out-1.png")
    pl.clf()

    def gauss(k, mu, sigma, scale):
        return scale * 1./np.sqrt(2 * np.pi * sigma**2) * np.exp(- (k-mu)**2 / (2 * sigma**2))


    data = np.genfromtxt("out-2a.csv")
    x = data[:,0]
    y = data[:,1]
    pl.plot(x, y, **plotargs)
    popt, pconv = op.curve_fit(gauss, x, y, p0=[400, 500, 100])
    print u"μ = {}, σ = {}".format(*popt)
    plot_x = np.linspace(np.min(x), np.max(x), 1000)
    plot_y = gauss(plot_x, *popt)
    pl.plot(plot_x, plot_y, label="Fit")
    pl.title(ur"Anzahl der Päckchen für ein volles Panini-Album")
    pl.xlabel(ur"Anzahl Päckchen")
    pl.ylabel(ur"Häufigkeit")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out-2a.pdf")
    pl.savefig("out-2a.png")
    pl.clf()

    data = np.genfromtxt("out-2b.csv")
    x = data[:,0]
    y = data[:,1]
    pl.plot(x, y, **plotargs)
    popt, pconv = op.curve_fit(gauss, x, y, p0=[400, 500, 100])
    print u"μ = {}, σ = {}".format(*popt)
    plot_x = np.linspace(np.min(x), np.max(x), 1000)
    plot_y = gauss(plot_x, *popt)
    pl.plot(plot_x, plot_y, label="Fit")
    pl.title(ur"Anzahl der Päckchen für ein volles Panini-Album")
    pl.xlabel(ur"Anzahl Päckchen")
    pl.ylabel(ur"Häufigkeit")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out-2b.pdf")
    pl.savefig("out-2b.png")
    pl.clf()

    data = np.genfromtxt("out-2c.csv")
    x = data[:,0]
    y = data[:,1]
    pl.plot(x, y, **plotargs)
    popt, pconv = op.curve_fit(gauss, x, y, p0=[400, 500, 100])
    print u"μ = {}, σ = {}".format(*popt)
    plot_x = np.linspace(np.min(x), np.max(x), 1000)
    plot_y = gauss(plot_x, *popt)
    pl.plot(plot_x, plot_y, label="Fit")
    pl.title(ur"Anzahl der gezinkten Päckchen für ein volles Panini-Album")
    pl.xlabel(ur"Anzahl Päckchen")
    pl.ylabel(ur"Häufigkeit")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out-2c.pdf")
    pl.savefig("out-2c.png")
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
