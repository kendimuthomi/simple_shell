#include "shell.h"
/**
 *_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @prev_size: byte size of previous block
 * @size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int size)
{
	char *p;

	if (!ptr)
		return (malloc(size));
	if (!size)
		return (free(ptr), NULL);
	if (size == prev_size)
		return (ptr);
	p = malloc(size);
	if (!p)
		return (NULL);
	prev_size = prev_size < size ? prev_size : size;
	while (prev_size--)
		p[prev_size] = ((char *) ptr)[prev_size];
	free(ptr);
	return (p);
}
