#include <wchar.h>
#include <stdio.h>
#include <stdint.h>

uint8_t reverse_bit(uint8_t c) {
  printf("char : %lc\n", c);
}

int reverse_file(__attribute__((unused)) char* filepath) {

  uint32_t c = 0x2900;
  uint8_t uint8_char = c - 0x2800;
  reverse_bit(uint8_char);
}

wchar_t getComplement(wchar_t braille) {
    if (braille < 0x2800 || braille > 0x28FF) {
        fwprintf(stderr, L"Erreur : Le caractère fourni n'est pas un caractère braille valide.\n");
        return braille;
    }

    unsigned char brailleDots = braille - 0x2800;

    unsigned char complementDots = brailleDots ^ 0x3F;

    // Reconstruction du caractère braille avec les bits inversés
    return 0x2800 + complementDots;
}
