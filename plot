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
        "linestyle": "-",
    }

    print ur"Zeitentwicklung -- harmonischer Oszillator mit Runge-Kutta"
    data = np.genfromtxt("out/1.txt")
    pl.plot(data[:, 0], data[:, 1], label=ur"$\phi$", **plotargs)
    pl.plot(data[:, 0], data[:, 2], label=ur"$\dot{\phi}$", **plotargs)
    pl.title(ur"Zeitentwicklung -- harmonischer Oszillator mit Runge-Kutta")
    pl.xlabel(ur"Zeit $t$")
    #pl.ylabel(ur"")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/1-t-phi.pdf")
    pl.savefig("out/1-t-phi.png")
    pl.clf()

    print ur"Phasenraum -- harmonischer Oszillator mit Runge-Kutta"
    pl.plot(data[:, 1], data[:, 2], **plotargs)
    pl.title(ur"Phasenraum -- harmonischer Oszillator mit Runge-Kutta")
    pl.xlabel(ur"Auslenkung $\phi$")
    pl.ylabel(ur"Geschwindigkeit $\dot{\phi}$")
    pl.grid(True)
    pl.savefig("out/1-phi-omega.pdf")
    pl.savefig("out/1-phi-omega.png")
    pl.clf()

    print ur"Zeitentwicklung -- harmonischer Oszillator mit Cash-Carp"
    data = np.genfromtxt("out/2.txt")
    pl.plot(data[:, 0], data[:, 1], label=ur"$\phi$", **plotargs)
    pl.plot(data[:, 0], data[:, 2], label=ur"$\dot{\phi}$", **plotargs)
    pl.title(ur"Zeitentwicklung -- harmonischer Oszillator mit Cash-Carp")
    pl.xlabel(ur"Zeit $t$")
    #pl.ylabel(ur"")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/2-t-phi.pdf")
    pl.savefig("out/2-t-phi.png")
    pl.clf()

    print ur"Phasenraum -- harmonischer Oszillator mit Cash-Carp"
    pl.plot(data[:, 1], data[:, 2], **plotargs)
    pl.title(ur"Phasenraum -- harmonischer Oszillator mit Cash-Carp")
    pl.xlabel(ur"Auslenkung $\phi$")
    pl.ylabel(ur"Geschwindigkeit $\dot{\phi}$")
    pl.grid(True)
    pl.savefig("out/2-phi-omega.pdf")
    pl.savefig("out/2-phi-omega.png")
    pl.clf()

    print ur"Zeitentwicklung -- Doppelpendel mit Runge-Kutta"
    data = np.genfromtxt("out/3-rk.txt")
    pl.plot(data[:, 0], data[:, 1], label=ur"$\phi_1$", color="blue", linestyle="-")
    pl.plot(data[:, 0], data[:, 2], label=ur"$\phi_2$", color="green", linestyle="-")
    pl.plot(data[:, 0], data[:, 3], label=ur"$p_1$", color="blue", linestyle="--")
    pl.plot(data[:, 0], data[:, 4], label=ur"$p_2$", color="green", linestyle="--")
    pl.plot(data[:, 0], data[:, 5], label=ur"$H$", color="black", linestyle="-")
    pl.title(ur"Zeitentwicklung -- Doppelpendel mit Runge-Kutta")
    pl.xlabel(ur"Zeit $t$")
    #pl.ylabel(ur"")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/3-rk-zeit.pdf")
    pl.savefig("out/3-rk-zeit.png")
    pl.clf()

    print ur"Phasenraum -- Doppelpendel mit Runge-Kutta"
    pl.plot(data[:, 1], data[:, 3], label=ur"1", **plotargs)
    pl.plot(data[:, 2], data[:, 4], label=ur"2", **plotargs)
    pl.title(ur"Phasenraum -- Doppelpendel mit Runge-Kutta")
    pl.xlabel(ur"Auslenkung $\phi_i$")
    pl.ylabel(ur"Impuls $p_i$")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/3-rk-phase.pdf")
    pl.savefig("out/3-rk-phase.png")
    pl.clf()

    print ur"Auslenkung -- Doppelpendel mit Runge-Kutta"
    pl.plot(data[:, 1], data[:, 2], **plotargs)
    pl.title(ur"Auslenkung -- Doppelpendel mit Runge-Kutta")
    pl.xlabel(ur"Auslenkung $\phi_1$")
    pl.ylabel(ur"Auslenkung $\phi_2$")
    pl.grid(True)
    pl.savefig("out/3-rk-auslenkung.pdf")
    pl.savefig("out/3-rk-auslenkung.png")
    pl.clf()

    print ur"Trajektorie -- Doppelpendel mit Runge-Kutta"
    x1 = np.cos(data[:, 1] - np.pi/2)
    y1 = np.sin(data[:, 1] - np.pi/2)
    x2 = x1 + np.cos(data[:, 2] - np.pi/2)
    y2 = y1 + np.sin(data[:, 2] - np.pi/2)
    items = 300
    step = len(x1)/items
    i = 0
    for t_, x1_, y1_, x2_, y2_ in zip(data[:, 0], x1, y1, x2, y2)[::step]:
        part = 1. - float(i) / items
        if part > 1.:
            part = 1.
        elif part < 0.:
            part = 0.
        color = str(part)
        pl.plot(np.array([0, x1_, x2_]), np.array([0, y1_, y2_]), marker="o",
                color=color, **plotargs)
        i += 1
    pl.title(ur"Trajektorie -- Doppelpendel mit Runge-Kutta")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$y$")
    pl.grid(True)
    pl.savefig("out/3-rk-trajektorie.pdf")
    pl.savefig("out/3-rk-trajektorie.png")
    pl.clf()

    print ur"Zeitentwicklung -- Doppelpendel mit Cash-Carp"
    data = np.genfromtxt("out/3-cc.txt")
    pl.plot(data[:, 0], data[:, 1], label=ur"$\phi_1$", color="blue", linestyle="-")
    pl.plot(data[:, 0], data[:, 2], label=ur"$\phi_2$", color="green", linestyle="-")
    pl.plot(data[:, 0], data[:, 3], label=ur"$p_1$", color="blue", linestyle="--")
    pl.plot(data[:, 0], data[:, 4], label=ur"$p_2$", color="green", linestyle="--")
    pl.plot(data[:, 0], data[:, 5], label=ur"$H$", color="black", linestyle="-")
    pl.title(ur"Zeitentwicklung -- Doppelpendel mit Cash-Carp")
    pl.xlabel(ur"Zeit $t$")
    #pl.ylabel(ur"")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/3-cc-zeit.pdf")
    pl.savefig("out/3-cc-zeit.png")
    pl.clf()

    print ur"Phasenraum -- Doppelpendel mit Cash-Carp"
    pl.plot(data[:, 1], data[:, 3], label=ur"1", **plotargs)
    pl.plot(data[:, 2], data[:, 4], label=ur"2", **plotargs)
    pl.title(ur"Phasenraum -- Doppelpendel mit Cash-Carp")
    pl.xlabel(ur"Auslenkung $\phi_i$")
    pl.ylabel(ur"Impuls $p_i$")
    pl.grid(True)
    pl.legend(loc="best")
    pl.savefig("out/3-cc-phase.pdf")
    pl.savefig("out/3-cc-phase.png")
    pl.clf()

    print ur"Auslenkung -- Doppelpendel mit Cash-Carp"
    pl.plot(data[:, 1], data[:, 2], **plotargs)
    pl.title(ur"Auslenkung -- Doppelpendel mit Cash-Carp")
    pl.xlabel(ur"Auslenkung $\phi_1$")
    pl.ylabel(ur"Auslenkung $\phi_2$")
    pl.grid(True)
    pl.savefig("out/3-cc-auslenkung.pdf")
    pl.savefig("out/3-cc-auslenkung.png")
    pl.clf()

    print ur"Trajektorie -- Doppelpendel mit Cash-Carp"
    x1 = np.cos(data[:, 1] - np.pi/2)
    y1 = np.sin(data[:, 1] - np.pi/2)
    x2 = x1 + np.cos(data[:, 2] - np.pi/2)
    y2 = y1 + np.sin(data[:, 2] - np.pi/2)
    step = len(x1)/items
    i = 0
    for t_, x1_, y1_, x2_, y2_ in zip(data[:, 0], x1, y1, x2, y2)[::step]:
        part = 1. - float(i) / items
        if part > 1.:
            part = 1.
        elif part < 0.:
            part = 0.
        color = str(part)
        pl.plot(np.array([0, x1_, x2_]), np.array([0, y1_, y2_]), marker="o",
                color=color, **plotargs)
        i += 1
    pl.title(ur"Trajektorie -- Doppelpendel mit Cash-Carp")
    pl.xlabel(ur"$x$")
    pl.ylabel(ur"$y$")
    pl.grid(True)
    pl.savefig("out/3-cc-trajektorie.pdf")
    pl.savefig("out/3-cc-trajektorie.png")
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
