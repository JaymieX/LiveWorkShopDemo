#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "key_map.h"

namespace Workshop
{
	class EventHandler final
	{
	private:
		friend class GL_Window;
		
		KeyboardKeys current_keyboard_key_down = KEY_NONE;
		KeyboardKeys current_keyboard_key_up = KEY_NONE;

		MouseKeys current_mouse_key_down = MOUSE_KEY_NONE;
		MouseKeys current_mouse_key_up = MOUSE_KEY_NONE;

	public:
		void Reset();

		KeyboardKeys GetKeyboardDown()
		{
			return current_keyboard_key_down;
		}

		KeyboardKeys GetKeyboardUp()
		{
			return current_keyboard_key_up;
		}

		MouseKeys GetMouseDown()
		{
			return current_mouse_key_down;
		}

		MouseKeys GetMouseUp()
		{
			return current_mouse_key_up;
		}

	};
}

#endif // EVENT_HANDLER_H