/* Implementieren Sie die folgenden Funktionen in personal.c */

/*
 * Gibt die verbleibende Arbeitszeit/Überstunden zurück und bezieht dabei ein,
 * - ob der Mitarbeiter krank oder im Urlaub ist,
 * - ob der Vormonat in die Berechnung einfliessen (vormonat_ignorieren=0) soll.
 */
int calc_arbeitszeit(int wochenarbeitszeit, int stand_vormonat, int wochensoll,
                     char *bemerkung, int vormonat_ignorieren);

/*
 * Überprüft, ob die <mitarbeiterbemerkung> der gesuchten Bemerkung.
 * <gesuchtebemerkung> entspricht Rückgabe ist 1 wenn ja und 0 sonst. 
 */
int hat_bemerkung(char *mitarbeiterbemerkung, char *gesuchtebemerkung);

/*
 * Überprüft, ob <bemerkung> gleich "krank" oder "Urlaub" ist.
 * Rückgabe ist 1 wenn ja und 0 sonst.
 */
int krank_oder_urlaub(char *bemerkung);
