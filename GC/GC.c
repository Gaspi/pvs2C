
// Hashtable code from :
// https://gist.github.com/tonious/1377667

#define _XOPEN_SOURCE 500 // Enable certain library functions (strdup) on linux.
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
 
struct entry_s {
  void* pointer;
  int counter;
  int rec_free;
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
  int i;
  if( size < 1 ) return NULL;
  
  hashtable_t *res = NULL;
  
  /* Allocate the table itself. */
  if( ( res = malloc( sizeof( hashtable_t ) ) ) == NULL )
    return NULL;
  
  /* Allocate pointers to the head nodes. */
  if( ( res->table = malloc( sizeof( entry_t * ) * size ) ) == NULL )
    return NULL;
  
  res->size = size;
  for( i = 0; i < size; i++ )
    res->table[i] = NULL;
  
  return res;	
}
 
/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, void* pointer ) {
  unsigned long int hashval = (unsigned long int) pointer;
  return hashval % hashtable->size;
}
 
/* Create a key-value pair. */
entry_t *ht_newpair( void* pointer, int rec_free ) {
  entry_t *newpair;
  if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL )
    return NULL;
  
  newpair->pointer  = pointer;
  newpair->counter  = 1;     // Default value
  newpair->rec_free = rec_free;
  newpair->next = NULL;
  return newpair;
}


hashtable_t *GC_hashtable;

void GC_start() {
  GC_hashtable = ht_create( 65536 );
}

void GC_quit() {
  // Should also free the list in each cell
  free(GC_hashtable);
}

entry_t* GC_get_entry( void* pointer ) {
  int bin = ht_hash( GC_hashtable, pointer);
  entry_t* next = GC_hashtable->table[ bin ];
  while( next != NULL && next->pointer != NULL && pointer != next->pointer )
    next = next->next;
  if( next != NULL && next->pointer != NULL )
    return next;
  else
    return NULL;
}

void GC_add_entry( entry_t* e) {
  int bin = ht_hash( GC_hashtable, e->pointer );
  e->next = GC_hashtable->table[bin];
  GC_hashtable->table[bin] = e;
}

void GC_new( void* pointer, int rec_free) {
  GC_add_entry( ht_newpair(pointer, rec_free) );
}

int GC_incr( void* pointer) {
  entry_t* entry = GC_get_entry( pointer);
  if ( entry == NULL )
    return -1;
  else {
    entry->counter++;
    return entry->counter;
  }
}

int GC_count( void* pointer ) {
  entry_t* entry = GC_get_entry( pointer);
  if ( entry == NULL )
    return -1;
  else
    return entry->counter;
}

void* GC(void* pointer) {
  GC_incr( pointer );
  return pointer;
}


// rec_free means need recusive freeing (bascially, is domain a pointer type ?)
// if rec_free != 0 then entry->rec_free is set to the length of the array
void* GC_malloc( int length, int size, int rec_free ) {
  void* res = malloc( length * size );
  if (rec_free)
    GC_new( res, length);
  else
    GC_new( res, 0);
  return res;
}

void GC_free(void* pointer) {
  int i;
  entry_t* e = GC_get_entry(pointer);
  for (i = 0; i < e->rec_free; i++) {
    if ( *(pointer+i) != NULL )
      GC_free(pointer[i]);
  }
  free(pointer);
}


 
int main( int argc, char **argv ) {
  GC_start();
  
  char* a = "a";
  
  GC_new( a , 0);
  GC_incr( a );
  GC_incr( a );
  
  char* b = "b";
  GC_new( b, 1);
  
  printf( "%d\n", GC_count( a ) );
  printf( "%d\n", GC_count( b ) );
  
  GC_quit();
  return 0;
}

