// Define a preprocessor identifier.
#define MY_ID 1

// Check the value of MY_ID.
#if MY_ID == 0
	// Ignore ...
#elif MY_ID == 1
	#warning "MY_ID == 1"
#else
	#error "MY_ID should be either 0 or 1"
#endif


int main()
{
}