export module key_value_pair;

import std;

export
template <typename Key, typename Value>
class KeyValuePair
{
public:
	// See Chapter 9 about using pass-by-value semantics.
	explicit KeyValuePair(Key key, Value value)
		: m_key{ std::move(key) }
		, m_value{ std::move(value) }
	{
	}

	const Key& getKey() const { return m_key; }
	void setKey(Key key) { m_key = std::move(key); }

	const Value& getValue() const { return m_value; }
	void setValue(Value value) { m_value = std::move(value); }

private:
	Key m_key;
	Value m_value;
};



// A full specialization of KeyValuePair<> for const char*s.
export
template<>
class KeyValuePair<const char*, const char*>
{
public:
	explicit KeyValuePair(const char* key, const char* value)
		: m_key{ key }
		, m_value{ value }
	{
	}

	const std::string& getKey() const { return m_key; }
	void setKey(const char* key) { m_key = key; }

	const std::string& getValue() const { return m_value; }
	void setValue(const char* value) { m_value = value; }

private:
	std::string m_key;
	std::string m_value;
};
