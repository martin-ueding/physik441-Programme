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

    data = np.genfromtxt("out/1-raw.txt");
    pl.pcolormesh(data)
    pl.colorbar() 
    pl.title(ur"Matrix in Rohform")
    pl.savefig('out/1-raw.png')
    pl.savefig('out/1-raw.pdf')
    pl.clf()

    data = np.genfromtxt("out/1-minimized.txt");
    pl.pcolormesh(data)
    pl.colorbar() 
    pl.title(ur"Matrix nach Maximierung der Diagonalen")
    pl.savefig('out/1-minimized.png')
    pl.savefig('out/1-minimized.pdf')
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
