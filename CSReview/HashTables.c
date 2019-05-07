#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/****
  Basic hash table key/value pair
 ****/
typedef struct Pair {
  char *key;
  char *value;
} Pair;

/****
  Basic hash table
 ****/
typedef struct BasicHashTable {
  int capacity;
  Pair **storage;
} BasicHashTable;

/****
  Create a key/value pair to be stored in the hash table.
 ****/
Pair *create_pair(char *key, char *value)
{
  Pair *pair = malloc(sizeof(Pair));
  pair->key = key;
  pair->value = value;

  return pair;
}

/****
  Use this function to safely destroy a hashtable pair.
 ****/
void destroy_pair(Pair *pair)
{
  if (pair != NULL) free(pair);
}

/****
  djb2 hash function

  Do not modify this!
 ****/
unsigned int hash(char *str, int max)
{
  unsigned long hash = 5381;
  int c;
  unsigned char * u_str = (unsigned char *)str;

  while ((c = *u_str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash % max;
}


/****
  Fill this in.

  All values in storage should be initialized to NULL
  (hint: look up `calloc`)
 ****/
/*
create_hash_table(3);
*/
BasicHashTable *create_hash_table(int capacity)
{
  BasicHashTable *ht = malloc(sizeof(BasicHashTable));
  ht->capacity = capacity; //indices in an array
  ht->storage = calloc(capacity, sizeof(Pair *)); //this size of struct 
  return ht;
}

/****
  Fill this in.

  If you are overwriting a value with a different key, print a warning.

  Don't forget to free any malloc'ed memory!
 ****/
void hash_table_insert(BasicHashTable *ht, char *key, char *value)
{

  int hashkey = hash(key, ht->capacity); 
  Pair *pair = create_pair(key, value); 
  ht->storage[hashkey] = pair;

}

/****
  Fill this in.

  Don't forget to free any malloc'ed memory!
 ****/
void hash_table_remove(BasicHashTable *ht, char *key)
{
  if(ht->storage[hash(key, ht->capacity)] != NULL ) {
    free(ht->storage[hash(key, ht->capacity)]);
    
    ht->storage[hash(key, ht->capacity)] = NULL;
  } 

}

/****
  Fill this in.

  Should return NULL if the key is not found.
 ****/
char *hash_table_retrieve(BasicHashTable *ht, char *key)
{

  int indexVal = hash(key, ht->capacity);

  if(ht->storage[indexVal] == NULL) {
    return NULL;
  }else{
    return ht->storage[indexVal]->value;
  }
  

}

/****
  Fill this in.

  Don't forget to free any malloc'ed memory!
 ****/
void destroy_hash_table(BasicHashTable *ht)
{
  if (ht != NULL) free(ht);
}


#ifndef TESTING
int main(void)
{
  printf("about to create Ht table\n");
  struct BasicHashTable *ht = create_hash_table(16);
  printf("created the table\n");

  hash_table_insert(ht, "line", "Here today...\n");
  printf("inserted into the table\n");

  printf("%s", hash_table_retrieve(ht, "line"));
  printf("retrieved the value from the ht\n");
  
  hash_table_remove(ht, "line");
  printf("removed from the hashtable\n");
  
  if (hash_table_retrieve(ht, "line") == NULL) {
    printf("...gone tomorrow. (success)\n");
  } else {
    fprintf(stderr, "ERROR: STILL HERE\n");
  }
  printf("retreive from the tables\n");
  
  destroy_hash_table(ht);
  printf("destroyed the table\n");
  return 0;
}
#endif
