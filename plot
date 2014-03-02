#!/usr/bin/python
# -*- coding: utf-8 -*-

# Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

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

    data = np.genfromtxt("out/1.txt")
    pl.plot(data[:, 0], data[:, 1], label=ur"$y$", **plotargs)
    pl.plot(data[:, 0], data[:, 2], label=ur"$w_\alpha$", **plotargs)
    pl.plot(data[:, 0], data[:, 3], label=ur"$y^\prime$", **plotargs)
    pl.plot(data[:, 0], data[:, 4], label=ur"$w_\alpha^\prime$", **plotargs)
    pl.title(ur"Alle Daten")
    pl.xlabel(ur"$x$")
    #pl.ylabel(ur"")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/1-Alles.pdf")
    pl.savefig("out/1-Alles.png")
    pl.clf()

    plotargs = {
        "linestyle": "-",
    }

    steps = len(data)/100
    last_data = data[99*steps:, :]
    print last_data.shape
    pl.plot(last_data[:, 0], last_data[:, 1], label=ur"$y$", **plotargs)
    pl.title(ur"Letzte Berechnung")
    pl.xlabel(ur"$x$")
    #pl.ylabel(ur"")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/1-Letzte.pdf")
    pl.savefig("out/1-Letzte.png")
    pl.clf()
    
    data = np.genfromtxt("out/2c.txt")
    pl.plot(data[:, 0], data[:, 1], label=ur"$\psi$", **plotargs)
    pl.title(ur"Alle Daten")
    pl.xlabel(ur"$x$")
    #pl.ylabel(ur"")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/2c.pdf")
    pl.savefig("out/2c.png")
    pl.clf()

    gerade = list(sorted(set(np.genfromtxt("out/2f-gerade.txt"))))
    ungerade = list(sorted(set(np.genfromtxt("out/2f-ungerade.txt"))))
    gerade2 = list(sorted(set(np.genfromtxt("out/2g-gerade.txt"))))
    ungerade2 = list(sorted(set(np.genfromtxt("out/2g-ungerade.txt"))))

    print "Energieniveaus für gerade Wellenfunktionen:"
    print ", ".join(["{:.1f}".format(e) for e in gerade])
    print
    print "Energieniveaus für ungerade Wellenfunktionen:"
    print ", ".join(["{:.1f}".format(e) for e in ungerade])

    print

    print "Energieniveaus für gerade Wellenfunktionen:"
    print ", ".join(["{:.1f}".format(e) for e in gerade2])
    print
    print "Energieniveaus für ungerade Wellenfunktionen:"
    print ", ".join(["{:.1f}".format(e) for e in ungerade2])

    n_gerade = np.linspace(0, len(gerade), len(gerade));
    n_ungerade = np.linspace(0, len(ungerade), len(ungerade));

    n_gerade2 = np.linspace(0, len(gerade2), len(gerade2));
    n_ungerade2 = np.linspace(0, len(ungerade2), len(ungerade2));

    plotargs = {
        "linestyle": "none",
        "marker": ".",
    }

    pl.plot(n_gerade, gerade, label=ur"$\psi_\mathrm{gerade}$", **plotargs)
    pl.plot(n_ungerade, ungerade, label=ur"$\psi_\mathrm{ungerade}$", **plotargs)
    pl.plot(n_gerade2, gerade2, label=ur"$\tilde{\psi}_\mathrm{gerade}$", **plotargs)
    pl.plot(n_ungerade2, ungerade2, label=ur"$\tilde{\psi}_\mathrm{ungerade}$", **plotargs)
    pl.title(ur"Energieniveaus")
    pl.xlabel(ur"$n$")
    pl.ylabel(ur"$E_n$")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/2f.pdf")
    pl.savefig("out/2f.png")
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
