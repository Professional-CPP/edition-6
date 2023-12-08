int main()
{
	int value{ 4 };
	if (value > 11) [[unlikely]] { /* Do something ... */ }
	else { /* Do something else... */ }

	switch (value)
	{
	[[likely]] case 1:
		// Do something ...
		break;
	case 2:
		// Do something...
		break;
	[[unlikely]] case 12:
		// Do something...
		break;
	}
}