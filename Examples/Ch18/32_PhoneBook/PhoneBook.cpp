import std;

using namespace std;

void printMap(const auto& m)
{
	for (auto& [key, value] : m) {
		println("{} (Phone: {})", key, value);
	}

	println("-------");
}

int main()
{
	// Create a hash table.
	unordered_map<string, string> phoneBook{
		{ "Marc G.", "123-456789" },
		{ "Scott K.", "654-987321" } };
	printMap(phoneBook);

	// Add/remove some phone numbers.
	phoneBook.insert(make_pair("John D.", "321-987654"));
	phoneBook["Johan G."] = "963-258147";
	phoneBook["Freddy K."] = "999-256256";
	phoneBook.erase("Freddy K.");
	printMap(phoneBook);

	// Find the bucket index for a specific key.
	const size_t bucket{ phoneBook.bucket("Marc G.") };
	println("Marc G. is in bucket {} containing the following {} names:",
		bucket, phoneBook.bucket_size(bucket));
	// Get begin and end iterators for the elements in this bucket.
	// 'auto' is used here. The compiler deduces the type of
	// both as unordered_map<string, string>::const_local_iterator
	auto localBegin{ phoneBook.cbegin(bucket) };
	auto localEnd{ phoneBook.cend(bucket) };
	for (auto iter{ localBegin }; iter != localEnd; ++iter) {
		println("\t{} (Phone: {})", iter->first, iter->second);
	}
	println("-------");

	// Print some statistics about the hash table
	println("There are {} buckets.", phoneBook.bucket_count());
	println("Average number of elements in a bucket is {}.",
		phoneBook.load_factor());
}
