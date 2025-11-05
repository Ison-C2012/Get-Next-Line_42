
NAME:= gnl

SRCDIR:= srcs/
OBJDIR:= objs/

SRCS:= srcs/get_next_line.c srcs/get_next_line_utils.c
OBJS:= ${SRCS:%.c=%.o}

INCDIR:= srcs/

CC:= gcc
CFLAGS:= -g3 -Wall -Werror -Wextra
MFLAGS:= -fsanitize=address

DEFINE:= -D
BUFSIZE:= BUFFER_SIZE=1

RM:= rm -rf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(DEFINE) $(BUFSIZE) $? -o $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(DEFINE) $(BUFSIZE) -c $< -o $@ 

all: $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
