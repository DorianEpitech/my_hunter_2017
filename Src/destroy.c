/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** destroy.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "duck_hunt.h"

void destroy_starter(sfMusic *music, sfFont *font, sfText *text)
{
	sfMusic_destroy(music);
	sfFont_destroy(font);
	sfText_destroy(text);
}

void restart(context_t *context, system_t *system)
{
	sfIntRect tmp = {0, 0, 60, 60};

	context->zoom = 1;
	context->check_status = 0;
	context->seconds_pause = 0;
	context->seconds = 0;
	context->time = sfClock_restart(context->clock);
	system->pos_x = 0;
	system->pos_y = 0;
	system->offset = 0;
	system->seconds = 0;
	system->time = sfClock_restart(system->clock);
	system->menu_status = 1;
	system->rect = tmp;
	system->alive = 20;
}

void destroy_system(system_t *system)
{
	sfTexture_destroy(system->t_die);
	sfSprite_destroy(system->s_die);
	sfTexture_destroy(system->t_menu);
	sfSprite_destroy(system->s_menu);
	sfMusic_destroy(system->music);
	sfClock_destroy(system->clock);
	sfText_destroy(system->result);
	sfText_destroy(system->command);
	sfText_destroy(system->score);
	sfFont_destroy(system->font);
	free(system);
}

void destroy_context(context_t *context)
{
	sfTexture_destroy(context->t_stage);
	sfTexture_destroy(context->t_plane);
	sfTexture_destroy(context->t_sniper);
	sfTexture_destroy(context->t_unprecise);
	sfTexture_destroy(context->t_precise);
	sfSprite_destroy(context->s_sniper);
	sfSprite_destroy(context->s_plane);
	sfSprite_destroy(context->s_stage);
	sfSprite_destroy(context->s_unprecise);
	sfSprite_destroy(context->s_precise);
	sfMusic_destroy(context->tir);
	sfMusic_destroy(context->music);
	sfView_destroy(context->scope);
	sfClock_destroy(context->clock);
	sfRenderWindow_destroy(context->window);
	free(context);
}

void destroy_bird(bird_t *bird, int check)
{
	if (check == 1) {
		sfSprite_destroy(bird->s_duck);
		sfTexture_destroy(bird->t_duck);
		sfClock_destroy(bird->clock);
	} else {
		while (bird != NULL) {
			sfSprite_destroy(bird->s_duck);
			sfTexture_destroy(bird->t_duck);
			sfClock_destroy(bird->clock);
			bird = bird->next;
		}
	}
}
