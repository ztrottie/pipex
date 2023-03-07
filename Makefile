NAME		=	pipex

BINDIR		=	bin/
INCDIR		=	includes/

PIPEX_DIR	=	src/pipex/
COMMON_DIR	=	src/common/
BONUS_DIR	=	src/bonus

LIBFT		=	libft/libft.a	
CC			=	gcc
CFLAGS		=	-Wextra -Werror -Wall

PIPEX_SRCS	=	pipex.c

PIPEX_OBJS	=	$(addprefix ${BINDIR}, ${PIPEX_SRCS:.c=.o})


all: $(BINDIR) libft files $(NAME)

files:
	@touch infile
	@touch outfile

${BINDIR}%.o: ${PIPEX_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

$(NAME): $(PIPEX_OBJS) $(COMMON_OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(PIPEX_OBJS) $(COMMON_OBJS) -o $@

$(BINDIR):
	@mkdir -p bin

libft:
	@$(MAKE) -C libft

clean:
	@rm -fr $(BINDIR) infile outfile
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: clean all
	@$(MAKE) -C libft re

.PHONY: all clean flcean re libft