# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plima <plima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 15:25:57 by pecavalc          #+#    #+#              #
#    Updated: 2025/09/26 12:22:03 by plima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, alloc_projection_vertices.c \
								 alloc_projection.c \
								 copy_model_vertices.c \
								 create_projection.c \
								 create_model_transformed.c \
								 destroy_app.c \
								 fdf.c \
								 init_app.c \
								 init_img.c \
								 init_projection.c \
								 init_model_transformed.c \
								 init_view.c \
								 validate_argc.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

HEADER_DIR = include
HEADER = $(HEADER_DIR)/fdf.h


# load_map module
LOAD_MAP_SRCS_DIR = srcs/load_map
LOAD_MAP_SRCS = $(addprefix $(LOAD_MAP_SRCS_DIR)/, alloc_model_vertices.c \
												   alloc_model.c \
												   create_model.c \
												   init_model.c \
												   load_map.c \
												   parse_map_dimensions.c \
												   parse_map.c \
												   try_ft_split.c \
												   try_get_next_line.c \
												   try_open.c)

LOAD_MAP_OBJS_DIR = objs/load_map
LOAD_MAP_OBJS = $(patsubst $(LOAD_MAP_SRCS_DIR)/%.c, \
				$(LOAD_MAP_OBJS_DIR)/%.o, $(LOAD_MAP_SRCS))

PUB_LOAD_MAP_HEADER_DIR = include
PRIV_LOAD_MAP_HEADER_DIR = $(LOAD_MAP_SRCS_DIR)
LOAD_MAP_HEADERS = $(PUB_LOAD_MAP_HEADER_DIR)/fdf_map.h \
					$(PRIV_LOAD_MAP_HEADER_DIR)/fdf_map_internal.h


# mlx_handling module
MLX_HAN_SRCS_DIR = srcs/mlx_handling
MLX_HAN_SRCS = $(addprefix $(MLX_HAN_SRCS_DIR)/, handle_all_mlx_inits.c \
												 handle_auto_rotate_model.c \
												 handle_close.c \
												 handle_on_button_press.c \
												 handle_on_button_release.c \
												 handle_on_key_press.c \
												 handle_on_mouse_move.c \
												 init_mlx.c \
												 init_mlx_img.c \
												 init_mlx_window.c \
												 register_mlx_hooks.c)
MLX_HAN_OBJS_DIR = objs/mlx_handling
MLX_HAN_OBJS = $(patsubst $(MLX_HAN_SRCS_DIR)/%.c, \
			   $(MLX_HAN_OBJS_DIR)/%.o, $(MLX_HAN_SRCS))
			   
PUB_MLX_HAN_HEADER_DIR = include
PRIV_MLX_HAN_HEADER_DIR = $(MLX_HAN_SRCS_DIR)
MLX_HAN_HEADERS = $(PUB_MLX_HAN_HEADER_DIR)/mlx_handling.h \
				  $(PRIV_MLX_HAN_HEADER_DIR)/mlx_handling_internal.h


# render_img module
RENDER_FDF_SRCS_DIR = srcs/render_img
RENDER_FDF_SRCS = $(addprefix $(RENDER_FDF_SRCS_DIR)/, \
					apply_perspective_projection.c \
					apply_projection.c \
					centralize_view_once.c \
					centralize_view.c \
					erase_img.c \
					move_origin_to_geometric_center.c \
					put_pixel.c \
					render_all_edges.c \
					render_img.c \
					rotate_model.c \
					translate_projection.c \
					zoom_projection.c)

RENDER_FDF_OBJS_DIR = objs/render_img
RENDER_FDF_OBJS = $(patsubst $(RENDER_FDF_SRCS_DIR)/%.c, \
					$(RENDER_FDF_OBJS_DIR)/%.o, $(RENDER_FDF_SRCS))
					
PUB_RENDER_FDF_HEADER_DIR = include
PRIV_RENDER_FDF_HEADER_DIR = $(RENDER_FDF_SRCS_DIR)
RENDER_FDF_HEADERS = $(PUB_RENDER_FDF_HEADER_DIR)/render_img.h \
						$(PRIV_RENDER_FDF_HEADER_DIR)/render_img_internal.h


# Directories of all objects above
OBJS_DIRS = $(OBJS_DIR) $(LOAD_MAP_OBJS_DIR) $(RENDER_FDF_OBJS_DIR) \
			$(MLX_HAN_OBJS_DIR)


# Libft
LIBFT_DIR = libs/Libft-2.1.1
LIBFT_HEADER_DIR = $(LIBFT_DIR)/include
LIBFT = $(LIBFT_DIR)/libft.a

# MiniLibX
LIBMLX_DIR = libs/minilibx-linux
LIBMLX_HEADER_DIR = $(LIBMLX_DIR)
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR) -I$(PUB_LOAD_MAP_HEADER_DIR) \
							   -I$(PRIV_LOAD_MAP_HEADER_DIR) \
							   -I$(PUB_MLX_HAN_HEADER_DIR) \
							   -I$(PRIV_MLX_HAN_HEADER_DIR) \
							   -I$(PUB_RENDER_FDF_HEADER_DIR) \
							   -I$(PRIV_RENDER_FDF_HEADER_DIR) \
							   -I$(LIBFT_HEADER_DIR) -I$(LIBMLX_HEADER_DIR)

all: $(OBJS_DIRS) $(NAME)

$(OBJS_DIRS):
	mkdir -p $@

$(NAME): $(OBJS) $(LOAD_MAP_OBJS) $(MLX_HAN_OBJS) $(RENDER_FDF_OBJS) $(LIBFT) $(LIBMLX)
	cc $(CFLAGS) $(OBJS) $(LOAD_MAP_OBJS) $(MLX_HAN_OBJS) $(RENDER_FDF_OBJS) \
	   $(LIBFT) $(LIBMLX) -lX11 -lXext -lm -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

$(LOAD_MAP_OBJS_DIR)/%.o: $(LOAD_MAP_SRCS_DIR)/%.c $(LOAD_MAP_HEADERS)
	cc $(CFLAGS) -c $< -o $@

$(MLX_HAN_OBJS_DIR)/%.o: $(LMLX_HAN_SRCS_DIR)/%.c $(MLX_HAN_HEADERS)
	cc $(CFLAGS) -c $< -o $@

$(RENDER_FDF_OBJS_DIR)/%.o: $(RENDER_FDF_SRCS_DIR)/%.c $(RENDER_FDF_HEADERS)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

print:
	@echo $(RENDER_FDF_OBJS)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	rm -f $(LOAD_MAP_OBJS)
	rm -rf $(LOAD_MAP_OBJS_DIR)
	rm -f $(RENDER_FDF_OBJS)
	rm -rf $(RENDER_FDF_OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all re clean fclean 
