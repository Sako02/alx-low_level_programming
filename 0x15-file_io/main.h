#ifndef MAIN_H
#define MAIN_H

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFSIZE 1024

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void ELF_check(unsigned char *e_ident, char *str);
void ELF_magic(unsigned char *e_ident);
void ELF_class(unsigned char *e_ident);
void ELF_data(unsigned char *e_ident);
void ELF_version(unsigned char *e_ident);
void ELF_osabi(unsigned char *e_ident);
void ELF_abiVersion(unsigned char *e_ident);
void ELF_type(unsigned char *e_ident, unsigned int e_type);
void ELF_entry(unsigned char *e_ident, unsigned long int e_entry);

void errMessage(int errCode, char *str, int val);
int _strlen(char *s, int j);
#endif
