
NAME = fractol

SRC = \
	$(addprefix src/, \
\
	main.c \
	add_initial_state.c \
	are_arguments_valid.c \
	open_windows.c \
	reset_map.c \
	move_map.c \
	move_fract.c \
	draw_all_fractals.c \
	redraw_fract.c \
	fract_1.c \
	fract_2.c \
	fract_3.c \
	fract_4.c \
	fract_5.c \
	fract_6.c \
	set_hooks.c \
	mouse_press_hook.c \
	turn_iter_to_col.c \
	complex_sum.c \
	complex_multiply.c \
	complex_divide.c \
	motion_hook.c \
	key_press_hook.c \
	zoom_fract.c \
	zoom_map.c \
	correct_map.c \
	loop_hook.c \
	key_release_hook.c \
	) \
\
	$(addprefix libft/, \
\
	ft_memalloc.c \
	ft_bzero.c \
	ft_memset.c \
	ft_putnbr_fd.c \
	ft_putchar_fd.c \
	ft_strlen.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcmp.c \
	) \
\

OBJ =  \
	$(addprefix obj/, \
\
	main.o \
	add_initial_state.o \
	are_arguments_valid.o \
	open_windows.o \
	redraw_fract.o \
	fract_1.o \
	fract_2.o \
	fract_3.o \
	fract_4.o \
	fract_5.o \
	fract_6.o \
	complex_divide.o \
	set_hooks.o \
	loop_hook.o \
	correct_map.o \
	draw_all_fractals.o \
	turn_iter_to_col.o \
	mouse_press_hook.o \
	complex_sum.o \
	complex_multiply.o \
	motion_hook.o \
	key_press_hook.o \
	move_map.o \
	reset_map.o \
	key_release_hook.o \
	zoom_fract.o \
	move_fract.o \
	zoom_map.o \
	ft_memalloc.o \
	ft_bzero.o \
	ft_memset.o \
	ft_strcmp.o \
	ft_putstr.o \
	ft_strlen.o \
	ft_putstr_fd.o \
	ft_putnbr_fd.o \
	ft_putchar_fd.o \
	ft_putnbr.o \
	) \
\

FLAGS = -Wall -Wextra -Werror

INC = -I ./minilibx -I ./includes -I ./libft/includes

PATH = minilibx -lmlx -framework OpenGL -framework AppKit

MLBX = minilibx/libmlx.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) $(INC)
	/bin/mv *.o obj
	gcc $(FLAGS) -L $(PATH) $(OBJ) $(MLBX) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
