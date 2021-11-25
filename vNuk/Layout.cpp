#include "Layout.h"

//=============================================================================
void vNuk::layout::rowDynamic(float height, int columns)
{
	nk_layout_row_dynamic(NuklearContext::context, height, columns);
}

void vNuk::layout::rowStatic(float width, float height, int columns)
{
	nk_layout_row_static(NuklearContext::context, height,
		static_cast<int>(std::round(width)), columns);
}

void vNuk::layout::rowBegin(nk_layout_format format, float height, int columns)
{
	nk_layout_row_begin(NuklearContext::context, format, height, columns);
}

void vNuk::layout::rowPush(float value)
{
	nk_layout_row_push(NuklearContext::context, value);
}

void vNuk::layout::rowEnd()
{
	nk_layout_row_end(NuklearContext::context);
}

void vNuk::layout::row(nk_layout_format format,
	float height, int columns, const float* ratio)
{
	nk_layout_row(NuklearContext::context, format, height, columns, ratio);
}

//=============================================================================
void vNuk::layout::Space::begin(nk_layout_format format,
	float height, int columns)
{
	nk_layout_space_begin(NuklearContext::context, format, height, columns);
}

void vNuk::layout::Space::push(struct nk_rect bounds)
{
	nk_layout_space_push(NuklearContext::context, bounds);
}

void vNuk::layout::Space::end()
{
	nk_layout_space_end(NuklearContext::context);
}