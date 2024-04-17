NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror
SRC = ft_check_4_directions.c 				ft_map_check.c 		ft_position_n_surrounded.c 		ft_maps_parsing.c
SRC_MAN = ma_create_n_generate.c 			so_long.c 			ma_detect_close.c 				ma_move_4_direction.c 		ma_other.c
SRC_BONUS = solong_bonus/create_n_generate_bonus.c 		solong_bonus/detect_close_bonus.c\
			solong_bonus/move_4_direction_bonus.c 		solong_bonus/move_4_direction_en_bonus.c\
			solong_bonus/en_funcs_bonus.c				solong_bonus/img_en_po_ptrs.c\
			solong_bonus/other_bonus.c					solong_bonus/so_long_bonus.c
OBJS = $(SRC:.c=.o)
OBJS_MAN = $(SRC_MAN:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJS) $(OBJS_MAN) 
	make -C libft
	make -C mlx
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_MAN) libft/libft.a -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

all: $(NAME)

clean:	lib_clean mlx_clean
	rm -f $(OBJS) $(OBJS_MAN) $(OBJS_BONUS)
lib_clean:
	make clean -C libft
mlx_clean:
	make clean -C mlx


fclean: lib_fclean mlx_clean
	rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_MAN) $(OBJS_BONUS)
lib_fclean:
	make fclean -C libft


re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS) 
	make -C libft
	make -C mlx
	cc $(CFLAGS) -o $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) libft/libft.a -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

%.o: .%c
	$(CC) $(CFLAGS) -Imlx -c $< -o <@