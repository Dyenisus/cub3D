/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:59:41 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/08 20:57:49 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "../../include/cub3d.h"

  static void   init_img(t_img *img)
  {
        img->ptr = NULL;
        img->addr = NULL;
        img->bpp = 0;
        img->line_len = 0;
        img->endian = 0;
        img->width = 0;
        img->height = 0;
  }

  static void   init_game_struct(t_game *game, t_map *map)
  {
        game->mlx = NULL;
        game->win = NULL;
        game->map = map;
        init_img(&game->frame);
        init_img(&game->textures.north);
        init_img(&game->textures.south);
        init_img(&game->textures.west);
        init_img(&game->textures.east);
        game->camera.x = 0.0;
        game->camera.y = 0.0;
        game->camera.dir_x = 0.0;
        game->camera.dir_y = 0.0;
        game->camera.plane_x = 0.0;
        game->camera.plane_y = 0.0;
  }

  static void   free_map(t_map *map)
  {
        if (!map)
                return ;
        free_2d_array(map->grid);
        free(map->north.path);
        free(map->south.path);
        free(map->west.path);
        free(map->east.path);
        free(map);
  }

  static void   destroy_img(void *mlx, t_img *img)
  {
        if (img->ptr)
                mlx_destroy_image(mlx, img->ptr);
  }

  static void   cleanup_game(t_game *game)
  {
        if (game->mlx)
        {
                destroy_img(game->mlx, &game->frame);
                destroy_img(game->mlx, &game->textures.north);
                destroy_img(game->mlx, &game->textures.south);
                destroy_img(game->mlx, &game->textures.west);
                destroy_img(game->mlx, &game->textures.east);
                if (game->win)
                        mlx_destroy_window(game->mlx, game->win);
                mlx_destroy_display(game->mlx);
                free(game->mlx);
        }
        free_map(game->map);
  }

  static void   init_camera(t_game *game)
  {
        game->camera.x = game->map->player.x;
        game->camera.y = game->map->player.y;
        if (game->map->player.dir == 'N')
        {
                game->camera.dir_x = 0.0;
                game->camera.dir_y = -1.0;
                game->camera.plane_x = 0.66;
                game->camera.plane_y = 0.0;
        }
        else if (game->map->player.dir == 'S')
        {
                game->camera.dir_x = 0.0;
                game->camera.dir_y = 1.0;
                game->camera.plane_x = -0.66;
                game->camera.plane_y = 0.0;
        }
        else if (game->map->player.dir == 'W')
        {
                game->camera.dir_x = -1.0;
                game->camera.dir_y = 0.0;
                game->camera.plane_x = 0.0;
                game->camera.plane_y = -0.66;
        }
        else
        {
                game->camera.dir_x = 1.0;
                game->camera.dir_y = 0.0;
                game->camera.plane_x = 0.0;
                game->camera.plane_y = 0.66;
        }
  }

  static int    load_texture(t_game *game, t_img *img, char *path)
  {
        img->ptr = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
    if (!img->ptr)
            return (print_error("Failed to load texture"));
    img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len,
                    &img->endian);
    if (!img->addr)
            return (print_error("Failed to get texture data"));
    return (EXIT_SUCCESS);
}

static int    init_textures(t_game *game)
{
    if (load_texture(game, &game->textures.north, game->map->north.path)
            == EXIT_FAILURE)
            return (EXIT_FAILURE);
    if (load_texture(game, &game->textures.south, game->map->south.path)
            == EXIT_FAILURE)
            return (EXIT_FAILURE);
    if (load_texture(game, &game->textures.west, game->map->west.path)
            == EXIT_FAILURE)
            return (EXIT_FAILURE);
    if (load_texture(game, &game->textures.east, game->map->east.path)
            == EXIT_FAILURE)
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int    init_frame(t_game *game)
{
    game->frame.ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!game->frame.ptr)
            return (print_error("Failed to create frame image"));
    game->frame.width = WIN_WIDTH;
    game->frame.height = WIN_HEIGHT;
    game->frame.addr = mlx_get_data_addr(game->frame.ptr, &game->frame.bpp,
                    &game->frame.line_len, &game->frame.endian);
    if (!game->frame.addr)
            return (print_error("Failed to get frame data"));
    return (EXIT_SUCCESS);
}

int   start_game(t_map *map)
{
    t_game  game;

    if (!map)
            return (EXIT_FAILURE);
    init_game_struct(&game, map);
    game.mlx = mlx_init();
    if (!game.mlx)
    {
            cleanup_game(&game);
            return (print_error("Failed to initialize mlx"));
    }
    game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
    if (!game.win)
    {
            cleanup_game(&game);
            return (print_error("Failed to create window"));
    }
    if (init_frame(&game) == EXIT_FAILURE)
    {
            cleanup_game(&game);
            return (EXIT_FAILURE);
    }
    if (init_textures(&game) == EXIT_FAILURE)
    {
            cleanup_game(&game);
            return (EXIT_FAILURE);
    }
    init_camera(&game);
    mlx_loop(game.mlx);
    cleanup_game(&game);
    return (EXIT_SUCCESS);
}