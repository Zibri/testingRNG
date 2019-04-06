#ifndef ZIBRI128_H
#define ZIBRI128_H

/* Modified by D. Lemire, August 2017 */
#include "splitmix64.h"
#include <stdint.h>

// state for zibri128
uint64_t zibri128_s[2];


static inline uint64_t rotr(const uint64_t x, int k) {
  return (x >> k) | (x << (64 - k));
}


// call this one before calling zibri128
static inline void zibri128_seed(uint64_t seed) {
  zibri128_s[0] = splitmix64_stateless(seed);
  zibri128_s[1] = splitmix64_stateless(seed + 1);
}

// returns random number, modifies zibri128_s
static inline uint64_t zibri128(void) {
  const uint64_t s0 = zibri128_s[0];
  uint64_t s1 = zibri128_s[1];
  const uint64_t result = rotr(s0 + s1,8);// ^ (s0 > s1);

  zibri128_s[0] = result; // a, b
  zibri128_s[1] = s0;                   // c

  return result;
}

#endif // ZIBRI128_H
