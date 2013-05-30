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
        "label": ur"Daten",
        "linestyle": "none",
        "marker": ".", 
    }

    data = np.genfromtxt("out-2a.csv")
    x = data
    pl.hist(x, bins=100)
    pl.xlim(0, 4.)
    pl.title(ur"Zufallszahlen aus der Sinusverteilung")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"Anzahl")
    pl.grid(True)
    pl.savefig("out-2a.pdf")
    pl.savefig("out-2a.png")
    pl.clf()

    data = np.genfromtxt("out-2b.csv")
    x = data
    pl.hist(x, bins=100)
    pl.xlim(0, 4.)
    pl.title(ur"Zufallszahlen aus der Sinusverteilung mit Dreieck")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"Anzahl")
    pl.grid(True)
    pl.savefig("out-2b.pdf")
    pl.savefig("out-2b.png")
    pl.clf()



    data = np.genfromtxt("out-3a-data.csv")
    x = data[:,0]
    y = data[:,1]
    z = data[:,2]
    pl.plot(x, y, markersize=4, **plotargs)
    pl.title(ur"Zufallszahlen aus der Einheitssphäre, $z$-Projektion")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$y$")
    pl.grid(True)
    pl.savefig("out-3a-z.pdf")
    pl.savefig("out-3a-z.png")
    pl.clf()

    pl.plot(x, z, markersize=4, **plotargs)
    pl.title(ur"Zufallszahlen aus der Einheitssphäre, $y$-Projektion")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$z$")
    pl.grid(True)
    pl.savefig("out-3a-y.pdf")
    pl.savefig("out-3a-y.png")
    pl.clf()

    fig = pl.figure()
    ax = p3.Axes3D(fig)
    ax.scatter(x, y, z, marker=".")
    ax.set_xlabel(u"$x$")
    ax.set_ylabel(u"$y$")
    pl.title(ur"Zufallszahlen aus der Einheitssphäre, 3D")
    ax.set_zlabel(u"$z$")
    pl.savefig("out-3a-3D.pdf")
    pl.savefig("out-3a-3D.png")
    #pl.show()
    pl.clf()
    


    data = np.genfromtxt("out-3a-transformed.csv")
    x = data[:,0]
    y = data[:,1]
    pl.plot(x, y, markersize=4, **plotargs)
    pl.title(ur"Zufallszahlen aus der Einheitssphäre, Hammer-Aitov-Projektion")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$y$")
    pl.grid(True)
    pl.savefig("out-3a-transformed.pdf")
    pl.savefig("out-3a-transformed.png")
    pl.clf()

    data = np.genfromtxt("out-3b.csv")
    x = np.log10(data[:,0])
    y = np.log10(data[:,2])
    def linear(x, a, b):
        return a * x + b
    popt, pconv = op.curve_fit(linear, x, y)
    plot_x = np.linspace(np.min(x), np.max(x), 4)
    plot_y = linear(plot_x, *popt)
    print "3b| Schritte bei normalem Radius:", 10**linear(np.log10(5e5), *popt)
    pl.plot(x, y, **plotargs)
    pl.plot(plot_x, plot_y)
    pl.title(ur"Random Walk in der Strahlungszone")
    pl.xlabel(ur"Strahlungsradius $\lg(R_\mathrm{rad})$")
    pl.ylabel(ur"Mittlere Entweichschrittzahl $\lg(\bar n_\mathrm{esc})$")
    pl.grid(True)
    pl.savefig("out-3b.pdf")
    pl.savefig("out-3b.png")
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
