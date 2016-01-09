#include "hashmap.h"






HashMap * create_hashmap(size_t key_space)
{
	

	HashMap * newp;
	
	if (key_space <1) return NULL;

	//allocate hashmap
	if( (newp = malloc( sizeof( HashMap ) ) ) == NULL )
	{
		return NULL;
	}

	if( ( newp->buckets = malloc( sizeof( entry *) * key_space) ) ==NULL)
	{
		return NULL;
	}

	for (size_t i = 0; i < key_space; ++i)
	{
		newp->buckets[i].key = NULL;
		newp->buckets[i].value = NULL;
	}

	return newp;//POINTER TO THE NEW HASMAP
	}


unsigned int hash(const char *input, HashMap *hm)		
{
	unsigned int hash_value = 0;

	

	while (*input)
	{
		hash_value +=(unsigned int) *input++ ;	//hash_value *33 +i 
	}


	return hash_value % sizeof(hm->size);
}

/* old hash function
unsigned int hash(const char *input, HashMap *hm)		
{
	unsigned int hash_value = 5381;

	unsigned int i;

	while ((i = *input++))
	{
		hash_value = (33*hash_value) +i;	//hash_value *33 +i 
	}


	return hash_value % sizeof(hm->size);
}

*/

void insert_data(HashMap * hm, const char *key, void * data, ResolveCollisionCallback resolve_collision) 
{


	unsigned int bucket_num = hash(key,hm);
	//char test = hm -> buckets[bucket_num].key;
	//check for collision
	if(hm->buckets[bucket_num].key !=NULL || hm->buckets[bucket_num].value != NULL)
	{
		//collision detected
		//free(hm);
	void* col_sol = resolve_collision(hm->buckets[bucket_num].value, data);
		hm->buckets[bucket_num].value = col_sol;
	}
	
	//call resolve_collision: pointer to old data (retrieve) pointer to new data
	//store returned void pointer
	else{
		//if no collision
		//store key 
		int length  = sizeof(key);
		hm->buckets[bucket_num].key = (char *) malloc(length);		
		strncpy(hm->buckets[bucket_num].key, key,length);
		//store data pointer
		hm->buckets[bucket_num].value = (char *) malloc(length);
		hm->buckets[bucket_num].value = data;
	}
}

/*
void * ResolveCollisionCallback(void *old_data, void *new_data)
{

	void * *newlist = malloc(sizeof(old_data) + sizeof(new_data));

	newlist[0]= old_data;
	newlist[1]= new_data;

	return newlist;

}
*/
void * get_data(HashMap *hm, const char *key) 
{


	unsigned int bin = 0;
	void * data;

	bin = hash(key,hm);

	data = hm->buckets[bin].value;

	return data;


}

void iterate(HashMap *hm, void (*callback)(const char*, void *))	
{
	
	size_t i;
	
	for (i = 0; i < hm->size; ++i)
	{
		if(hm->buckets[i].value)
		{
			(*callback)(hm->buckets[i].key, hm->buckets[i].value);
		}
		

	}
}

/*
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
*/
//void * data, void *(*ResolveCollisionCallback)(void*, void *)
//void remove_data(HashMap *hm, const char *key, DestroyDataCallback destroy_data)
void remove_data(HashMap *hm, const char *key, DestroyDataCallback destroy_data) 
{

	if(key !=NULL)
	{
		unsigned int hask = hash(key,hm);
		//free(hm->buckets[hask].value);
		hm->buckets[hask].value=NULL;
		
		if(destroy_data !=NULL)
		{
			destroy_data(hm->buckets[hask].value);
		}
		
	}


}
/*
void DestroyDataCallback(void *data)
{
	if(data != NULL){
		free(data);
	}
	
}
*/

//void delete_hasmap(HashMap *hm, DestroyDataCallback destroy_data)
void delete_hashmap(HashMap *hm, DestroyDataCallback *destroy_data)
{
	
	if (destroy_data !=NULL)
	{
		
		for (unsigned int i = 0; i < hm->size; ++i)
		{
			free(hm->buckets[i].value);
		}
	}

	free(hm);
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
