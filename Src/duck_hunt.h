/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** header duck_hunt
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>

typedef struct context {
	sfRenderWindow *window;
	sfSprite *s_sniper;
	sfTexture *t_sniper;
	sfSprite *s_stage;
	sfTexture *t_stage;
	sfSprite *s_plane;
	sfTexture *t_plane;
	sfSprite *s_unprecise;
	sfTexture *t_unprecise;
	sfSprite *s_precise;
	sfTexture *t_precise;
	sfMusic *tir;
	sfMusic *music;
	sfView *scope;
	const sfView *no_scope;
	sfClock *clock;
	sfTime time;
	float seconds;
	float seconds_pause;
	int zoom;
	int check_status;
} context_t;

typedef struct system {
	sfSprite *s_die;
	sfTexture *t_die;
	sfSprite *s_menu;
	sfTexture *t_menu;
	sfMusic *music;
	sfClock *clock;
	sfText *result;
	sfText *command;
	sfText *score;
	sfFont *font;
	sfIntRect rect;
	sfTime time;
	int alive;
	int offset;
	float seconds;
	float pos_x;
	float pos_y;
	int menu_status;
	int pause;
} system_t;

typedef struct bird {
	sfSprite *s_duck;
	sfTexture *t_duck;
	sfClock *clock;
	sfTime time;
	sfIntRect rect;
	int offset;
	float i;
	float y;
	float seconds;
	int starter;
	struct bird *next;
} bird_t;

context_t *init_context(void);
bird_t *init_bird(bird_t **, int);
system_t *init_system(void);
bird_t *detect_touch_nozoom(bird_t *bird, context_t **context,
	system_t **system);
bird_t *detect_touch_zoom(bird_t *bird, context_t **context, system_t **system);
void destroy_context(context_t *);
void destroy_system(system_t *);
void destroy_bird(bird_t *, int);
void restart(context_t *, system_t *);
bird_t *menu(context_t *, bird_t *, sfVideoMode, system_t *);
void destroy_starter(sfMusic *, sfFont *, sfText *);
void init_sprite(context_t *, bird_t *, system_t *);
void display_window(bird_t *, context_t *, system_t *, int);
void display_zoom(bird_t *, context_t *, system_t *, int);
void display_starter(context_t *, sfText *, sfFont *, sfMusic *);
void play_menu(system_t *, context_t *);
void play_music(context_t *);
void play_starter(sfMusic *);
void text_score(system_t *, sfColor, int);
char *manage_score(int);
int rules(char **, system_t *);
bird_t *manage_pause(context_t **, system_t **, sfEvent, bird_t *);
bird_t *analyse_events(context_t **, sfEvent, bird_t *, system_t **);
bird_t *game(context_t *, system_t *, bird_t *, sfVideoMode);
bird_t *move_birds(context_t *, sfVideoMode, bird_t *);
system_t *move_system(system_t *, context_t **);
