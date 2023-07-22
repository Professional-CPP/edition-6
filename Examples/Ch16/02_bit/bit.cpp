import std;

using namespace std;

int main()
{
	println("{}", popcount(0b10101010u)); // 4

	uint8_t value{ 0b11101011u };
	println("{}", countl_one(value));     // 3
	println("{}", countr_one(value));     // 2

	value = 0b10001000u;
	println("{:08b}", rotl(value, 2));    // 00100010

	value = 0b00001011u;
	println("bit_ceil({0:08b} = {0}) = {1:08b} = {1}",
		value, bit_ceil(value));          // bit_ceil(00001011 = 11) = 00010000 = 16
	println("bit_floor({0:08b} = {0}) = {1:08b} = {1}",
		value, bit_floor(value));         // bit_floor(00001011 = 11) = 00001000 = 8

	uint32_t before{ 0x12345678u };
	println("{:x}", before);              // 12345678
	uint32_t after{ byteswap(before) };   // C++23 std::byteswap().
	println("{:x}", after);               // 78563412
}
