#include <stdio.h>
#include <err.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

#include "Reverser.h"


int main(int argc, char** argv) {
  setlocale(LC_ALL, "en_US.UTF-8");

  if (argc != 2)
    err(EXIT_FAILURE, "Wrong usage : \"./Reverse {file}\"");

  reverse_file(argv[1]);

  return EXIT_SUCCESS;
}

