#include <stdio.h>
#include <stdlib.h>

// Ownership & Lifetime Example 1
// 	For msg_1: non-escaping ownership / function-contained lifetime management
// 	For msg_2: Escaping lifetime via return + ownership transfer

static size_t	ft_strlcpy(char *dst, const char *src, size_t size);
static char		*ft_strdup(const char *src);

int print_heap_allocated_messages(void)
{
	char *msg_1;
	char *msg_2;

	msg_1 = malloc(sizeof(char) * 27); 	// msg_1 lifetime begins
	if (!msg_1)
		return (1);

	ft_strlcpy(msg_1, "msg_1: function contained.", 27);

	msg_2 = ft_strdup("msg_2: ownership transferred.");
	if (!msg_2)
	{
		free(msg_1);
		return (1);
	}

    printf("%s\n%s\n", msg_1, msg_2);

    free(msg_1);                    // lifetime ends
	free(msg_2);					// lifetime ends
	return (0);
}

// borrows str, does not free
static size_t	ft_strlen(const char *str) 	
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

// borrows s1 (read-only); allocates new string; returns owned pointer
static char	*ft_strdup(const char *src) 		
{
	size_t	size;
	char	*src_dup;

	size = (ft_strlen(src) + 1) * sizeof(char);
	src_dup = (char *)malloc(size);			// msg_2 lifetime begins
	if (src_dup == NULL)
		return (NULL);
	ft_strlcpy(src_dup, src, size);
	return (src_dup);						// transfers ownership
}

// reads src (borrowed); writes dst; no alloc/free
static size_t	ft_strlcpy(char *dst, const char *src, const size_t size) 
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	print_heap_allocated_messages();
	return (0);
}