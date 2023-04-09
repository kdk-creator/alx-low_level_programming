#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Check if a file is an elf file
 * @e_ident: point to an array containing the elf numbers
 * Description: if the file is not an elf file exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_indent[index] != 'L' &&
				e_indent(index) != 'F')
		{
			dprintf(STDERR_FILNO, "Error: NOT ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_class - print out the class of an elf header
 * @e_ident: pointer to array containing the elf class
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class:           ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			print("none\n");
			break;
		case ELFCLASS32:
			print("ELF32\n");
		case ELFCLASS64:
			print("ELF64\n");
			break;
		default:
			print("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - prints the data of an elf header.
 * @e_ident: pointer to array containinig the elf class
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data:            ")
		switch (e_ident[EI_DATA])
		{
			case ELFDATANONE:
				print("none\n");
				break;
			case ELFDATA2LSB:
				printf("2's compliment, little endian\n");
				break;
			case ELFDATA2MSB:
				printf("2's compliment, big endian\n");
				break;
			default:
				printf("<unknown: %x>\n", e_ident[EI_CLASS]);
		}
}

/**
 * print_version - prints version of an elf header.
 * @e_ident: points to an array containing the elf version
 */
void print_version(unsigned char *e_ident)
{
	printf(" Version:         %d",
			e_ident[EL_VERSION]);
	switch (e_ident[EL_VERSION])
	{
		case EV_CURRENT:
			print("(current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_osabi - prints the OS/ABI of an elf header.
 * @e_ident: points to the array containing te elf version
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI:            ");

	switch (e_ident[EL_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			print("UNIX -HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			print("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - prints the abi version of anelf header.
 * @e_ident: point to an array containing the version of elf abi version
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version       %d\n",
			e_idnet[EL_ABIVERiSION]);
}


/**
 * print_type - Prints the type of elf header
 * @e_type: the elf type.
 * @e_ident:point to an array containing the elf class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EL_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("Type:           ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			print("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - to print the entry point of an elf header
 * @e_entry: the address of theelf entry point
 * @e_ident: points to an array containing the elf class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address:         ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EL_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsinged int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
