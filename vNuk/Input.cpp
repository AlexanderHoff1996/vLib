#include "Input.h"

//=============================================================================
void vNuk::inputBegin()	{nk_input_begin(NuklearContext::context);}
void vNuk::inputEnd()	{nk_input_end(NuklearContext::context);}

//=============================================================================
void vNuk::handleEvent(SDL_Event* event) {nk_sdl_handle_event(event);}