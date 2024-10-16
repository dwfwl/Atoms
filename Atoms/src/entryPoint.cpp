#include <Atoms/Atoms.h>

int main()
{
	Atoms& atoms = Atoms::Get();
	atoms.initialize();
	atoms.run();
	atoms.cleanup();
}