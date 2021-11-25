#pragma once

#include "nuklear/NuklearSDL.h"

#include <iostream>

//=============================================================================
namespace vNuk {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

namespace layout {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
void rowDynamic(float height, int columns);
void rowStatic(float width, float height, int columns);
void rowBegin(nk_layout_format format, float height, int columns);
void rowPush(float value);
void rowEnd();
void row(nk_layout_format format, float height, int columns, const float* ratio);

//=============================================================================
class Space
{
public:
	void begin(nk_layout_format format, float height, int columns);
	void push(struct nk_rect bounds);
	void end();

private:
};

//=============================================================================
// nk_layout_set_min_row_height
// nk_layout_reset_min_row_height
// nk_layout_widget_bounds
// nk_layout_ratio_from_pixel

//=============================================================================
// nk_layout_row_template_begin
// nk_layout_row_template_push_dynamic
// nk_layout_row_template_push_variable
// nk_layout_row_template_push_static
// nk_layout_row_template_end

//=============================================================================
// nk_layout_space_bounds
// nk_layout_space_to_screen
// nk_layout_space_to_local
// nk_layout_space_rect_to_screen
// nk_layout_space_rect_to_local

//  _______________
// | NAMESPACE END |	// layout
//  ***************
}

//  _______________
// | NAMESPACE END |	// vNuk
//  ***************
}