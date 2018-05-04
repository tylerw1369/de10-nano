//#include "acunit/i.h"
#include "../src/lib/ccurl.h"
#include "../src/lib/curl.h"
#include "../src/lib/hash.h"
#include "../src/lib/pearl_diver.h"
#include "../src/lib/util/converter.h"

#include "cunit_include.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// static const char *tryte_nines =
// "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
static const char* real_transaction =
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999ZDWNRTMICEUJKUZIZGXKNUXGTFQTGNXHY"
    "HYYQYLWPPWKRWFVTIOBFGMVLKGCOGHF9LINGNLPHQBO9UHSE99999999999999999999999999"
    "9999999999999999999999999999CAAUHVD99999999999999999999HRNCLJOVIU999QYHADT"
    "TFLUMTDSUAYKUUBWCWACGEPWZQUHQDWSGMFFKNHAIUUVQHPXOTHFFGLUUMYRMK999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "99999999999999999999999999999999999999999999999999999999999999999999999999"
    "999999999";
// static const char *real_trans_w_hash =
// "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999ZDWNRTMICEUJKUZIZGXKNUXGTFQTGNXHYHYYQYLWPPWKRWFVTIOBFGMVLKGCOGHF9LINGNLPHQBO9UHSE999999999999999999999999999999999999999999999999999999CAAUHVD99999999999999999999HRNCLJOVIU999QYHADTTFLUMTDSUAYKUUBWCWACGEPWZQUHQDWSGMFFKNHAIUUVQHPXOTHFFGLUUMYRMKPYHODCQSKTYJBNXYLMDXGTAIDMXNNXZPCJZD9PAXVITTAPLDDDAVZXHVY9QABYMTFGODIGFV9JZFW9999UNBHOV9VMEMRMBPJLEIJLUMXNFTSOMQ9JLNPAKOPIXALNXQHOMNRJPSRJOQYYWWXZJJX9FYOSKB999999XBKFGDZLRGMOMLDTQZOQ9DVUCNWCAXKOWCQDLLGMZAZKYYKIIQBT9X9RRMTMPPOAN9UJYKKBGNSWAZVHJ";

void runtests();
void getRandomTrits(char* RandomTrits, int length);
int init_suites(void) {
  init_converter();
  return 0;
}
int clean_suites(void) { return 0; }

/************** Test case functions ****************/

bool test_last_n_nines(char* hash, int length, int numNines) {
  int i;
  for (i = 1; i <= numNines; i++) {
    if (hash[length - i] != '9')
      return false;
  }
  return true;
}

void test_pearl_diver_search(void) {
  Curl curl;
  PearlDiver pearl_diver;
  int nonce_size = 13;
  clock_t start, diff;
  char *hash, *trans;
  char* mytrits;
  char hash_trits[HASH_LENGTH];

  mytrits = trits_from_trytes(real_transaction, TRYTE_LENGTH);

  start = clock();
  pd_search(&pearl_diver, mytrits, TRANSACTION_LENGTH, nonce_size, 8);
  diff = clock() - start;
  trans = trytes_from_trits(mytrits, 0, TRANSACTION_LENGTH);
  hash = trytes_from_trits(mytrits + TRANSACTION_LENGTH - HASH_LENGTH, 0,
                           HASH_LENGTH);
  init_curl(&curl);
  absorb(&curl, mytrits, 0, TRANSACTION_LENGTH);
  squeeze(&curl, hash_trits, 0, HASH_LENGTH);

  printf("\nTime taken: %ldms\n", diff * 1000 / CLOCKS_PER_SEC);
  hash = trytes_from_trits(hash_trits, 0, HASH_LENGTH);
  CU_ASSERT(test_last_n_nines(hash, HASH_LENGTH / 3, nonce_size / 3));
  free(mytrits);
  free(hash);
  free(trans);
}

void* dosearch(void* ctx) {
  PearlDiver* pearl_diver = (PearlDiver*)ctx;
  Curl curl;
  init_curl(&curl);
  char hash_trits[HASH_LENGTH];

  int nonce_size = 13;
  char mytrits[TRANSACTION_LENGTH];
  getRandomTrits(mytrits, TRANSACTION_LENGTH);

  pd_search(pearl_diver, mytrits, TRANSACTION_LENGTH, nonce_size, 1);

  absorb(&curl, mytrits, 0, TRANSACTION_LENGTH);
  squeeze(&curl, hash_trits, 0, HASH_LENGTH);

  CU_ASSERT(pearl_diver->status != PD_FOUND);
  CU_ASSERT(pearl_diver->status == PD_INTERRUPTED);
  return 0;
}
void test_pearl_diver_interrupt(void) {
  PearlDiver pearl_diver;

  pthread_t tid;
  pthread_create(&tid, NULL, &dosearch, (void*)&pearl_diver);

  sleep(1);

  interrupt(&pearl_diver);

  pthread_join(tid, NULL);
}

void test_export_pow(void) {
  char *hash, *output;
  char hash_trits[HASH_LENGTH];
  int mwm = 13;

  for (int i = 1; i <= 13; i++) {
    output = ccurl_pow((char*)real_transaction, i);
  }
  output[TRANSACTION_LENGTH / 3] = 0;
  char* outtrits = trits_from_trytes(output, TRANSACTION_LENGTH / 3);

  Curl curl;
  init_curl(&curl);

  absorb(&curl, outtrits, 0, TRANSACTION_LENGTH);
  squeeze(&curl, hash_trits, 0, HASH_LENGTH);
  hash = trytes_from_trits(hash_trits, 0, HASH_LENGTH);
  hash[HASH_LENGTH / 3] = 0;

  CU_ASSERT_FATAL(test_last_n_nines(hash, HASH_LENGTH / 3, mwm / 3));
  free(outtrits);
  free(hash);
}

void getRandomTrits(char* RandomTrits, int length) {
  int i = 0;
  srand(time(NULL));
  while (i < length) {
    RandomTrits[i] = rand() % 3 - 1;
    i++;
  }
}

static CU_TestInfo tests[] = {
    {"PearlDiver Search Test", test_pearl_diver_search},
    {"PearlDiver Interrupt Test", test_pearl_diver_interrupt},
    {"PearlDiver test curl_pow export", test_export_pow},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
    {"suitename1", init_suites, clean_suites, NULL, NULL, tests},
    CU_SUITE_INFO_NULL,
};

int main() { return run_tests(suites); }