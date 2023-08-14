#include "reverseString.h"
#include <stdlib.h>
#include <string.h>

char* reverseString(char* string)
{
	size_t stringLength = strlen(string);
	char* result = (char*)malloc(stringLength + 1); // +1 for null terminating character
	if (!result) { return NULL; }
	result[stringLength] = 0;
	for (size_t index = 0; index < stringLength; ++index) {
		result[index] = string[stringLength - 1 - index];
	}
	return result;
}

void freeString(char* string)
{
	free(string);
}
