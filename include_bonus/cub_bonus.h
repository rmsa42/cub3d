/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:14:00 by rumachad          #+#    #+#             */
/*   Updated: 2024/07/08 17:34:59 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "vector2D_bonus.h"
# include "sprite_enum_bonus.h"
# include <stdbool.h>
# include <time.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define E 101
# define Q 113
# define SPACE 32
# define LEFT_CLICK 1
# define LARROW 65361
# define RARROW 65363

# define GREY 0x9c9c9c
# define BLUE 0x0050FF
# define VIOLET 0x8050FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define DARK_BLUE 0x000080
# define GREEN 0x00FF00
# define LIGHT_BLUE 0x00FFFF
# define DAMAGE_RED 0x4Dff0000
# define HEAL_GREEN 0x4D00FF00
# define TRANSPARENT 0xFF00FF

# define HEIGHT 600
# define WIDTH 800
# define FOV 60
# define SPRITE_SIZE 64
# define SPRITE_NBR 62

# define PI 3.14159265359

# define BALL_SPEED 10
# define PL_SPEED 3
# define ROTATION_SPEED 200
# define MOUSE_SPEED 0.1
# define MAX_COINS 4

typedef enum e_state
{
	DIED_STATE,
	WIN_STATE,
	GAME_STATE,
	PORTAL_STATE
}	t_state;

typedef enum e_type
{
	FLOOR,
	DOOR,
	END_DOOR_STATE,
	END_DOOR_STATE2,
	END_DOOR_STATE3,
	DOOR_OPEN,
	ENEMY,
	SPRITE,
	BALL,
	COLLECT,
	WALL,
	HP_COLLECT,
	DAMAGED,
	HEALED
}	t_type;

typedef struct s_objs
{
	struct timespec	last_time;
	double			elapsed_time;
	int				spr_index;
	t_type			type;
	t_v2D			pos;
	int				state;
	int				hp;
}	t_objs;

typedef struct s_player
{
	t_v2D	pos;
	t_v2D	direction;
	t_v2D	plane;
	t_v2D	movement;
	t_list	*ball_node;
	int		hp;
	int		damaged;
	int		healed;
	int		coins;
	double	angle;
	double	pitch;
	bool	mouse;
	bool	shoot;
	bool	shoot_anim;
}	t_player;

typedef struct s_map
{
	int		x;
	int		y;
	int		height;
	int		width;
	int		player_flag;
	char	**game_map;
	char	*config_map[7];
}	t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_sprite
{
	t_image	img;
	int		height;
	int		width;
	int		color;
}	t_sprite;

typedef struct s_ray
{
	t_v2D	dir;
	t_v2D	delta;
	t_v2D	side_d;
	t_v2D	step;
}	t_ray;

typedef struct s_draw
{
	int			tex_x;
	double		line_height;
	double		scale;
	double		tex_pos;
	int			start;
	int			end;
}	t_draw;

typedef struct s_draw_sprite
{
	int	start_y;
	int	end_y;
	int	start_x;
	int	end_x;
	int	screen_x;
	int	height;
	int	tex_x;
	int	tex_y;
}	t_draw_sprite;

typedef struct s_cell
{
	int	x;
	int	y;
}	t_cell;

typedef struct s_mlx
{
	void			*lib;
	void			*window;
	t_sprite		sprite[SPRITE_NBR];
	t_player		player;
	t_map			*map;
	t_image			img;
	t_ray			ray;
	t_draw			draw;
	t_list			*objs_lst;
	t_cell			*marked_cells;
	t_state			game_state;
	int				side;
	int				tile_size;
	double			dist_buffer[WIDTH];
	int				num_marked_cells;
	int				spr_index;
	int				spr_hp_index;
	int				spr_character_index;
	int				spr_coins_index;
	int				nbr_maps;
	int				c_color;
	int				f_color;
	int				iter_map;
	t_map			*head_map;
	struct timespec	door_time;
	struct timespec	last_time;
	struct timespec	current_time;
	struct timespec	prev_time;
	double			elapsed_time;
	double			elapsed_door;
	double			delta;
}	t_mlx;

// Init
t_player	init_player(double x, double y, char tile);
void		init_sprite(t_mlx *mlx, char **conf_map, t_sprite *sprite);
t_objs		*init_obj(t_v2D pos, int spr_index, int hp, t_type type);
t_list		*init_ball(t_list **head, t_player *player);
int			init_mlx_structs(t_mlx *mlx);
void		init_mlx_vars(t_mlx *mlx, int ac);
void		init_map(t_mlx *mlx, int nbr_maps, char **av);

// Raycast
void		ft_crane(t_mlx *mlx);
void		raycaster_hits(t_mlx *mlx, t_map *map, int *hit);
t_draw		calculus(t_ray *ray, t_player *player, double *buffer, int side);
int			select_sprite(t_ray *ray, int side);
void		draw_line(t_mlx *mlx, int x);
void		door_hit(t_mlx *mlx, t_map *map);
void		draw_sprites(t_mlx *mlx);
void		enemy_ray(t_mlx *mlx, t_list *objs_lst);

// Update
void		update_player(t_mlx *mlx, t_player *player, t_map *map);
void		update_ball(t_mlx *mlx, t_player *player);
void		update_sprites(t_mlx *mlx, t_player *player, t_list *objs_lst);
void		update_animations(t_mlx *mlx);
void		ball_animation(t_objs *ball);
void		update_state(t_mlx *mlx);
void		end_game(t_mlx *mlx);

// Game Loop
int			game_loop(t_mlx *mlx);

// Map
int			set_map(t_mlx *mlx);

// Parser (MAP)
int			check_path(char *line);
int			check_rgb(char *line);
int			check_conf(t_mlx *mlx, char **conf_map, t_sprite *sprite);
int			check_element(t_mlx *mlx, t_sprite *sprite, char *conf_map);
int			color(int nbr);
int			shift_color(int *rgb);
int			advance_space(char *line);

int			map_parser(char *file_name, t_map *map);
char		**create_full_map(int fd, char *map_name, int nbr_lines);
int			create_config_map(t_map *map, char **full_map);
int			create_content_map(t_map *map, char **full_map, int after, int len);
char		*srch_set(char *line, char *set);
int			calc_map_lines(int fd, char *map_name);
int			call_flood_fill(t_mlx *mlx, t_map *map);

// Image
void		pixel_put(t_image *img, int pixelX, int pixelY, int color);
int			pixel_get(t_image *img, int pixel_x, int pixel_y);
t_sprite	xpm_to_image(t_mlx *mlx, char *texture);
t_image		image_buffer(t_mlx *mlx);

// Events
int			handle_key_press(int keycode, t_mlx *mlx);
int			handle_key_release(int keycode, t_player *player);
int			handle_mouse(int x, int y, t_mlx *mlx);
int			handle_mouse_press(int button, int x, int y, t_mlx *mlx);
t_v2D		rotate(t_v2D vector, double degree);

// Interactions Player
t_type		get_next_tile(char **game_map, t_player *player);
void		interact_door(char **game_map, t_player *player);
bool		check_objs_collision(t_mlx *mlx, t_list *objs_lst, t_v2D check);
bool		is_wall_collision(t_map *map, float x, float y);

// Interactions Ball
t_list		*ball_hit_obj(t_list *objs_lst, t_objs *ball);
bool		ball_hit_wall(t_map *map, t_objs *ball);
void		clean_hit(t_list **objs_list, t_player *player, t_list *hit);

// Draw Hud
void		draw_hud(t_image *img, t_sprite *sprite, t_v2D sprite_pos);
void		draw_char(t_image *img, t_sprite *sprites, int spr_index);
void		draw_coins(t_image *img, t_sprite *sprites, int spr_index);
void		draw_hearts(t_image *img, t_sprite *sprites, int spr_index);
void		draw_status(t_mlx *mlx);
int			calc_char_anim(t_mlx *mlx);
void		draw_damage_heal(t_image *img, int status);
void		draw_screen(t_image *img, t_sprite *sprite);
void		draw_minimap(t_mlx *mlx);
void		put_tiles(t_mlx *mlx, int x, int y, int tile_size);
int			get_color(int x, int y, t_map *map);

// Sort Sprite
t_list		*sort_sprites(t_player *player, t_list *objs_lst);

// Time
void		update_time(struct timespec *time);
double		time_passed(struct timespec *last, struct timespec *current);

// Free Mem
void		free_obj_lst(t_list *objs);
void		free_config(void *lib, t_sprite *sprite);
void		free_sprites(void *lib, t_sprite *sprite);
void		free_map(int nbr_maps, t_map *map);
void		elim_obj(t_list **head, t_list *elim_obj);
void		print_error(char *str, int status, t_mlx *mlx);
int			close_game(t_mlx *mlx, int status);

// Destructors
void		obj_destructor(t_list *node);
void		sprite_destructor(void *lib, t_sprite *sprite);
void		map_destructor(t_map *map);
void		mlx_destructor(void *lib, void *window);
void		free_config(void *lib, t_sprite *sprite);

#endif