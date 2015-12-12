#include <stdio.h>
#include <string.h>
#include "hashmap.h"

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
	size_t^2 size;
	entry **buckets;

};

typedef void * (*ResolveCollision) (void *old_data, void *new_data);

typedef void * (*iterate_callback) (char *key, void *data);


HashMap * create_hasmap(size_t^2 key_space)
{
	/*Implement a function create_hashmap that returns a pointer to the newly constructed HashMap structure and has parameter
	• key_space, a size_t^2	that represents the number of buckets in the hash map.
	This function should allocate enough memory to fit key_space buckets, and the allocated memory should be zeroed 
	(i.e., NULLed)*/

	HashMap * newp =NULL;
	int i;

	if (size_t^2 <1) return NULL;

	//allocate hashmap
	if( (newp = malloc( sizeof( HashMap ) ) ) = NULL )
	{
		return NULL;
	}

	if( ( newp->buckets = malloc( sizeof( entry *) * key_space) ) ==NULL)
	{
		return NULL;
	}

	for (int i = 0; i < key; ++i)
	{
		newp->buckets[i] = NULL;
	}

	return newp;//POINTER TO THE NEW HASMAP
	}
}

unsigned int hash(unsigned char *input, HashMap hm)		//dan bernstein hash function
{
	unsigned int hash_value = 5381;

	int i;

	while (i = *input++)
		hash_value = (33*hash_value) +i;	//hash_value *33 +i 


	return hash_value % sizeof(hm->size);
}

void insert_data(HashMap * hm, char *key, void * data, ResolveCollision resolve_collision) //KEY FIXEN, RESOLVE COLLISION FIXEN
{
	/*
	Implement a function insert_data that has parameters
	• hm, a pointer to a hash map;
	• key, a null-terminated string of characters;
	• data, a void pointer to the source data;
	• resolve_collision, a ResolveCollisionCallback (see below).
	The function should store the data pointer and a copy of the key in the bucket
	that can be found by applying the hash function on the key. In case of a
	collision, i.e. when there already is data with the same key in the hash map, the
	resolve_collision function should be called with the the previously stored
	data and data as arguments and the returned void pointer should be stored in
	the bucket instead.
	*/

	unsigned int bucket_num = hash(key,hm);

	//check for collision
	if(hm.buckets[bucket_num] -> key !=NULL || hm.buckets[bucket_num] -> data != NULL)
	{
		//collision detected
		void* col_sol = ResolveCollision(hm.buckets[bucket_num] ->data, data);
		hm.buckets[bucket_num] -> data = col_sol;
	}
	
	//call resolve_collision: pointer to old data (retrieve) pointer to new data
	//store returned void pointer
	else{
		//if no collision
		//store key 
		memcpy(hm.buckets[bucket_num] ->key, key, sizeof(key));
		//store data pointer
		hm.buckets[bucket_num] -> data = data;
	}
}

void * ResolveCollision(void *old_data, void *new_data)
{
	/*
	ResolveCollisionCallback, a pointer to a function that returns a void pointer
	and has two parameters:
	• old_data, a void pointer to the previously stored data;
	• new_data, a void pointer to the data that is being newly inserted.
	The function should determine what data is stored in the has map in case of a
	key collision by returning the void pointer to the data that is to be stored.
	*/
	//stop de nieuwe data in de volgende bucket die geen collision oplevert, 
	//return pointer naar die bucket. (bedenk iets waardoor je de old data niet kwijtraakt (list oid))

	//make linked list met de pointers naar de data
	//
}




void * get_data(HashMap *hm, char *key) 
{
	/*
	Implement a function get_data that has parameters
	• hm, a pointer to a hash map;
	• key, a null-terminated string of characters.
	The function should return the data pointer (a void pointer) in the hash std::map<key, value> map;
	that is associated with the key. If the key is not present in the hash map, NULL
	should be returned.
	*/


	unsigned int bin = 0;
	entry data;

	bin = hash(key);

	data = hashmap->buckets[bin];

	if (data == NULL )
	{
		return NULL;
	}

	return data;


}

void iterate(HashMap *hm, iterate_callback callback)	//CALLBACK FUCTION POINTER MAKEN, KEY FIXEN, is deze functie void?
{
	/*
	Implement a function iterate that has parameters
	• hm, a pointer to a hash map;
	• callback, a pointer to a function that returns nothing (i.e. void) and has
	two parameters:
	– key, a null-terminated string of characters;
	– data, a void pointer to the data.
	This function should iterate over the entire hash map. For each data element
	it finds, the callback function should be called with the two members of the
	element.
	*/
}

void iterate_callback(char *key, void *data)
{
	//callback, a pointer to a function that returns nothing (i.e. void) and has
	//two parameters:
	//– key, a null-terminated string of characters;
	//– data, a void pointer to the data.
	//This function should iterate over the entire hash map. For each data element
	//it finds, the callback function should be called with the two members of the
	//element.
}

void remove_data(HashMap *hm, char *key, void (*DestroyData_Callback)(void *data)) //fix destroy_data
{
	/*Implement a function remove_data that has parameters
	• hm, a pointer to a hash map;
	• key, a null-terminated string of characters.
	• destroy_data, a DestroyDataCallback (see below).
	This function should remove the data in the hash map that is associated with
	the given key. If the destroy_data parameter is non-NULL it should be called
	with the data pointer of the element as argument. If the key is not present, the
	hash map should remain untouched. As the remove_data function cannot fail,
	its return type is void.

	*/
}

void DestroyDataCallback(void *data)
{
	/*
	DestroyDataCallback, a pointer to to a function that returns nothing (i.e.
	void) and has one parameter:
	• data, a void pointer.
	The function should clean up the data (e.g. free allocated memory).
	*/

}



void delete_hasmap(HashMap *hm, destroy_data) //destroydata fixen.
{
	/*  Implement a function delete_hashmap that has parameters
	• hm, a pointer to the hash map that is to be deleted;
	• destroy_data, a DestroyDataCallback (see 7).	
	The function should deallocate all memory that was allocated by the hash map.
	If the destroy_data parameter is non-NULL it should be called for every data
	element that is stored in the hash map with the data pointer of the element as
	argument */
}

//BONUS 9, 10 see assignment

//11 submission
/*
	Finished assignments should be uploaded to CPM, and submissions should adhere
to the following requirements:
• Put all the hash map source code inside a file called hashmap.c;
• Put all the word count source code inside a file called wordcount.c;
• Include a header file hashmap.h that contains all your (public) hash map
function prototypes and data types. In the header file, also place the
following preprocessor directive if you have completed the first bonus
exercise:
#define NEW_HASH
• Include a header file wordcount.h only if you have completed the Counting
Words bonus exercise that contains the public function prototype.
• Do not include a main function. (We will use our own test driver, just like
the example test provided.)
• Create a ZIP file of the hashmap.[ch] files by executing make submit.
Upload this ZIP file to CPM.
Submissions violating the above requirements will be rejected.
*/
