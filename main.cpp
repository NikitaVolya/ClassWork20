
#include <iostream>

namespace Bit
{
	float transform(float Kbytes) { return Kbytes * 8192; }
}

namespace Gram
{
	float transform(float Kilogram) { return Kilogram * 1000; }
}

int main()
{
	short choice;
	float number;
	do {
		std::cout << "Select type to transform: 1)Bits 2)Grams: ";
		std::cin >> choice;
	} while (choice != 1 && choice != 2);
	std::cout << "Write number of ";
	switch (choice)
	{
	case 1:
		std::cout << "Kbtyes: ";
		std::cin >> number;
		std::cout << "Is " << Bit::transform(number) << " bits";
		break;
	case 2:
		std::cout << "Kilograms: ";
		std::cin >> number;
		std::cout << "Is " << Bit::transform(number) << " grams";
		break;
	}

	return 0;
}