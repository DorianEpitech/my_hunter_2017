/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** display.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include "duck_hunt.h"

void display_starter(context_t *context, sfText *text, sfFont *font,
	sfMusic *music)
{
	sfRenderWindow_clear(context->window, sfBlack);
	play_starter(music);
	sfText_setPosition(text, (sfVector2f){80, 0});
	sfText_setColor(text, sfBlack);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 750);
	sfRenderWindow_setView(context->window, context->no_scope);
	sfRenderWindow_drawSprite(context->window, context->s_stage, NULL);
	sfRenderWindow_drawSprite(context->window, context->s_sniper, NULL);
	sfRenderWindow_drawSprite(context->window, context->s_plane, NULL);
	sfRenderWindow_drawText(context->window, text, NULL);
	sfRenderWindow_display(context->window);
}

void display_bird(bird_t *bird, context_t *context)
{
	bird_t *tmp = bird;

	while (tmp != NULL && tmp->starter < context->seconds) {
		sfSprite_setPosition(tmp->s_duck,
			(sfVector2f){tmp->i , tmp->y});
		sfRenderWindow_drawSprite(context->window, tmp->s_duck, NULL);
		tmp = tmp->next;
	}
}

void display_system(system_t *system, context_t *context)
{
	if (context->check_status == 1) {
		sfSprite_setPosition(system->s_die, (sfVector2f){system->pos_x,
			system->pos_y});
		sfRenderWindow_drawSprite(context->window, system->s_die, NULL);
	}
}

void display_window(bird_t *bird, context_t *context, system_t *system,
	int check)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(context->window);
	text_score(system, sfBlack, 60);

	sfText_setPosition(system->score, (sfVector2f){105, 455});
	play_music(context);
	sfRenderWindow_clear(context->window, sfBlack);
	sfRenderWindow_setView(context->window, context->no_scope);
	sfSprite_setOrigin(context->s_unprecise, (sfVector2f){205, 205});
	sfSprite_setPosition(context->s_unprecise,
		(sfVector2f){mouse.x, mouse.y});
	sfRenderWindow_drawSprite(context->window, context->s_stage, NULL);
	sfRenderWindow_drawSprite(context->window, context->s_sniper, NULL);
	display_bird(bird, context);
	display_system(system, context);
	sfRenderWindow_drawSprite(context->window, context->s_plane, NULL);
	sfRenderWindow_drawSprite(context->window, context->s_unprecise, NULL);
	sfRenderWindow_drawText(context->window, system->score, NULL);
	if (check == 1)
		sfRenderWindow_display(context->window);
}

void display_zoom(bird_t *bird, context_t *context, system_t *system,
	int check)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(context->window);
	text_score(system, sfBlack, 60);

	sfText_setPosition(system->score, (sfVector2f){105, 455});
	play_music(context);
	sfRenderWindow_clear(context->window, sfBlack);
	sfSprite_setOrigin(context->s_precise, (sfVector2f){205, 205});
	sfSprite_setPosition(context->s_precise,
		(sfVector2f){mouse.x + 30, mouse.y + 30});
	sfSprite_setTexture(context->s_unprecise, context->t_unprecise, sfTrue);
	sfRenderWindow_setView(context->window, context->scope);
	sfView_setCenter(context->scope, (sfVector2f){mouse.x, mouse.y});
	sfRenderWindow_drawSprite(context->window, context->s_stage, NULL);
	display_bird(bird, context);
	display_system(system, context);
	sfRenderWindow_drawSprite(context->window, context->s_plane, NULL);
	sfRenderWindow_drawSprite(context->window, context->s_precise, NULL);
	sfRenderWindow_drawText(context->window, system->score, NULL);
	if (check == 1)
		sfRenderWindow_display(context->window);
}
