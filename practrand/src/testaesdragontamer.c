#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "aesdragontamer.h"

#define buffer_size 512
int main() {
#ifdef __AES__
  uint64_t seedvalue = 12345678;
  aesdragontamer_seed(seedvalue);
  uint64_t buffer[buffer_size];

  while (1) {
    for (int k = 0; k < buffer_size; k++)
      buffer[k] = aesdragontamer();
    fwrite((void *)buffer, sizeof(buffer), 1, stdout);
  }
#endif // __AES__
}
