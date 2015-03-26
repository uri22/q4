#ifndef _codif_h
#define __codif_h

typedef char morse_char_t[5];
/*Es un tipus de dades que representa una cadena morse correspo-
  nent a un sol caracter. Com en el codi ITU la llargada maxima
  a d’un caracter  es de 5 simbols, el representarem com una taula
  de mida fixa de 6 caracters.*/

typedef struct {
  /*Es un tipus de dades que representa una taula de codificacio
    Morse.*/
  char c;
  morse_char_t m;
} morse_table_t[64];

void empty_morse_char(morse_char_t mt);

void empty_morse_table(morse_table_t t);

int posicio_arbre(morse_char_t m);

void modifica_mchar_t(morse_table_t t, morse_char_t m,int p);

void set_translation(morse_table_t t, char c, morse_char_t m);

char to_ascii(const morse_table_t t, morse_char_t m);

void to_morse(const morse_table_t t, char c, morse_char_t m);

#endif
