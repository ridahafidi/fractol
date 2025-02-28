NAME = fractol
BNAME = fractol_bns
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = events_mandelbrot.c \
      mandelbrotset.c \
      str_utils.c \
      fractol.c \
      julia_set.c \
      julia_events.c \
      coloring.c \
      event_helper.c \
      error.c

BSRC = fractol_bonus/events_mandelbrot_bonus.c \
       fractol_bonus/mandelbrotset_bonus.c \
       fractol_bonus/str_utils_bonus.c \
       fractol_bonus/fractol_bonus.c \
       fractol_bonus/julia_set_bonus.c \
       fractol_bonus/julia_events_bonus.c \
       fractol_bonus/coloring_bonus.c \
       fractol_bonus/event_helper_bonus.c \
       fractol_bonus/error_bonus.c \
       fractol_bonus/my_set_bonus.c \
       fractol_bonus/my_set_events_bonus.c

OBJS = $(SRC:.c=.o)
BOBJS = $(BSRC:.c=.o)

MINILIBX = -L./usr/local/lib -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MINILIBX)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS) $(MINILIBX)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus
