
// Hashtable code from :
// https://gist.github.com/tonious/1377667

#define _XOPEN_SOURCE 500 // Enable certain library functions (strdup) on linux.
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
 
struct entry_s {
  void* key;
  int value;
  struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
  int size;
  entry_t** table;	
};
 
typedef struct hashtable_s hashtable_t;
 
 
/* Create a new hashtable. */
hashtable_t *ht_create( int size ) {
  hashtable_t *hashtable = NULL;
  int i;
  
  if( size < 1 ) return NULL;
  
  /* Allocate the table itself. */
  if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
    return NULL;
  }
  
  /* Allocate pointers to the head nodes. */
  if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
    return NULL;
  }
  for( i = 0; i < size; i++ ) {
    hashtable->table[i] = NULL;
  }
  
  hashtable->size = size;
  
  return hashtable;	
}
 
/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, void* key ) {
  unsigned long int hashval = (unsigned long int) key;
  return hashval % hashtable->size;
}
 
/* Create a key-value pair. */
entry_t *ht_newpair( void* key, int value ) {
  entry_t *newpair;
  if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
    return NULL;
  }
  newpair->key = key;
  newpair->value = value;
  newpair->next = NULL;
  return newpair;
}
 
/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, void* key, int value ) {
  entry_t *newpair = NULL;
  entry_t *next = NULL;
  entry_t *last = NULL;
  int bin = ht_hash( hashtable, key );
  
  next = hashtable->table[ bin ];
  
  while( next != NULL && next->key != NULL && key != next->key ) {
    last = next;
    next = next->next;
  }
  
  /* There's already a pair. Let's replace that string. */
  if( next != NULL && next->key != NULL && key == next->key ) {
    next->value = value;
    
    /* Nope, could't find it. Time to grow a pair. */
  } else {
    newpair = ht_newpair( key, value );
    
    /* We're at the start of the linked list in this bin. */
    if( next == hashtable->table[ bin ] ) {
      newpair->next = next;
      hashtable->table[ bin ] = newpair;
      /* We're at the end of the linked list in this bin. */
    } else if ( next == NULL ) {
      last->next = newpair;
      /* We're in the middle of the list. */
    } else {
      newpair->next = next;
      last->next = newpair;
    }
  }
}


 
/* Retrieve a key-value pair from a hash table. */
int ht_get( hashtable_t *hashtable, void* key ) {
  entry_t *pair;
  int bin = ht_hash( hashtable, key );
  
  /* Step through the bin, looking for our value. */
  pair = hashtable->table[ bin ];
  while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
    pair = pair->next;
  }
  
  /* Did we actually find anything? */
  if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
    return -1;
    
  } else {
    return pair->value;
  }
}
 
 
int main( int argc, char **argv ) {
  
  hashtable_t *hashtable = ht_create( 65536 );
  
  char* a = "a";
  char* b = "b";
  char* c = "c";
  char* d = "d";
  
  
  ht_set( hashtable, a, 1 );
  ht_set( hashtable, b, 2 );
  ht_set( hashtable, c, 3 );
  ht_set( hashtable, d, 5 );
  
  printf( "%d\n", ht_get( hashtable, a ) );
  printf( "%d\n", ht_get( hashtable, b ) );
  printf( "%d\n", ht_get( hashtable, c ) );
  printf( "%d\n", ht_get( hashtable, d ) );
  
  return 0;
}


void* GC(void* e) {
  return e;
}
