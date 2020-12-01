NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

INC = includes/

HEADERS = ft_printf.h

FILES = $(wildcard libtft/srcs/*.c) \
		srcs/ft_printf.c

OBJS = $(FILES:.c=.o)

INCLUDES = $(addprefix $(INC), $(HEADERS))

%.o: %.c $(INCLUDES) libft/includes/libft.h
	@$(CC) -c $< -o $(<:.c=.o) -I${INC} -Ilibft/${INC}
	@printf "$(notdir $<) [\033[32m✔️\033[0m]\n"

$(NAME): ${OBJS}
		@ar rcs libftprintf.a ${OBJS}
		@printf "\n\033[1m\033[4m\033[32mlibftprintf.a \033[1m\033[32mgenerated !\n\n\033[0m\033[24m"

all: $(NAME)

main: $(NAME)
	@$(CC) -c main.c -I${INC} -Ilibft/${INC} -L -lftprintf

clean:
	@make clean -C libft/
	@$(RM) $(OBJS)
	@printf "\033[31mDeleting\033[0m >>\033[31m \033[1mall printf .o files\n\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[31mDeleting\033[0m >>\033[31m \033[1mlibftprintf.a\n\033[0m"

re: fclean all
