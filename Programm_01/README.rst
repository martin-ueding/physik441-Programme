.. Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

############
physik411-01
############

Abgabe für physik411, Aufgabenzettel 1.

Aufgabe 2
=========

Für diese Aufgabe nur ``make`` eingeben, es werden die Daten in ``sin.csv``
erstellt und durch das Plotprogramm ``plot`` in die Datei ``plot-2.pdf``
geplottet.

Aufgabe 3
=========

Hier wieder ``make`` ausführen dann ``./3`` ausführen. Das Programm gibt dann
die gefundenen Genaugikeiten aus.

Auf meiner Maschine (``Linux Martin-X220 3.5.0-27-generic #46-Ubuntu SMP Mon
Mar 25 19:58:17 UTC 2013 x86_64 x86_64 x86_64 GNU/Linux``) gibt das Programm
aus:::

    double: 2.22045e-16
    float:  1.19209e-07

Aufgabe 4
=========

Mit ``make`` aus `Aufgabe 2`_ wurde bereits ``plot-4.pdf`` erstellt.

Abhängigkeiten
==============

Benötigt werden:

- gcc
- make
- Python 2
- Python numpy
- Python matplotlib
