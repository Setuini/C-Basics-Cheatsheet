#ifndef ADDRESS_H
#define ADDRESS_H

struct address {
  // Definieren Sie hier ihre Adressen-Struktur
};

// Liest einen Adressdatensatz vom Benutzer ein und gibt diesen in Form eines
// struct zurück
struct address input_address(void);

// Übernimmt einen Adressdatensatz in form eines struct und gibt diesen auf dem
// Bildschirm aus
void print_address(const struct address *addr);

#endif /* ADDRESS_H */
