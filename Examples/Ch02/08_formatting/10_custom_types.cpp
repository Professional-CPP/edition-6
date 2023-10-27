import std;

using namespace std;

class KeyValue
{
public:
	KeyValue(string_view key, int value) : m_key{ key }, m_value{ value } {}

	const string& getKey() const { return m_key; }
	int getValue() const { return m_value; }

private:
	string m_key;
	int m_value{ 0 };
};

template<>
class std::formatter<KeyValue>
{
public:
	constexpr auto parse(auto& context)
	{
		string keyFormat, valueFormat;
		size_t numberOfParsedColons{ 0 };
		auto iter{ begin(context) };
		for (; iter != end(context); ++iter) {
			if (*iter == '}') {
				break;
			}

			if (numberOfParsedColons == 0) { // Parsing output type
				switch (*iter) {
				case 'k': case 'K':  // {:k format specifier
					m_outputType = OutputType::KeyOnly;
					break;
				case 'v': case 'V':  // {:v format specifier
					m_outputType = OutputType::ValueOnly;
					break;
				case 'b': case 'B':  // {:b format specifier
					m_outputType = OutputType::KeyAndValue;
					break;
				case ':':
					++numberOfParsedColons;
					break;
				default:
					throw format_error{ "Invalid KeyValue format." };
				}
			} else if (numberOfParsedColons == 1) { // Parsing key format
				if (*iter == ':') {
					++numberOfParsedColons;
				} else {
					keyFormat += *iter;
				}
			} else if (numberOfParsedColons == 2) { // Parsing value format
				valueFormat += *iter;
			}
		}

		// Validate key format specifier.
		if (!keyFormat.empty()) {
			format_parse_context keyFormatterContext{ keyFormat };
			m_keyFormatter.parse(keyFormatterContext);
		}

		// Validate value format specifier.
		if (!valueFormat.empty()) {
			format_parse_context valueFormatterContext{ valueFormat };
			m_valueFormatter.parse(valueFormatterContext);
		}

		if (iter != end(context) && *iter != '}') {
			throw format_error{ "Invalid KeyValue format." };
		}

		return iter;
	}

	auto format(const KeyValue& kv, auto& ctx) const
	{
		switch (m_outputType) {
			using enum OutputType;

		case KeyOnly:
			ctx.advance_to(m_keyFormatter.format(kv.getKey(), ctx));
			break;
		case ValueOnly:
			ctx.advance_to(m_valueFormatter.format(kv.getValue(), ctx));
			break;
		default:
			ctx.advance_to(m_keyFormatter.format(kv.getKey(), ctx));
			ctx.advance_to(format_to(ctx.out(), " - "));
			ctx.advance_to(m_valueFormatter.format(kv.getValue(), ctx));
			break;
		}

		return ctx.out();
	}

private:
	enum class OutputType
	{
		KeyOnly,
		ValueOnly,
		KeyAndValue
	};

	OutputType m_outputType{ OutputType::KeyAndValue };
	formatter<string> m_keyFormatter;
	formatter<int> m_valueFormatter;
};


int main()
{
	const size_t len{ 34 }; // Label field length
	KeyValue kv{ "Key 1", 255 };

	println("{:>{}} {}",   "Default:", len, kv);
	println("{:>{}} {:k}", "Key only:", len, kv);
	println("{:>{}} {:v}", "Value only:", len, kv);
	println("{:>{}} {:b}", "Key and value with default format:", len, kv);
	
	println("{:>{}} {:k:*^11}",     "Key only with special format:", len, kv);
	println("{:>{}} {:v::#06X}",    "Value only with special format:", len, kv);
	println("{:>{}} {::*^11:#06X}", "Key and value with special format:", len, kv);

	try {
		auto formatted{ vformat("{:cd}", make_format_args(kv)) };
		println("{}", formatted);
	} catch (const format_error& caught_exception) {
		println("{}", caught_exception.what());
	}
}