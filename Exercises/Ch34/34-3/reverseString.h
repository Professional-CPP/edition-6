#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Allocates a new string and initializes it with the reverse of a given string.
	/// </summary>
	/// <param name="string">The source string to reverse.</param>
	/// <returns>A newly allocated buffer filled with the reverse of the
	/// given string.
	/// The returned memory needs to be freed with freeString().</returns>
	char* reverseString(char* string);

	/// <summary>Frees the memory allocated for the given string.</summary>
	/// <param name="string">The string to deallocate.</param>
	void freeString(char* string);

#ifdef __cplusplus
} // matches extern "C"
#endif
