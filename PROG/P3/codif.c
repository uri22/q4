#include <stdio.h>
#include "codif.h"

void empty_morse_char(morse_char_t mc) {
  /*Modifica la taula de mc, de tipus morse_char_t i 
    introdueix en el seu contingut caracters centinella.*/
  static int i;
  for (i=0;i<5;i++){
    mc[i]='\0';
  }
}
void empty_morse_table(morse_table_t t) {
  /*Modifica la taula de codificaci t i introdueix en el seu
    contingut caracters centinella.*/
  static int i;
  for (i=0;i<64;i++){
    t[i].c='\0';
    empty_morse_char(t[i].m);
  }
}

int posicio_arbre(morse_char_t m) {
  /* Calculem la posicio de l'arbre on li pertoca. */ 
  int n;
  int p;
  n=0;
  while (m[n]!='\0'){
    n=n+1;}
  if (m[n-1]=='.'){
    p=2*n;}
  else {
    p=2*n+1;}
  return p;
}

void modifica_mchar_t(morse_table_t t, morse_char_t m,int p){
  /*Ens permet modificar comodament un morse_char_t d'un 
    morse_table_t per un de nou.*/
  empty_morse_char(t[p].m);
  char j;
  int i;
  i=0;
  while (i<=5){
    j=m[i];
    t[p].m[i]=j;
    i=i+1;}
}

void set_translation(morse_table_t t, char c, morse_char_t m) {
  /* Introduim la codificacio morse en la taula t a la posicio
     que li pertoca de l'arbre. */
  int p;
  p=posicio_arbre(m);
  t[p].c=c;
  modifica_mchar_t(t,m,p);
}

char to_ascii(const morse_table_t t, morse_char_t m) {
  /*Retorna el caracter ASCII representat per la sequencia Morse.
    Si la sequencia Morse no te cap caracter associat, retorna el 
    caracter especial ’@’.*/
  int p;
  p=posicio_arbre(m);
  if (t[p].c!='\0'){
    return t[p].c;}
  else{
    return '@';}
}

void to_morse(const morse_table_t t, char c, morse_char_t m) {
  /*Modifica m assignant-li la cadena de caracters que conte la 
    representacio Morse del caracter ASCII c. Si c no conte un 
    caracter del domini, m es una cadena de longitud zero.*/
  static int p;
  static int i;
  i=0;
  while (i<=65){
    if (t[i].c==c) {
      p=i;
      i=i+1;}
    else{
      i=i+1;}
  }
  if (p<=64){
    int o;
    char k;
    o=0;
    while (o<5){
      k=t[p].m[o];
      m[o]=k;
      o=o+1;}}
  else{
    empty_morse_char(m);}
}
/*
int main(){
  morse_table_t t;
  empty_morse_table(t);
  set_translation(t, 'D', "-.");
  set_translation(t, 'R', "----");
  morse_char_t seq_morse;
  to_morse(t, 'D', seq_morse);
  printf("%s\n",seq_morse);
  char h;
  h=to_ascii(t, "----");
  printf("%c\n",h);
  return 1;
}
*/
