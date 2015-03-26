#include <stdio.h>
#include <ctype.h>
#include "codif.h"
#include "itu.h"
#include "streamencode.h"

void streamencode_init(void){
  itu_init();
}
  

void do_codifica(FILE *in, FILE *out){
  /*codifica el missatge ASCII del canal in i ecriu el resultat Morse en el canal out,in es un  un stream obert en mode lectura i out un stream obert en mode  escriptura. El final de missatge ve donat pel EOF */
  



}
 

void do_descodifica(FILE *in, FILE *out){
  /* Descodifica el missatge del canal in i escriu el resultat en el canal out*/

  

} 
