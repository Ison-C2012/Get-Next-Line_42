
#include "get_next_line.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *name = "read_error.txt";
	int fd = open(name, O_RDONLY);
	/* 1 */ printf("1:%d\n", strcmp(get_next_line(fd), "aaaaaaaaaa\n"));
	/* 2 */ printf("2:%d\n", strcmp(get_next_line(fd), "bbbbbbbbbb\n"));
	// set the next read call to return -1
	if (BUFFER_SIZE > 100) {
		char *temp;
		do {
			temp = get_next_line(fd);
			free(temp);
		} while (temp != (char *)NULL);
	}
	/* 3 */ printf("3:%ld\n", get_next_line(42) - (char *)NULL);
	close(fd);
	fd = open(name, O_RDONLY);
	/* 4 */ printf("4:%d\n", strcmp(get_next_line(fd), "aaaaaaaaaa\n"));
	/* 5 */ printf("5:%d\n", strcmp(get_next_line(fd), "bbbbbbbbbb\n"));
	/* 6 */ printf("6:%d\n", strcmp(get_next_line(fd), "cccccccccc\n"));
	/* 7 */ printf("7:%d\n", strcmp(get_next_line(fd), "dddddddddd\n"));
	/* 8 */ printf("8:%ld\n", get_next_line(fd) - (char *)NULL);
	return 0;
}

