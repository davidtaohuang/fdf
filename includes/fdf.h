/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 16:46:35 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/02 22:36:21 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"

typedef struct	s_point
{
	double			p[4];
	unsigned int	c;
}				t_point;

typedef struct	s_matrix
{
	int		l;
	int		pl;
	int		*ppl;
	int		**mat;
}				t_matrix;

typedef struct	s_wire
{
	int				*angle;
	t_point			**po;
	t_point			**p;
	int				l;
	int				pl;
	int				xo;
	int				yo;
	double			zoom;
}				t_wire;

typedef struct	s_keydata
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*imgd;
	int				bbp;
	int				endian;
	int				oxmax;
	int				oymax;
	int				xmax;
	int				ymax;
	int				line;
	int				mdown;
	int				mbutton;
	int				xp;
	int				yp;
	t_wire			*f;
}				t_keydata;

# define YMAX 1000
# define OFFSET 50
# define XMAX round(YMAX * (f->pl / (double)f->l))
# define PXMAX round(YMAX * (d.f->pl / (double)d.f->l))
# define DYMAX YMAX
# define DXMAX round(DYMAX * (d->f->pl / (double)d->f->l))
# define PXOFFSET round((PWINX - d.xmax) / 2)
# define XOFFSET round((WINX - d.xmax) / 2)
# define YOFFSET round((WINY - d.ymax) / 2)
# define DXO DXOFFSET + d->f->xo
# define DYO DYOFFSET + d->f->yo
# define DXOFFSET round((WINDX - d->xmax) / 2)
# define DYOFFSET round((WINDY - d->ymax) / 2)
# define PWINX PXMAX + (2 * OFFSET)
# define WINX XMAX + (2 * OFFSET)
# define WINY YMAX + (2 * OFFSET)
# define WINDX DXMAX + (2 * OFFSET)
# define WINDY DYMAX + (2 * OFFSET)
# define EA e[0]
# define EB e[1]
# define D2RAD(x) (x * M_PI / 180)
# define PTS m->pl * m->l + 1
# define FPTS f->pl * f->l + 1
# define CR 0x0000FFFF
# define CO 0x00FF0000

t_point			**f_darray(t_point **array);
t_matrix		*ft_freematrix(t_matrix *array, int lines);
int				ft_freewire(t_wire *frame);
void			ft_freefm(t_wire *f, t_matrix *m);

void			ft_edgepoints(int a, int b, t_keydata d);
void			ft_makehedges(t_keydata d, int pl, int l);
void			ft_makevedges(t_keydata d, int pl, int l);

double			p2max(t_point **m, int a);
double			p2min(t_point **m, int a);

void			ft_transform(t_point *p, double *t);
double			*ft_transm(double *p, double *t);

void			ft_3drot(int *angles, t_point **pts);
void			ft_translate(t_point **points);
void			ft_scale(t_wire *f, t_point **pts, t_point **o);

void			ft_iso3d(t_wire *f, t_point **pts);
void			ft_parallel3d(t_wire *f, t_point **pts);
void			ft_perspective3d(t_wire *f, t_point **pts);

t_matrix		*ft_getmap(char *str);
t_matrix		*ft_matrix(char *str, char c, int lines);
t_wire			*ft_framesetup(t_matrix *m);
t_point			**ft_3dpoints(t_matrix *m, int i, int pi);
t_point			**ft_cpypts(t_wire *f, t_point **o);

int				ft_drag(int x, int y, t_keydata *d);
int				ft_mousedown(int button, int x, int y, t_keydata *d);
int				ft_mouseup(int button, int x, int y, t_keydata *d);
int				ft_kdown(int key, t_keydata *d);

int				ft_mlxsetup(t_wire *f, int endian, int bbp, int line);
void			ft_mlxredraw(t_keydata *d);

#endif
