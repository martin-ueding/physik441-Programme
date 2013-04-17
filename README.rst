.. Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
.. Abgabe zusammen mit Jan Weber

############
physik441-02
############

Abgabe von Martin Ueding und Jan Weber.

.. note::

    Dieses Dokument kann mit ``rst2html README.rst README.html`` aus
    ``python-docutils`` in HTML übersetzt werden. Dort werden auch die Formeln
    unten dargestellt.

Kompilieren und Ausführen
=========================

Mit ``make dep && make`` wird alles kombiliert und ausgeführt, die Ausgaben
erscheinen ganz unten in der Ausgabe von ``make``::

    Ausgabe Programm
    ./main
    Roots -12
    U_d = 5.95465
    I_d = 1


Abhängigkeiten
==============

- g++
- make

Überlegungen zu Aufgabe 2
=========================

Der Strom, der durch die Diode geht ist:

.. math::

    I_D(U_D) = I_S \exp\left( \frac{U_D}{m U_T} \right)

Die Spannung, die über dem Widerstand und der Diode abfällt, muss gerade die Eingangsspannung sein:

.. math::

    U_0 - U_D + R I_D (U_D) = 0
