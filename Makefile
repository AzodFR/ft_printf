NAME = libftprintf.a
LIBFT = libft.a

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

INC = includes/

SRC = srcs/

HEADERS = ft_printf.h

FILES = ft_printf.c \
		str/print_direct.c str/read_format.c \
		str/prepare_string.c \
		struct/initstruct.c  struct/prepare_flags.c \
		struct/set_flags.c \
		converter/convert.c converter/convert_c.c \
		converter/convert_s.c converter/convert_d_i.c \
		converter/convert_perc.c converter/convert_u.c \
		converter/convert_xx.c converter/convert_p.c

OBJS = $(OBJ:.c=.o)

INCLUDES = $(addprefix $(INC), $(HEADERS))
OBJ = $(addprefix $(SRC), $(FILES))

all: $(NAME)

%.o: %.c $(INCLUDES) libft/includes/libft.h
	@$(CC) -c $< -o $(<:.c=.o) -I${INC} -Ilibft/${INC}
	@printf "$(notdir $<) [\033[32m✔️\033[0m]\n"

$(LIBFT): $(INCLUDES) libft/includes/libft.h
		@make -C libft/

$(NAME): ${OBJS} $(LIBFT)
		@ar rcs libft/$(LIBFT) ${OBJS}
		@cp libft/$(LIBFT) $(NAME)
		@printf "\n\033[1m\033[32mlibftprintf.a \033[1m\033[32mgenerated !\n\n\033[0m"

main: $(NAME)
	@$(CC) main.c -lftprintf -L. -I${INC} -Ilibft/${INC}
	@clear
	@printf "\n\033[1m\033[33ma.out ready, lauching...\n\n\033[0m"
	@printf "\n\033[1m\033[32m#########################\n\033[0m"
	@./a.out | cat -e
	@printf "\033[1m\033[32m#########################\n\033[0m"

test:
	$(CC) test.c -o test.out
	@printf "\n\033[1m\033[33mtest.out ready, lauching...\n\n\033[0m"
	@printf "\n\033[1m\033[32m#########################\n\033[0m"
	@./test.out | cat -e
	@printf "\033[1m\033[32m#########################\n\033[0m"


clean:
	@make clean -C libft/
	@$(RM) $(OBJS)
	@printf "\033[31mDeleting\033[0m >>\033[31m \033[1mall printf .o files\n\033[0m"

fclean: clean
	@make lclean -C libft/
	@$(RM) $(NAME)
	@printf "\033[31mDeleting\033[0m >>\033[31m \033[1mlibftprintf.a\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus libft.a libftprintf.a main
