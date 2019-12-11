#include "workshop_pch.h"
#include "event_handler.h"

void Workshop::EventHandler::Reset()
{
	current_keyboard_key_down = KEY_NONE;
	current_keyboard_key_up = KEY_NONE;
	
	current_mouse_key_down = MOUSE_KEY_NONE;
	current_mouse_key_up = MOUSE_KEY_NONE;
}
