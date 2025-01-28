#include "Serializer.hpp"

int	main(void)
{
	// Create a Data structure and initialize it
	Data *data = new Data;
	data->str = "Hello, World!";

	// Print original values
	std::cout << "Original pointer: " << data << std::endl;
	std::cout << "Original string: " << data->str << std::endl;

	// Serialize and deserialize
	uintptr_t serialized = Serializer::serialize(data); // Converts the memory address to a number
	Data *deserialized = Serializer::deserialize(serialized);   // Converts the number back to a memory address

	// Print results
	std::cout << "Serialized value: " << serialized << std::endl;   // Shows the number version of our address
	std::cout << "Deserialized pointer: " << deserialized << std::endl; // Shows the address after converting back
	std::cout << "Deserialized string: " << deserialized->str << std::endl; // Shows our string is still accessible

	// Compare pointers
	if (data == deserialized)
	{
		std::cout << "Success: Pointers match!" << std::endl;
	}
	else
	{
		std::cout << "Error: Pointers don't match!" << std::endl;
	}

	delete data;
	return (0);
}