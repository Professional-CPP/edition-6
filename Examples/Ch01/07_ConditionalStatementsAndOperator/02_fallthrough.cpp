int main()
{
	enum class Mode { Default, Custom, Standard };

	int value{ 42 };
	Mode mode{ Mode::Custom };

	switch (mode) {
		using enum Mode;

		case Custom:
			value = 84;
			[[fallthrough]];
		case Standard:
		case Default:
			// Do something with value ...
			break;
	}
}
