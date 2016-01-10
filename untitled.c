#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned int hash(const char *input)		
{
	unsigned int hash_value = 0;

	

	while (*input)
	{
		hash_value +=(unsigned int) *input++ ;	//hash_value *33 +i 
	}


	return hash_value % 1024;

}

void main(){
	const char * key_1    = "ab";
	const char * key_2    = "cd";
	const char * key_3    = "ad";
	const char * key_4    = "xy";
	unsigned int a = hash(key_1);
	unsigned int b = hash(key_2);
	unsigned int c = hash(key_3);
	unsigned int d = hash(key_4);

	printf("(\"%u)\n", a);
	printf("(\"%u)\n", b);
	printf("(\"%u)\n", c);
	printf("(\"%u)\n", d);
}