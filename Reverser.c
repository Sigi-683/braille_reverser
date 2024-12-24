#include <wchar.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <locale.h>

wchar_t getComplement(wchar_t braille) {
  setlocale(LC_ALL, "en_US.UTF-8");

  if (braille == ' ')
    return 0x28FF;
  else if (braille == 0x28FF)
    return ' ';
  if (braille < 0x2800 || braille > 0x28FF) {
    fwprintf(stderr, L"Erreur : Le caractère fourni n'est pas un caractère braille valide.\n");
    return braille;
  }

  unsigned char brailleDots = (unsigned char)(braille - 0x2800);
  unsigned char complementDots = brailleDots ^ 0x3F;

  return (wchar_t)(0x2800 + complementDots);
}

int reverse_file(const char *filepath) {
  setlocale(LC_ALL, "en_US.UTF-8");

  FILE *file = fopen(filepath, "r");
  if (file == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return EXIT_FAILURE;
  }

  wint_t ch;
  wchar_t *buffer = NULL;
  size_t size = 0;

  while ((ch = fgetwc(file)) != WEOF) {
    wchar_t *temp = realloc(buffer, (size + 1) * sizeof(wchar_t));
    if (temp == NULL) {
      perror("Erreur de réallocation mémoire");
      free(buffer);
      fclose(file);
      return EXIT_FAILURE;
    }
    buffer = temp;
    buffer[size++] = (ch == L'\n') ? L'\n' : getComplement(ch);
  }
  fclose(file);

  file = fopen(filepath, "w");
  if (file == NULL) {
    perror("Erreur lors de l'ouverture du fichier en écriture");
    free(buffer);
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < size; i++) {
    if (fputwc(buffer[i], file) == WEOF) {
      perror("Erreur lors de l'écriture dans le fichier");
      free(buffer);
      fclose(file);
      return EXIT_FAILURE;
    }
  }

  fclose(file);
  free(buffer);

  return EXIT_SUCCESS;
}

