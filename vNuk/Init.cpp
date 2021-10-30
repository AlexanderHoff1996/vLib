#include "Init.h"

// This code should ONLY be in this file
#define NK_IMPLEMENTATION
#define NUKLEARSDL_IMPLEMENTATION

//=============================================================================
void vNuk::init(SDL_Window* window)
{
	NuklearContext::context = nk_sdl_init(window);
	{struct nk_font_atlas* atlas;
	nk_sdl_font_stash_begin(&atlas);
	/*struct nk_font *droid = nk_font_atlas_add_from_file(atlas, "../../../extra_font/DroidSans.ttf", 14, 0);*/
	nk_sdl_font_stash_end();
	/*nk_style_load_all_cursors(ctx, atlas->cursors);*/
	/*nk_style_set_font(ctx, &roboto->handle);*/}
}