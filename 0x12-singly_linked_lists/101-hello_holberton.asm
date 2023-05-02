extern printf

section .data
	alx:	db "Hello, Holberton", 10, 0

section .text
	global main
main:
	; Write the string to stdout
	mov rdi, alx
	xor eax, eax
	call printf


	; Exit program
	mov eax, 0
