NAME		=	pipex
NAME2		=	pipex_bonus

BINDIR		=	bin/
INCDIR		=	includes/

PIPEX_DIR	=	src/pipex/
COMMON_DIR	=	src/common/
BONUS_DIR	=	src/bonus/

LIBFT		=	libft/libft.a	
CC			=	gcc
CFLAGS		=	-Wextra -Werror -Wall

PIPEX_SRCS	=	pipex.c \
				exit.c \
				files.c \
				path.c \
				commands.c

BONUS_SRCS	=	bonus.c \
				commands_bonus.c \
				path_bonus.c

PIPEX_OBJS	=	$(addprefix ${BINDIR}, ${PIPEX_SRCS:.c=.o})
BONUS_OBJS	=	$(addprefix ${BINDIR}, ${BONUS_SRCS:.c=.o})

all: $(BINDIR) libft files $(NAME)
	@echo "Pipex compiled"

files:
	@touch infile

${BINDIR}%.o: ${PIPEX_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BINDIR}%.o: ${BONUS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(PIPEX_OBJS)
	@echo "compiling pipex"
	@$(CC) $(CFLAGS) $(LIBFT) $(PIPEX_OBJS) -o $@

$(BINDIR):
	@mkdir -p bin

bonus: $(BINDIR) libft files $(NAME2)
	@echo "Pipex Bonus compiled"

$(NAME2): $(BONUS_OBJS)
	@echo "compiling Pipex Bonus"
	@$(CC) -g $(CFLAGS) $(LIBFT) $(BONUS_OBJS) -o $@

libft:
	@$(MAKE) -C libft

clean:
	@rm -fr $(BINDIR) infile outfile
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -f infile
	@$(MAKE) -C libft fclean

re: clean all

.PHONY: all clean flcean bonus re libft