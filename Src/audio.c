/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** audio.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include "duck_hunt.h"

void play_menu(system_t *system, context_t *context)
{
	if (sfMusic_getStatus(context->music) == sfPlaying)
		sfMusic_stop(context->music);
	if (sfMusic_getStatus(system->music) == sfStopped)
		sfMusic_play(system->music);
}

void play_starter(sfMusic *music)
{
	if (sfMusic_getStatus(music) == sfStopped)
		sfMusic_play(music);
}

void play_music(context_t *context)
{
	if (sfMusic_getStatus(context->music) == sfStopped)
		sfMusic_play(context->music);
}
