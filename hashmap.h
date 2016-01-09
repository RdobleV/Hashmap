#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct entry entry;

struct entry
{
	char *key;
	char *value;
	entry *next;   
};

typedef struct HashMap HashMap;

struct HashMap
{
	size_t size;
	entry **buckets;

};
typedef void * (*DestroyDataCallback) (void *);
typedef void * (*ResolveCollisionCallback) (void *, void *);


HashMap * create_hashmap(size_t key_space);

unsigned int hash(const char *input, HashMap *hm);

void insert_data(HashMap * hm, const char *key, void * data, ResolveCollisionCallback resolve_collision);

void * ResolveCollision(void *old_data, void *new_data);

void * get_data(HashMap *hm, const char *key) ;

void iterate(HashMap *hm, void (*callback)(const char*, void *));

void remove_data(HashMap *hm, const char *key, DestroyDataCallback *destroy_data); 

void delete_hashmap(HashMap *hm, DestroyDataCallback *destroy_data);

