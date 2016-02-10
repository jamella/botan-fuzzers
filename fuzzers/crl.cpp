#include "driver.h"

#include <botan/x509_crl.h>

void fuzz(const uint8_t in[], size_t len)
   {
   try
      {
      DataSource_Memory input(in, len);
      X509_CRL crl(input);
      }
   catch(Botan::Exception& e) { }
   }
