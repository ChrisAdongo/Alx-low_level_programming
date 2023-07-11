#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#define ELF_MAGIC_SIZE 4
#define ELF_CLASS_SIZE 1
#define ELF_DATA_SIZE 1
#define ELF_VERSION_SIZE 1
#define ELF_OSABI_SIZE 1
#define ELF_ABIVERSION_SIZE 1
#define ELF_TYPE_SIZE 2
#define ELF_ENTRY_POINT_SIZE 8

/**
 * struct ELFHeader - ELF file header structure
 * @magic:      Magic numbers
 * @class:      Class (32-bit or 64-bit)
 * @data:       Data encoding (little-endian or big-endian)
 * @version:    ELF version
 * @osabi:      OS/ABI identification
 * @abiversion: ABI version
 * @padding:    Padding bytes
 * @type:       Object file type
 * @entry:      Entry point address
 */
typedef struct ELFHeader
{
	unsigned char magic[ELF_MAGIC_SIZE];
	unsigned char class;
	unsigned char data;
	unsigned char version;
	unsigned char osabi;
	unsigned char abiversion;
	unsigned char padding[7];
	uint16_t type;
	uint64_t entry;
} ELFHeader;

/**
 * print_error - Print error message and exit
 * @message: Error message
 *
 * Prints the given error message to stderr and exits with status code 98.
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * print_elf_header - Print the information in the ELF header
 * @header: Pointer to the ELF header structure
 *
 * Prints the information contained in the ELF header structure.
 */
void print_elf_header(const ELFHeader *header)
{
	printf("Magic: ");
	for (int i = 0; i < ELF_MAGIC_SIZE; i++)
	{
		printf("%02x ", header->magic[i]);
	}
	printf("\nClass: %d-bit\n", header->class == 1 ? 32 : 64);
	printf("Data: %s-endian\n", header->data == 1 ? "Little" : "Big");
	printf("Version: %d\n", header->version);
	printf("OS/ABI: %d\n", header->osabi);
	printf("ABI Version: %d\n", header->abiversion);
	printf("Type: %u\n", header->type);
	printf("Entry point address: 0x%lx\n", header->entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Main function reads the ELF header from a file and prints the information
 * contained in the header. If the file is not an ELF file or an error occurs,
 * it prints an appropriate error message and exits with status code 98.
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Invalid number of arguments");
	}
	const char *filename = argv[1];
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Unable to open file");
	}

	ELFHeader header;
	ssize_t bytes_read = read(fd, &header, sizeof(ELFHeader));

	if (bytes_read != sizeof(ELFHeader))
	{
		print_error("Unable to read ELF header");
	}

	if (memcmp(header.magic, "\x7f\x45\x4c\x46", ELF_MAGIC_SIZE) != 0)
	{
		print_error("Not an ELF file");
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}
