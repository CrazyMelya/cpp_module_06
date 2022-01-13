#include <iostream>
#include <typeinfo>

typedef struct s_data
{
	int age;
	std::string name;
}				Data;

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t> (ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data data = {25, "Vlad"};
	uintptr_t uin;
	Data *after;

	std::cout << "Before: " << data.age << " " + data.name << std::endl;
	uin = serialize(&data);
	std::cout << "uintptr_t: " << uin << std::endl;
	after = deserialize(uin);
	std::cout << "After: " << after->age << " " + data.name << std::endl;
}
