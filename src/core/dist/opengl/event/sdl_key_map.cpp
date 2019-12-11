#include "workshop_pch.h"
#include "sdl_key_map.h"

#include <SDL.h>

Workshop::SDL_KeyMap::SDL_KeyMap()
{
	keyboard_translator.emplace(SDLK_1, KEY_1);
	keyboard_translator.emplace(SDLK_2, KEY_2);
	keyboard_translator.emplace(SDLK_3, KEY_3);
	keyboard_translator.emplace(SDLK_4, KEY_4);
	keyboard_translator.emplace(SDLK_5, KEY_5);
	keyboard_translator.emplace(SDLK_6, KEY_6);
	keyboard_translator.emplace(SDLK_7, KEY_7);
	keyboard_translator.emplace(SDLK_8, KEY_8);
	keyboard_translator.emplace(SDLK_9, KEY_9);
	keyboard_translator.emplace(SDLK_0, KEY_0);
	keyboard_translator.emplace(SDLK_a, KEY_A);
	keyboard_translator.emplace(SDLK_b, KEY_B);
	keyboard_translator.emplace(SDLK_c, KEY_C);
	keyboard_translator.emplace(SDLK_d, KEY_D);
	keyboard_translator.emplace(SDLK_e, KEY_E);
	keyboard_translator.emplace(SDLK_f, KEY_F);
	keyboard_translator.emplace(SDLK_g, KEY_G);
	keyboard_translator.emplace(SDLK_h, KEY_H);
	keyboard_translator.emplace(SDLK_i, KEY_I);
	keyboard_translator.emplace(SDLK_j, KEY_J);
	keyboard_translator.emplace(SDLK_k, KEY_K);
	keyboard_translator.emplace(SDLK_l, KEY_L);
	keyboard_translator.emplace(SDLK_m, KEY_M);
	keyboard_translator.emplace(SDLK_n, KEY_N);
	keyboard_translator.emplace(SDLK_o, KEY_O);
	keyboard_translator.emplace(SDLK_p, KEY_P);
	keyboard_translator.emplace(SDLK_q, KEY_Q);
	keyboard_translator.emplace(SDLK_r, KEY_R);
	keyboard_translator.emplace(SDLK_s, KEY_S);
	keyboard_translator.emplace(SDLK_t, KEY_T);
	keyboard_translator.emplace(SDLK_u, KEY_U);
	keyboard_translator.emplace(SDLK_v, KEY_V);
	keyboard_translator.emplace(SDLK_w, KEY_W);
	keyboard_translator.emplace(SDLK_x, KEY_X);
	keyboard_translator.emplace(SDLK_y, KEY_Y);
	keyboard_translator.emplace(SDLK_z, KEY_Z);

	mouse_translator.emplace(SDL_BUTTON_LEFT, LEFT);
	mouse_translator.emplace(SDL_BUTTON_MIDDLE, MIDDLE);
	mouse_translator.emplace(SDL_BUTTON_RIGHT, RIGHT);
}
