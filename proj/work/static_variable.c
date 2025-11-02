/*

Static variable will be initialized only once.
You need to initialize it just one time as though the initialization is not simple.

 */


char	*ft_concatenate(char *s)
{
	static char	*d = "";
/*	static char	*d;

	d = malloc(1);*/
	d = ft_strjoin(d, s);
	if (d)
		return (d);
	return (NULL);
}

int	main(void)
{
	printf("%s\n", ft_concatenate("Hi,"));
	printf("%s\n", ft_concatenate(" I'm"));
	printf("%s\n", ft_concatenate(" Keito"));
	printf("%s\n", ft_concatenate("."));
}

