/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:07:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/30 10:32:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "load_map.h"
# include <stdbool.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_2d_vertex {
	double				x;
	double				y;
}	t_2d_vertex;

typedef struct s_projection {
	int				rows;
	int				columns;
	t_2d_vertex		**vertices;
}	t_projection;

typedef enum e_projection_type {
	ISO = 0,
	ISO_TOP = 1,
	ISO_SIDE = 2,
	ISO_FRONT = 3,
	PERSPECTIVE = 4
}	t_projection_type;

typedef struct s_view {
	int						width;
	int						height;
	double					zoom;
	int						zoom_step;
	int						shift_x;
	int						shift_y;
	float					translation_step;
	int						color;
	float					scale_z;
	bool					currently_dragging_with_left_mouse_button;
	bool					currently_dragging_with_middle_mouse_button;
	bool					is_auto_rotate_on;
	int						last_mouse_x;
	int						last_mouse_y;
	double					rot_angle_x;
	double					rot_angle_y;
	double					rot_angle_z;
	float					rot_step;
	t_projection_type		projection_type;
}			t_view;

typedef struct s_img {
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_app
{
	void				*mlx;
	void				*window;
	t_img				img;
	t_view				view;
	t_model				*model;
	t_model				*model_transformed;
	t_projection		*projection;
}	t_app;

void			validate_argc(int argc);
void			init_app(t_app *app);
void			init_img(t_img *img);
t_model			*create_model_transformed(t_app *app);
void			init_model_transformed(t_model *init_model_transformed, 
					t_model *model);
void			copy_model_vertices(t_model *src, t_model *dst);
t_projection	*create_projection(t_app *app);
t_projection	*alloc_projection(t_app *app);
void			init_projection(t_projection *projection, t_model *model);
void			alloc_projection_vertices(t_projection *projeciton, t_app *app);
void			init_view(t_view *view);
void			destroy_app(t_app *app, int exit_code);

#endif
