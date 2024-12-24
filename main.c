#include <stdio.h>
#include <err.h>
#include <wchar.h>
#include <locale.h>

#include "Reverser.h"


int main(int argc, char** argv) {
  setlocale(LC_CTYPE, "");

  if (argc != 2)
    err(EXIT_FAILURE, "Wrong usage : \"./Reverse {file}\"");

  wchar_t braille = L'⣵';
  wchar_t complement = getComplement(braille);

  wprintf(L"Caractère braille  %lc\n", braille);
  wprintf(L"Complémentaire  %lc\n", complement);

  return 0;
}

