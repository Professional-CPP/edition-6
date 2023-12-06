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



// A partial specialization of KeyValuePair<> for const char* values.
export
template<typename Key>
class KeyValuePair<Key, const char*>
{
public:
	// See Chapter 9 about using pass-by-value semantics.
	explicit KeyValuePair(Key key, const char* value)
		: m_key{ std::move(key) }
		, m_value{ value }
	{
	}

	const Key& getKey() const { return m_key; }
	void setKey(Key key) { m_key = std::move(key); }

	const std::string& getValue() const { return m_value; }
	void setValue(const char* value) { m_value = value; }

private:
	Key m_key;
	std::string m_value;
};
