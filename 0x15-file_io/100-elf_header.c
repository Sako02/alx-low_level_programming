#include "main.h"
#include "elf.h"
#include <sys/types.h>

/**
 * main -function that print info from ELF header from an ELF file
 * @argc: arguments count
 * @av: arguments vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *av[])
{
	Elf64_Ehdr *ELF;
	int fl, rt;

	fl = open(av[1], O_RDONLY);
	if (fl == -1)
	{
		dprintf(2, "readelf: Error: '%s': No such file\n", av[1]);
		exit(98);
	}

	ELF = malloc(sizeof(Elf64_Ehdr));
	if (ELF == NULL)
	{
		close(fl);
		dprintf(2, "readelf: Error: failed reading file '%s'\n", av[1]);
		exit(98);
	}

	rt = read(fl, ELF, sizeof(Elf64_Ehdr));
	if (rt == -1)
	{
		free(ELF);
		close(fl);
		dprintf(2, "readelf: Error: failed reading file '%s'\n", av[1]);
		exit(98);
	}
	ELF_check(ELF->e_ident, av[1]);
	printf("ELF Header:\n");
	ELF_magic(ELF->e_ident);
	ELF_class(ELF->e_ident);
	ELF_data(ELF->e_ident);
	ELF_version(ELF->e_ident);
	ELF_osabi(ELF->e_ident);
	ELF_abiVersion(ELF->e_ident);
	ELF_type(ELF->e_ident, ELF->e_type);
	ELF_entry(ELF->e_ident, ELF->e_entry);

	free(ELF);
	(void)argc;
	return (0);
}
/**
 * ELF_check - checks if the file is an ELF file
 * @elf_ident: the ELF magic number
 * @str: filename
 */
void ELF_check(unsigned char *elf_ident, char *str)
{
	const char elf_magic[] = {0x7f, 'E', 'L', 'F'};

	if (elf_ident[0] != elf_magic[0] || elf_ident[1] != elf_magic[1] ||
	    elf_ident[2] != elf_magic[2] || elf_ident[3] != elf_magic[3])
	{
		dprintf(2, "elfread: Error: '%s': Not an ELF file\n", str);
		exit(98);
	}
}
/**
 * ELF_magic - display the magic number
 * @elf_ident: the ELF magic number
 */
void ELF_magic(unsigned char *elf_ident)
{
	int j;

	printf("  Magic:   ");
	for (j = 0; j < 16; j++)
	{
		printf("%02x", elf_ident[j]);
		if (j == 15)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * ELF_class - display the ELF file class
 * @elf_ident: the ELF magic number
 */
void ELF_class(unsigned char *elf_ident)
{
	printf("  Class:                             ");
	if (elf_ident[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (elf_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (elf_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
}
/**
 * ELF_data - display the ELF file data
 * @elf_ident: the ELF magic number
 */
void ELF_data(unsigned char *elf_ident)
{
	printf("  Data:                              ");

	if (elf_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else  if (elf_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else if (elf_ident[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
}
/**
 * ELF_version - display the ELF  version
 *
 * @elf_ident: the ELF magic number
 */
void ELF_version(unsigned char *elf_ident)
{
	printf("  Version:                           ");
	printf("%d", elf_ident[EI_VERSION]);

	if (elf_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * ELF_osabi - display the ELF file OS/ABI
 * @elf_ident: the ELF magic number
 */
void ELF_osabi(unsigned char *elf_ident)
{
	printf("  OS/ABI:                            ");

	if (elf_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else if (elf_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else
		printf("<unknown: %x>\n", elf_ident[EI_OSABI]);

}
/**
 * ELF_abiVersion - display the ELF file type
 * @e_i: the ELF magic number
 */
void ELF_abiVersion(unsigned char *e_i)
{
	printf("  ABI Version:                       %d\n", e_i[EI_ABIVERSION]);
}

/**
 * ELF_type - display the ELF file type
 * @elf_ident: the ELF magic number
 * @elf_type: the ELF type
 */
void ELF_type(unsigned char *elf_ident, unsigned int elf_type)
{
	printf("  Type:                              ");

	if (elf_ident[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	if (elf_type == ET_NONE)
		printf("NONE (None)\n");
	else if (elf_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (elf_type == ET_CORE)
		printf("CORE (Core file)\n");
	else if (elf_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (elf_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else
		printf("<unknown: %x>\n", elf_type);
}

/**
 * ELF_entry - display the ELF file entry point adress
 * @elf_ident: the ELF magic number
 * @elf_entry: the ELF entry
 */
void ELF_entry(unsigned char *elf_ident, unsigned long int elf_entry)
{
	printf("  Entry point address:               ");

	if (elf_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else if (elf_ident[EI_CLASS] == ELFCLASS64)
		printf("%#lx\n", elf_entry);

	else
		printf("<unknown ELF class>\n");
}
