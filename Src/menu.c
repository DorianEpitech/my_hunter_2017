/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** menu.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "duck_hunt.h"

static const int starter[20] = {
	43,
	42,
	40,
	37,
	36,
	34,
	28,
	26,
	24,
	23,
	20,
	19,
	17,
	11,
	9,
	8,
	6,
	4,
	3,
	1
};

void text_score(system_t *system, sfColor color, int size)
{
	char *number = manage_score(system->alive);

	sfText_setString(system->score, number);
	sfText_setColor(system->score, color);
	sfText_setFont(system->score, system->font);
	sfText_setCharacterSize(system->score, size);
	free(number);
}

void event_menu(sfEvent event, context_t *context, system_t *system)
{
	while (sfRenderWindow_pollEvent(context->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(context->window);
		if (event.key.type == sfEvtKeyPressed)
			system->menu_status = 2;
	}
}

void menu_text(context_t *context, system_t *system)
{
	text_score(system, sfBlack, 150);

	sfText_setString(system->result, "Press Any Key To Restart");
	sfText_setPosition(system->result, (sfVector2f){150, 300});
	sfText_setColor(system->result, sfBlack);
	sfText_setFont(system->result, system->font);
	sfText_setCharacterSize(system->result, 125);
	if (context->check_status == 2) {
		sfText_setString(system->command, "You Loose...");
		sfText_setPosition(system->score, (sfVector2f){725, 600});
		sfRenderWindow_drawText(context->window, system->score, NULL);
	} else
		sfText_setString(system->command, "You Win !!!");
	sfText_setPosition(system->command, (sfVector2f){550, 150});
	sfText_setColor(system->command, sfBlack);
	sfText_setFont(system->command, system->font);
	sfText_setCharacterSize(system->command, 150);
	sfRenderWindow_drawText(context->window, system->result, NULL);
	sfRenderWindow_drawText(context->window, system->command, NULL);
}

void display_menu(context_t *context, system_t *system)
{
	sfRenderWindow_clear(context->window, sfBlack);
	play_menu(system, context);
	sfRenderWindow_setView(context->window, context->no_scope);
	sfRenderWindow_drawSprite(context->window, system->s_menu, NULL);
	menu_text(context, system);
	sfRenderWindow_display(context->window);
}

bird_t *menu(context_t *context, bird_t *bird, sfVideoMode mode,
	system_t *system)
{
	int i = 0;
	bird_t *new_bird = NULL;
	sfEvent event;

	while (sfRenderWindow_isOpen(context->window)
	&& system->menu_status == 1) {
		event_menu(event, context, system);
		display_menu(context, system);
	}
	sfMusic_stop(system->music);
	if (system->menu_status == 2) {
		restart(context, system);
		destroy_bird(bird, 0);
		while (i < 20) {
			init_bird(&new_bird, starter[i]);
			i = i + 1;
		}
		bird = game(context, system, new_bird, mode);
	}
	return (bird);
}
