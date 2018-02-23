/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** bootstrap
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

void laucher(context_t *context)
{
	sfMusic *start_race = sfMusic_createFromFile("Obj/starter.ogg");
	sfFont *font = sfFont_createFromFile("Obj/RioGrande.ttf");
	sfText *text = sfText_create();

	context->seconds = 0;
	while (context->seconds < 5.6) {
		context->time = sfClock_getElapsedTime(context->clock);
		context->seconds = context->time.microseconds/1000000.0;
		if (context->seconds < 1.7) {
			sfText_setString(text, "(3)");
		} else if (context->seconds < 3.4) {
			sfText_setString(text, "(2)");
		} else if (context->seconds < 5.6) {
			sfText_setString(text, "(1)");
		}
		display_starter(context, text, font, start_race);
	}
	context->seconds = 0;
	sfClock_restart(context->clock);
	destroy_starter(start_race, font, text);
}

bird_t *manage_mouse_click(sfMouseButtonEvent event, context_t **context,
	bird_t *bird, system_t **system)
{
	if (event.button == sfMouseLeft) {
		if (sfMusic_getStatus((*context)->tir) == sfStopped
		&& (*context)->zoom == -1) {
			bird = detect_touch_zoom(bird, context, system);
		} else if (sfMusic_getStatus((*context)->tir) == sfStopped
		&& (*context)->zoom == 1) {
			bird = detect_touch_nozoom(bird, context, system);
		}
	} else if (event.button == sfMouseRight) {
		(*context)->zoom = -(*context)->zoom;
	}
	return (bird);
}

bird_t *analyse_events(context_t **context, sfEvent event, bird_t *bird,
	system_t **system)
{
	while (sfRenderWindow_pollEvent((*context)->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close((*context)->window);
		if (event.key.type == sfEvtKeyPressed)
			bird = manage_pause(context, system, event, bird);
		if (event.mouseButton.type == sfEvtMouseButtonPressed
		&& (*system)->pause != 1)
			bird = manage_mouse_click(event.mouseButton, context,
				bird, system);
	}
	return (bird);
}

bird_t *game(context_t *context, system_t *system, bird_t *bird,
	sfVideoMode mode)
{
	sfEvent event;

	init_sprite(context, bird, system);
	laucher(context);
	while (sfRenderWindow_isOpen(context->window)
	&& context->check_status < 2 && system->alive != 0) {
		context->time = sfClock_getElapsedTime(context->clock);
		context->seconds = context->time.microseconds/1000000.0;
		context->seconds = context->seconds - context->seconds_pause;
		bird = analyse_events(&context, event, bird, &system);
		bird = move_birds(context, mode, bird);
		system = move_system(system, &context);
		if (context->zoom == 1) {
			display_window(bird, context, system, 1);
		} else if (context->zoom == -1) {
			display_zoom(bird, context, system, 1);
		}
	}
	bird = menu(context, bird, mode, system);
	return (bird);
}

int main(int ac, char **av)
{
	sfVideoMode mode = {1920, 1080, 32};
	system_t *system = init_system();
	context_t *context;
	bird_t *bird = NULL;

	if (ac > 1)
		return (rules(av, system));
	context = init_context();
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		init_bird(&bird, starter[i]);
	context->window = sfRenderWindow_create(mode, "duck_hunt",
	sfDefaultStyle, NULL);
	context->no_scope = sfRenderWindow_getDefaultView(context->window);
	bird = game(context, system, bird, mode);
	destroy_system(system);
	destroy_bird(bird, 0);
	destroy_context(context);
	return (0);
}
