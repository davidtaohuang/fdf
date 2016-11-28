# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 16:11:06 by dhuang            #+#    #+#              #
#    Updated: 2016/11/02 21:14:29 by dhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re testing

vpath %.h includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

GFLAGS = -framework OpenGL -framework AppKit

INCLUDES = -I includes/

SRCFILES = main.c ft_cleanup.c ft_framesetup.c ft_getmap.c ft_iso3d.c \
		ft_tandscale.c ft_3dpoints.c ft_matrix.c\
		ft_mlxstuff.c ft_edgepoints.c ft_perspective3d.c ft_3drot.c \
		ft_mlxredraw.c ft_pmath.c ft_khooks.c ft_mhooks.c

SRCDIR := srcs

SRC:= $(addprefix $(SRCDIR)/, SRCFILES))

LIB = libft/libft.a

MINILIB = minilibx_macos/libmlx.a

OBJDIR := obj

OBJS := $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(SRCFILES)))

NAME = fdf

all: $(NAME)

$(LIB):
		make -C libft/

$(MINILIB):
		@echo "Creating $@..."
		make -C minilibx_macos/
		@echo "Done creating $@!"

$(OBJS): fdf.h $(SRCS) | $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Done creating $@..."

$(OBJDIR):
		@echo "Creating subdirectory for object files..."
		@mkdir $(OBJDIR)

$(NAME): fdf.h $(OBJS) $(LIB) $(MINILIB)
		@echo "Creating $(NAME)..."
		@$(CC) $(CFLAGS) $(GFLAGS) $(OBJS) -o $@ -L minilibx_macos/ -lmlx -L libft/ -lft
		@echo "All done!"

testing: 
		$(CC) $(CFLAGS) $(GFLAGS) $(LIB) $(MINILIB) $(SRCS) $(INCLUDES)

clean:
		@echo "Deleting fdf object files and subdirectory..."
		@rm -f $(OBJS)
		@rm -rf $(OBJDIR)
		make clean -C libft/

fclean: clean
		@echo "Deleting $(NAME)..."
		@rm -f $(NAME)
		make fclean -C libft/
		make clean -C minilibx_macos/

re: fclean all
