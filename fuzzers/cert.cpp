#include "driver.h"

#include <botan/x509cert.h>

void fuzz(const uint8_t in[], size_t len)
   {
   try
      {
      DataSource_Memory input(in, len);
      X509_Certificate cert(input);
      }
   catch(Botan::Exception& e) { }
   }
