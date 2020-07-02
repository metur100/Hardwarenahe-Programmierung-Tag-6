# Hardwarenahe-Programmierung-Tag-6
In den bisherigen Ubungen haben Sie Nutzereingaben zur Laufzeit des Programms uber Tastatureingaben implementiert. In dieser Ubung schreiben Sie C-Programme, die ihren Input als Kommandozeilen-Parameter und -Optionen oder uber einzulesende Dateien erhalten, und die Ausgabedaten ebenfalls in Dateien schreiben konnen.

# Aufgabe 1 Kleiner Taschenrechner

Wir haben Ihnen fur die Funktion int calc(int x, int y, int interval, int mod10) eine Implementierung vorgegeben, die jede interval-te Zahl des Intervalls [x,y] quadriert und die Quadrate summiert. Wenn mod10 6= 0 gilt, wird nur die letzte Stelle des Ergebnisses zuruckgegeben.
(a) Schreiben Sie ein Programm main.c, welches die Zahlen x und y ¨uber die Kommandozeile ubergeben bekommt, und das die Funktion calc mit diesen Werten f¨ ur x und y sowie mit interval=1 und mod10=0 aufruft.
(b) Erweitern Sie Ihre main so, dass Sie folgende Optionen verarbeiten k¨onnen. • -m i: Setzt interval f¨ur den Funktionsaufruf auf i. • -d: Setzt mod10 auf 1. • -h: Gibt eine Hilfestellung zur Benutzung des Taschenrechners aus. Andern Sie den Funktionsaufruf entsprechend. Das Programm konnte also zum Beispiel so ./taschenrechner 2 10 oder so ./taschenrechner -m 2 2 10 aufgerufen werden.

# Aufgabe 2 Personal

I In dieser Aufgabe sollen Sie ein Programm schreiben, das die Wochenarbeitszeit von Mitarbeitern verwalten kann. Das Programm erh¨alt ¨uber die unten beschriebenen Eingabemethoden das Wochensoll aller Mitarbeiter und die Daten der einzelnen Mitarbeiter, und soll anschließend die Namen und den neuen Stand des Arbeitszeitkontos aller Mitarbeiter ausgeben. Der neue Stand des Arbeitzeitkontos berechnet sich aus der Di?erenz von pers¨onlicher Wochenarbeitszeit und allgemeinem Wochensoll, plus den pers¨onlichen Stand des Vormonats. Falls ein Beschaftigter aktuell krank oder im Urlaub ist (Spalte ’Bemerkungen’), soll der Wochensoll nicht abgezogen werden!

• Die Wochenarbeitszeit in Stunden (integer), die jeder Mitarbeiter leisten soll, wird Ihrem Programm als Kommandozeilen-Parameter ubergeben. • Die Personaldaten bestehen aus einem 4-Tupel pro Mitarbeiter, dieses enth¨alt den Nachnamen, die geleistete Wochenarbeitszeit, den Stunden-Stand des Vormonats und eine Bemerkung. Ihr Programm erhalt diese Daten zur Laufzeit ¨uber stdin. Beispieldaten haben wir Ihnen in der Datei Mitarbeiter.csv bereitgestellt, diese konnen z.B. so aussehen:
Schneider 15 -30 Urlaub Fischer 50 -60 Dienstreise Weber 40 0 leer
• Zusatzlich soll Ihr Programm folgende Optionen anbieten: -m Gibt nur diejenigen Beschaftigten aus, deren neuer Stand des Arbeitszeitkontos negativ ist. -a Berechnet den Vormonatswert nicht mit ein. -b bem Gibt nur die Beschaftigten aus, bei denen in der Bemerkungsspalte bem steht.
Beispielaufrufe:
./main 40 < Mitarbeiter.csv Gibt die Namen und neuen Stunden-Stand aus Mitarbeiter.csv aus, wenn pro Woche 40h gearbeitet werden soll.
./main 40 -b Dienstreise < Mitarbeiter.csv > Stundensoll.csv Gibt f¨ur 40 Soll-Wochenstunden die Namen und den neuen Stunden-Stand derjenigen Mitarbeiter aus Mitarbeiter.csv aus, in deren Bemerkung ’Dienstreise’ steht, und schreibt das Ergebnis in Stundensoll.csv.
./main 35 -m -a < Mitarbeiter.csv Gibt die Namen und die Di?erenz Wochenarbeitszeit-Wochensoll derjenigen Mitarbeiter aus Mitarbeiter.csv aus, die diese Woche weniger als das Soll von 35h gearbeitet haben.
Die Header-Datei personal.h enthalt einige Funktionsprototypen, die Sie implementieren sollen, um diese Aufgabe zu losen. Testen Sie Ihre Implementierungen mit den Unit-Tests in personal tests.ts. Schreiben Sie ein Make?le, um den Kompilier- und Testprozess zu automatisieren.

# Aufgabe 3 Personal II

Als nachstes sollen Sie ein Programm schreiben, das die in der vorherigen Aufgabe erstellten Listen weiter verarbeitet. Ihr Programm soll eine Datei mit Namen und Stundensoll (Output der vorherigen Aufgabe) sowie eine beliebige Anzahl an Namen von Projekt-Dateien mit deren verf¨ugbaren Mitarbeiter-Pl¨atzen als Eingabe erhalten, und soll die Mitarbeiter auf die Projekte verteilen. In jede der angegebenen Projekt-Dateien sollen dabei die Namen der Mitarbeiter geschrieben werden, die in diesem Projekt arbeiten sollen. Wenn bereits Daten in den ProjektDateien stehen, sollen diese nicht gel¨oscht werden! H¨angen Sie neue Daten stattdessen an. Wie Sie die Mitarbeiter konkret verteilen ist Ihnen ¨uberlassen, Sie m¨ussen lediglich die Kapazit¨aten der Projekte einhalten. Beispielaufruf:
./aufteilung Stundensoll.csv P1.csv 5 P2.csv 10 P3.csv 2 Verteilt die Mitarbeiter aus Stundensoll.csv auf die drei Projekte P1 (5 Pl¨atze), P2 (10 Pl¨atze) und P3 (2 Pl¨atze).
F¨ugen Sie eine Regel f¨ur das Kompilieren Ihres Programms aus dieser Aufgabe zu Ihrem Make?le hinzu.

# Aufgabe 4 Personal III

Geben Sie einen Kommandozeilenbefehl an, der Ihre Programme aus den vorherigen beiden Aufgaben verwendet, um damit aus der Datei Mitarbeiter.csv diejenigen Beschaftigten auf die zwei Projekte P1 (2 verbleibende Platze) und P2 (3 verbleibende Platze) zu verteilen, die nach Aktualisierung der Arbeitszeit im Minus sind. Dabei soll • der Wochensoll 40h betragen, und • nur Besch¨aftigte betrachtet werden, fur die die Bemerkung ’leer’ eingetragen wurde und deren Name mit M beginnt.
F¨ugen Sie in Ihrem Make?le eine Regel namens ’loesung aufgabenteil III’ hinzu, die den gesuchten Kommandozeilenbefehl ausf¨uhrt. Verwenden Sie das Make-Feature prerequisites in der neuen Regel, um sicher zu stellen, dass alle Voraussetzungen (wie das Kompilieren der ben¨otigten Programme) vorher erf¨ullt sind.