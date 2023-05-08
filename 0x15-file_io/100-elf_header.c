#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

void print_magic_no(unsigned char e_ident[EI_NIDENT]);
void print_class(unsigned char e_ident[EI_NIDENT]);
void print_data(unsigned char e_ident[EI_NIDENT]);
void print_version(unsigned char e_ident[EI_NIDENT]);
void print_abi(unsigned char e_ident[EI_NIDENT]);
void print_abiversion(unsigned char e_ident[EI_NIDENT]);
void print_type(Elf32_Word e_type);
void print_entry(Elf32_Addr e_entry);

/**
 * print_magic_no - prints the magic number of an ELF file header
 * @e_ident: the array containing the magic number.
 *
 * Return: Nothing.
 */
void print_magic_no(unsigned char e_ident[EI_NIDENT])
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * print_class - prints the class of an ELF file header.
 * @e_ident: the array containing the class information.
 *
 * Return: Nothing.
 */
void print_class(unsigned char e_ident[EI_NIDENT])
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %d>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - prints the data encoding of an ELF file header
 * @e_ident: the array containing the data encoding information.
 *
 * Return: Nothing.
 */
void print_data(unsigned char e_ident[EI_NIDENT])
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %d>\n", e_ident[EI_DATA]);
			break;
	}
}

/**
 * print_version - prints the version of an ELF file header.
 * @e_ident: the array containing the version information.
 *
 * Return: Nothing.
 */
void print_version(unsigned char e_ident[EI_NIDENT])
{
	printf("  Version:                           ");
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("none\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("<unknown: %d>\n", e_ident[EI_VERSION]);
			break;
	}
}

/**
 * print_abi - prints the ABI of an ELF file header.
 * @e_ident: the array containing the ABI information.
 *
 * Return: Nothing.
 */
void print_abi(unsigned char e_ident[EI_NIDENT])
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris ABI\n");
			break;
		case ELFOSABI_AIX:
			printf("AIX ABI\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD ABI\n");
			break;
		case ELFOSABI_TRU64:
			printf("Compaq TRU64 UNIX ABI\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell Modesto ABI\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("OpenBSD ABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture ABI\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("<unknown: %d>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
* print_abiversion - prints the ABI version of the ELF header.
* @e_ident: pointer to the EI_IDENT array of the ELF header.
*
* Return: Nothing.
*/
void print_abiversion(unsigned char e_ident[EI_NIDENT])
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
* print_type - prints the type of the ELF header
* @e_type: ELF header type.
*
* Return: Nothing.
*/

void print_type(Elf32_Word e_type)
{
	printf(" Type: ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("0x%x\n", e_type);
			break;
	}
}

/**
*print_entry - prints the entry point address of the ELF header
*@e_entry: entry point address.
*
* Return: Nothing.
*/
void print_entry(Elf32_Addr e_entry)
{
	printf(" Entry point address: 0x%x\n", e_entry);
}

/**
* main - entry point
* @argc: argument count
* @argv: array of arguments
*
* Return: 0 on success and 98 on failure.
*/
int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr ehdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		printf(stderr, "Error: Cannot open file '%s': %s\n", argv[1], strerror(errno));
		return (EXIT_FAILURE);
	}
	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
	{
		fprintf(stderr, "Error: Cannot read ELF header: %s\n", strerror(errno));
		close(fd);
		return (EXIT_FAILURE);
	}
}
