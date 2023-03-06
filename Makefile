NAME	=	pipex

BINDIR	=	bin/

all: $(BINDIR) libft $(NAME)

$(BINDIR):
	@mkdir -p bin

libft:
	@$(MAKE) -C libft

clean:
	@rm -fr $(BINDIR)
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: clean all
	@$(MAKE) -C libft re

.PHONY: all clean flcean re libft