#ifndef SDL_KEY_MAP_H
#define SDL_KEY_MAP_H

#include <SDL_hints.h>

#include "core/event/key_map.h"

namespace Workshop
{
	class SDL_KeyMap
	{
	private:
		std::unordered_map<Uint32, KeyboardKeys>	keyboard_translator;
		std::unordered_map<Uint32, MouseKeys>		mouse_translator;

		SDL_KeyMap();
		
	public:
		inline static SDL_KeyMap* GetInstance()
		{
			static SDL_KeyMap ins;
			return &ins;
		}

		inline std::unordered_map<Uint32, KeyboardKeys> GetKeyboardTranslator() const
		{
			return keyboard_translator;
		}

		inline std::unordered_map<Uint32, MouseKeys> GetMouseTranslator() const
		{
			return mouse_translator;
		}
	};
}

#endif // SDL_KEY_MAP_H