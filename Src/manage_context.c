/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** manage_context.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdlib.h>
#include <time.h>
#include "duck_hunt.h"

char *manage_score(int alive)
{
	char *result = malloc(11);

	result[0] = 'A';
	result[1] = 'l';
	result[2] = 'i';
	result[3] = 'v';
	result[4] = 'e';
	result[5] = '\n';
	result[6] = '(';
	result[8] = alive % 10 + 48;
	alive = alive / 10;
	result[7] = alive % 10 + 48;
	result[9] = ')';
	result[10] = '\0';
	return (result);
}

bird_t *init_bird(bird_t **bird, int start)
{
	bird_t *element = malloc(sizeof(bird_t));
	sfIntRect tmp = {0, 0, 60, 60};

	element->s_duck = sfSprite_create();
	element->t_duck = sfTexture_createFromFile("Obj/duck_fly.png", NULL);
	element->seconds = 0;
	element->i = 0;
	element->y = rand()%500;
	element->offset = 0;
	element->clock = sfClock_create();
	element->next = *bird;
	element->starter = start;
	element->rect = tmp;
	*bird = element;
	return (element);
}

system_t *init_system(void)
{
	system_t *element = malloc(sizeof(system_t));
	sfIntRect tmp = {0, 0, 60, 60};

	element->rect = tmp;
	element->s_die = sfSprite_create();
	element->t_die = sfTexture_createFromFile("Obj/duck_die.png", NULL);
	element->s_menu = sfSprite_create();
	element->t_menu = sfTexture_createFromFile("Obj/menu.png", NULL);
	element->music = sfMusic_createFromFile("Obj/menu.ogg");
	element->result = sfText_create();
	element->command = sfText_create();
	element->score = sfText_create();
	element->font = sfFont_createFromFile("Obj/RioGrande.ttf");
	element->offset = 0;
	element->seconds = 0;
	element->clock = sfClock_create();
	element->menu_status = 1;
	element->alive = 20;
	element->pause = -1;
	return (element);
}

context_t *init_context(void)
{
	context_t *element = malloc(sizeof(context_t));

	element->s_sniper = sfSprite_create();
	element->s_stage = sfSprite_create();
	element->s_unprecise = sfSprite_create();
	element->s_precise = sfSprite_create();
	element->s_plane = sfSprite_create();
	element->t_plane = sfTexture_createFromFile("Obj/plane.png", NULL);
	element->t_sniper = sfTexture_createFromFile("Obj/sniper.png", NULL);
	element->t_stage = sfTexture_createFromFile("Obj/stage.png", NULL);
	element->t_unprecise = sfTexture_createFromFile("Obj/unpre.png", NULL);
	element->t_precise = sfTexture_createFromFile("Obj/precise.png", NULL);
	element->tir = sfMusic_createFromFile("Obj/tir.ogg");
	element->music = sfMusic_createFromFile("Obj/game.ogg");
	element->scope = sfView_createFromRect((sfFloatRect){0, 0, 300, 300});
	element->clock = sfClock_create();
	element->seconds_pause = 0;
	element->zoom = 1;
	element->check_status = 0;
	return (element);
}

void init_sprite(context_t *context, bird_t *bird, system_t *system)
{
	while (bird != NULL) {
		sfSprite_setTexture(bird->s_duck, bird->t_duck, sfTrue);
		bird = bird->next;
	}
	sfSprite_setTexture(system->s_menu, system->t_menu, sfTrue);
	sfSprite_setTexture(system->s_die, system->t_die, sfTrue);
	sfSprite_setTexture(context->s_stage, context->t_stage, sfTrue);
	sfSprite_setTexture(context->s_sniper, context->t_sniper, sfTrue);
	sfSprite_setTexture(context->s_unprecise, context->t_unprecise, sfTrue);
	sfSprite_setTexture(context->s_precise, context->t_precise, sfTrue);
	sfSprite_setTexture(context->s_plane, context->t_plane, sfTrue);
	sfSprite_setPosition(context->s_sniper, (sfVector2f){1170 , 699});
	sfRenderWindow_setMouseCursorVisible(context->window , sfFalse);
}
