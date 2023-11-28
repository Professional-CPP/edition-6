export module key_value_pair;

import std;

export
template <std::integral Key, std::floating_point Value>
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
