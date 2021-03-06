#include "driver.h"
#include <botan/divide.h>

void fuzz(const uint8_t in[], size_t len)
   {
   const BigInt x = BigInt::decode(in, len / 2);
   const BigInt y = BigInt::decode(in + len / 2, len / 2);

   if(y == 0)
      return;

   BigInt q, r;
   Botan::divide(x, y, q, r);

   FUZZER_ASSERT_TRUE(r < y);

   BigInt z = q*y + r;

   FUZZER_ASSERT_EQUAL(z, x);
   }

