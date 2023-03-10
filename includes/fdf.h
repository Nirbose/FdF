/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:10:31 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/29 16:05:37 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define NAME "fdf"
# define HEIGHT 1080
# define WIDTH 1920
# define DEFAULT_ZOOM 30.0

/*	STRUCT	*/
typedef struct s_point
{
	float			x;
	float			y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_map
{
	int		total_x;
	int		total_y;
	double	zoom;
	t_point	**points;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_map	*map;
}	t_data;

/*	PARSE_FILE	*/
t_map	*parse_file(char *file);

/*	PARSE_FILE_UTILS	*/
int		count_file_lines(char *file);

/*	ERROR	*/
void	error(char const *msg);

/*	CLEAN	*/
void	tab_clean(char **tab);
void	clean_points(t_point **points, int items);

/*	UTILS	*/
int		count_split_items(char **items);
int		create_trgb(unsigned char t, unsigned char r, \
		unsigned char g, unsigned char b);
void	find_zoom(t_map *map);

/*	EVENTS	*/
int		esc(int keycode, t_data *data);
int		quit(t_data *data);

/*	RENDER	*/
void	render(t_data *data);
t_point	*get_point(t_point point);
void	resize_points(t_map *map);

/*	DRAW	*/
void	dda(t_data *data, t_point point0, t_point point1);

#endif
