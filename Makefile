NAME = libftprintf.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
INC = -Iincludes
RM = rm -rf

SRC = ./srcs/

FILES = datacs.c datadiu.c datapx.c libfts.c mainfuncs.c pointerzero.c print_utils.c searchandprints.c numsizes.c

OBJ = $(addprefix $(SRC), $(FILES))
OBJS = $(OBJ:.c=.o)


.c.o : $(OBJ)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^

$(NAME) : $(OBJS)
	$(AR) $@ $^

bonus : all

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re