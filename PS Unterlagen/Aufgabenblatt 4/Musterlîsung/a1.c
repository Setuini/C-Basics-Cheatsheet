#include <stdbool.h>

// ... die Gesamtfläche des Grundstücks enthält
double total_area = 0.0;

// ... die Anzahl der Grundstückseigentümer enthält
int num_owners = 0; // In der Praxis die beste Lösung
// Falls Speicherplatz ein Problem ist und es max 255 Besitzer gibt.
// In der Praxis können solche Annahmen schnell zu Problemen führen.
unsigned char num_owners = 0;

// ... den Anfangsbuchstaben des Nachnamens des Haupteigentümers des Grundstücks
// enthält.
char surname_initial = 0;

// ... angibt ob es sich um ein Baugrundstück handelt oder nicht.
bool residential = false;
