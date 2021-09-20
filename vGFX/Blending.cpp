#include "Blending.h"

//=============================================================================
void vGFX::enableBlending()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void vGFX::disableBlending()
{
	glDisable(GL_BLEND);
}