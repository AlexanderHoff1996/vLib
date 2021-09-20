#pragma once

#include <glad/glad.h>

namespace vGFX {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

namespace color {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
struct ColorF		{GLfloat r, g, b;};
struct ColorFA		{GLfloat r, g, b, a;};

struct ColorRGB		{GLuint r, g, b;};
struct ColorRGBA	{GLuint r, g, b, a;};

typedef const GLchar ColorHex[6];

//=============================================================================
namespace colorF {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
const ColorF black					{0 / 255.f,		0 / 255.f,		0 / 255.f};
const ColorF white					{255 / 255.f,	255 / 255.f,	255 / 255.f};

const ColorF red					{255 / 255.f,	0 / 255.f,		0 / 255.f};
const ColorF lime					{0 / 255.f,		255 / 255.f,	0 / 255.f};
const ColorF blue					{0 / 255.f,		0 / 255.f,		255 / 255.f};

const ColorF yellow					{255 / 255.f,	255 / 255.f,	0 / 255.f};
const ColorF magenta				{255 / 255.f,	0 / 255.f,		255 / 255.f};
const ColorF cyan					{0 / 255.f,		255 / 255.f,	255 / 255.f};

//=============================================================================
const ColorF aliceBlue				{240 / 255.f,	248 / 255.f,	255 / 255.f};
const ColorF antiqueWhite			{250 / 255.f,	235 / 255.f,	215 / 255.f};
const ColorF aqua					{0 / 255.f,		255 / 255.f,	255 / 255.f};
const ColorF aquamarine				{127 / 255.f,	255 / 255.f,	212 / 255.f};
const ColorF azure					{240 / 255.f,	255 / 255.f,	255 / 255.f};
const ColorF beige					{245 / 255.f,	245 / 255.f,	220 / 255.f};
const ColorF bisque					{255 / 255.f,	228 / 255.f,	196 / 255.f};
const ColorF blanchedAlmond			{255 / 255.f,	235 / 255.f,	205 / 255.f};
const ColorF blueViolet				{138 / 255.f,	43 / 255.f,		226 / 255.f};
const ColorF brown					{165 / 255.f,	42 / 255.f,		42 / 255.f};
const ColorF burlyWood				{222 / 255.f,	184 / 255.f,	135 / 255.f};
const ColorF cadetBlue				{95 / 255.f,	158 / 255.f,	160 / 255.f};
const ColorF chartreuse				{127 / 255.f,	255 / 255.f,	0 / 255.f};
const ColorF chocolate				{210 / 255.f,	105 / 255.f,	30 / 255.f};
const ColorF coral					{255 / 255.f,	127 / 255.f,	80 / 255.f};
const ColorF cornflowerBlue			{100 / 255.f,	149 / 255.f,	237 / 255.f};
const ColorF cornsilk				{255 / 255.f,	248 / 255.f,	220 / 255.f};
const ColorF crimson				{220 / 255.f,	20 / 255.f,		60 / 255.f};
const ColorF darkBlue				{0 / 255.f,		0 / 255.f,		139 / 255.f};
const ColorF darkCyan				{0 / 255.f,		139 / 255.f,	139 / 255.f};
const ColorF darkGoldenRod			{184 / 255.f,	134 / 255.f,	11 / 255.f};
const ColorF darkGrey				{169 / 255.f,	169 / 255.f,	169 / 255.f};
const ColorF darkGreen				{0 / 255.f,		100 / 255.f,	0 / 255.f};
const ColorF darkKhaki				{189 / 255.f,	183 / 255.f,	107 / 255.f};
const ColorF darkMagenta			{139 / 255.f,	0 / 255.f,		139 / 255.f};
const ColorF darkOliveGreen			{85 / 255.f,	107 / 255.f,	47 / 255.f};
const ColorF darkOrange				{255 / 255.f,	140 / 255.f,	0 / 255.f};
const ColorF darkOrchid				{153 / 255.f,	50 / 255.f,		204 / 255.f};
const ColorF darkRed				{139 / 255.f,	0 / 255.f,		0 / 255.f};
const ColorF darkSalmon				{233 / 255.f,	150 / 255.f,	122 / 255.f};
const ColorF darkSeaGreen			{143 / 255.f,	188 / 255.f,	143 / 255.f};
const ColorF darkSlateBlue			{72 / 255.f,	61 / 255.f,		139 / 255.f};
const ColorF darkSlateGrey			{47 / 255.f,	79 / 255.f,		79 / 255.f};
const ColorF darkTurquoise			{0 / 255.f,		206 / 255.f,	209 / 255.f};
const ColorF darkViolet				{148 / 255.f,	0 / 255.f,		211 / 255.f};
const ColorF deepPink				{255 / 255.f,	20 / 255.f,		147 / 255.f};
const ColorF deepSkyBlue			{0 / 255.f,		191 / 255.f,	255 / 255.f};
const ColorF dimGrey				{105 / 255.f,	105 / 255.f,	105 / 255.f};
const ColorF dodgerBlue				{30 / 255.f,	144 / 255.f,	255 / 255.f};
const ColorF fireBrick				{178 / 255.f,	34 / 255.f,		34 / 255.f};
const ColorF floralWhite			{255 / 255.f,	250 / 255.f,	240 / 255.f};
const ColorF forestGreen			{34 / 255.f,	139 / 255.f,	34 / 255.f};
const ColorF fuchsia				{255 / 255.f,	0 / 255.f,		255 / 255.f};
const ColorF gainsboro				{220 / 255.f,	220 / 255.f,	220 / 255.f};
const ColorF ghostWhite				{248 / 255.f,	248 / 255.f,	255 / 255.f};
const ColorF gold					{255 / 255.f,	215 / 255.f,	0 / 255.f};
const ColorF goldenRod				{218 / 255.f,	165 / 255.f,	32 / 255.f};
const ColorF grey					{128 / 255.f,	128 / 255.f,	128 / 255.f};
const ColorF green					{0 / 255.f,		128 / 255.f,	0 / 255.f};
const ColorF greenYellow			{173 / 255.f,	255 / 255.f,	47 / 255.f};
const ColorF honeyDew				{240 / 255.f,	255 / 255.f,	240 / 255.f};
const ColorF hotPink				{255 / 255.f,	105 / 255.f,	180 / 255.f};
const ColorF indianRed				{205 / 255.f,	92 / 255.f,		92 / 255.f};
const ColorF indigo					{75 / 255.f,	0 / 255.f,		130 / 255.f};
const ColorF ivory					{255 / 255.f,	255 / 255.f,	240 / 255.f};
const ColorF khaki					{240 / 255.f,	230 / 255.f,	140 / 255.f};
const ColorF lavender				{230 / 255.f,	230 / 255.f,	250 / 255.f};
const ColorF lavenderBlush			{255 / 255.f,	240 / 255.f,	245 / 255.f};
const ColorF lawnGreen				{124 / 255.f,	252 / 255.f,	0 / 255.f};
const ColorF lemonChiffon			{255 / 255.f,	250 / 255.f,	205 / 255.f};
const ColorF lightBlue				{173 / 255.f,	216 / 255.f,	230 / 255.f};
const ColorF lightCoral				{240 / 255.f,	128 / 255.f,	128 / 255.f};
const ColorF lightCyan				{224 / 255.f,	255 / 255.f,	255 / 255.f};
const ColorF lightGoldenRodYellow	{250 / 255.f,	250 / 255.f,	210 / 255.f};
const ColorF lightGrey				{211 / 255.f,	211 / 255.f,	211 / 255.f};
const ColorF lightGreen				{144 / 255.f,	238 / 255.f,	144 / 255.f};
const ColorF lightPink				{255 / 255.f,	182 / 255.f,	193 / 255.f};
const ColorF lightSalmon			{255 / 255.f,	160 / 255.f,	122 / 255.f};
const ColorF lightSeaGreen			{32 / 255.f,	178 / 255.f,	170 / 255.f};
const ColorF lightSkyBlue			{135 / 255.f,	206 / 255.f,	250 / 255.f};
const ColorF lightSlateGrey			{119 / 255.f,	136 / 255.f,	153 / 255.f};
const ColorF lightSteelBlue			{176 / 255.f,	196 / 255.f,	222 / 255.f};
const ColorF lightYellow			{255 / 255.f,	255 / 255.f,	224 / 255.f};
const ColorF limeGreen				{50 / 255.f,	205 / 255.f,	50 / 255.f};
const ColorF linen					{250 / 255.f,	240 / 255.f,	230 / 255.f};
const ColorF maroon					{128 / 255.f,	0 / 255.f,		0 / 255.f};
const ColorF mediumAquaMarine		{102 / 255.f,	205 / 255.f,	170 / 255.f};
const ColorF mediumBlue				{0 / 255.f,		0 / 255.f,		205 / 255.f};
const ColorF mediumOrchid			{186 / 255.f,	85 / 255.f,		211 / 255.f};
const ColorF mediumPurple			{147 / 255.f,	112 / 255.f,	219 / 255.f};
const ColorF mediumSeaGreen			{60 / 255.f,	179 / 255.f,	113 / 255.f};
const ColorF mediumSlateBlue		{123 / 255.f,	104 / 255.f,	238 / 255.f};
const ColorF mediumSpringGreen		{0 / 255.f,		250 / 255.f,	154 / 255.f};
const ColorF mediumTurquoise		{72 / 255.f,	209 / 255.f,	204 / 255.f};
const ColorF mediumVioletRed		{199 / 255.f,	21 / 255.f,		133 / 255.f};
const ColorF midnightBlue			{25 / 255.f,	25 / 255.f,		112 / 255.f};
const ColorF mintCream				{245 / 255.f,	255 / 255.f,	250 / 255.f};
const ColorF mistyRose				{255 / 255.f,	228 / 255.f,	225 / 255.f};
const ColorF moccasin				{255 / 255.f,	228 / 255.f,	181 / 255.f};
const ColorF navajoWhite			{255 / 255.f,	222 / 255.f,	173 / 255.f};
const ColorF navy					{0 / 255.f,		0 / 255.f,		128 / 255.f};
const ColorF oldLace				{253 / 255.f,	245 / 255.f,	230 / 255.f};
const ColorF olive					{128 / 255.f,	128 / 255.f,	0 / 255.f};
const ColorF oliveDrab				{107 / 255.f,	142 / 255.f,	35 / 255.f};
const ColorF orange					{255 / 255.f,	165 / 255.f,	0 / 255.f};
const ColorF orangeRed				{255 / 255.f,	69 / 255.f,		0 / 255.f};
const ColorF orchid					{218 / 255.f,	112 / 255.f,	214 / 255.f};
const ColorF paleGoldenRod			{238 / 255.f,	232 / 255.f,	170 / 255.f};
const ColorF paleGreen				{152 / 255.f,	251 / 255.f,	152 / 255.f};
const ColorF paleTurquoise			{175 / 255.f,	238 / 255.f,	238 / 255.f};
const ColorF paleVioletRed			{219 / 255.f,	112 / 255.f,	147 / 255.f};
const ColorF papayaWhip				{255 / 255.f,	239 / 255.f,	213 / 255.f};
const ColorF peachPuff				{255 / 255.f,	218 / 255.f,	185 / 255.f};
const ColorF peru					{205 / 255.f,	133 / 255.f,	63 / 255.f};
const ColorF pink					{255 / 255.f,	192 / 255.f,	203 / 255.f};
const ColorF plum					{221 / 255.f,	160 / 255.f,	221 / 255.f};
const ColorF powderBlue				{176 / 255.f,	224 / 255.f,	230 / 255.f};
const ColorF purple					{128 / 255.f,	0 / 255.f,		128 / 255.f};
const ColorF rebeccaPurple			{102 / 255.f,	51 / 255.f,		153 / 255.f};
const ColorF rosyBrown				{188 / 255.f,	143 / 255.f,	143 / 255.f};
const ColorF royalBlue				{65 / 255.f,	105 / 255.f,	225 / 255.f};
const ColorF saddleBrown			{139 / 255.f,	69 / 255.f,		19 / 255.f};
const ColorF salmon					{250 / 255.f,	128 / 255.f,	114 / 255.f};
const ColorF sandyBrown				{244 / 255.f,	164 / 255.f,	96 / 255.f};
const ColorF seaGreen				{46 / 255.f,	139 / 255.f,	87 / 255.f};
const ColorF seaShell				{255 / 255.f,	245 / 255.f,	238 / 255.f};
const ColorF sienna					{160 / 255.f,	82 / 255.f,		45 / 255.f};
const ColorF silver					{192 / 255.f,	192 / 255.f,	192 / 255.f};
const ColorF skyBlue				{135 / 255.f,	206 / 255.f,	235 / 255.f};
const ColorF slateBlue				{106 / 255.f,	90 / 255.f,		205 / 255.f};
const ColorF slateGrey				{112 / 255.f,	128 / 255.f,	144 / 255.f};
const ColorF snow					{255 / 255.f,	250 / 255.f,	250 / 255.f};
const ColorF springGreen			{0 / 255.f,		255 / 255.f,	127 / 255.f};
const ColorF steelBlue				{70 / 255.f,	130 / 255.f,	180 / 255.f};
const ColorF tan					{210 / 255.f,	180 / 255.f,	140 / 255.f};
const ColorF teal					{0 / 255.f,		128 / 255.f,	128 / 255.f};
const ColorF thistle				{216 / 255.f,	191 / 255.f,	216 / 255.f};
const ColorF tomato					{255 / 255.f,	99 / 255.f,		71 / 255.f};
const ColorF turquoise				{64 / 255.f,	224 / 255.f,	208 / 255.f};
const ColorF violet					{238 / 255.f,	130 / 255.f,	238 / 255.f};
const ColorF wheat					{245 / 255.f,	222 / 255.f,	179 / 255.f};
const ColorF whiteSmoke				{245 / 255.f,	245 / 255.f,	245 / 255.f};
const ColorF yellowGreen			{154 / 255.f,	205 / 255.f,	50 / 255.f};

//  _______________
// | NAMESPACE END |	// colorF
//  ***************
}

//=============================================================================
namespace colorFA {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
const ColorFA black					{0 / 255.f,		0 / 255.f,		0 / 255.f,		1.f};
const ColorFA white					{255 / 255.f,	255 / 255.f,	255 / 255.f,	1.f};

const ColorFA red					{255 / 255.f,	0 / 255.f,		0 / 255.f,		1.f};
const ColorFA lime					{0 / 255.f,		255 / 255.f,	0 / 255.f,		1.f};
const ColorFA blue					{0 / 255.f,		0 / 255.f,		255 / 255.f,	1.f};

const ColorFA yellow				{255 / 255.f,	255 / 255.f,	0 / 255.f,		1.f};
const ColorFA magenta				{255 / 255.f,	0 / 255.f,		255 / 255.f,	1.f};
const ColorFA cyan					{0 / 255.f,		255 / 255.f,	255 / 255.f,	1.f};

//=============================================================================
const ColorFA aliceBlue				{240 / 255.f,	248 / 255.f,	255 / 255.f,	1.f};
const ColorFA antiqueWhite			{250 / 255.f,	235 / 255.f,	215 / 255.f,	1.f};
const ColorFA aqua					{0 / 255.f,		255 / 255.f,	255 / 255.f,	1.f};
const ColorFA aquamarine			{127 / 255.f,	255 / 255.f,	212 / 255.f,	1.f};
const ColorFA azure					{240 / 255.f,	255 / 255.f,	255 / 255.f,	1.f};
const ColorFA beige					{245 / 255.f,	245 / 255.f,	220 / 255.f,	1.f};
const ColorFA bisque				{255 / 255.f,	228 / 255.f,	196 / 255.f,	1.f};
const ColorFA blanchedAlmond		{255 / 255.f,	235 / 255.f,	205 / 255.f,	1.f};
const ColorFA blueViolet			{138 / 255.f,	43 / 255.f,		226 / 255.f,	1.f};
const ColorFA brown					{165 / 255.f,	42 / 255.f,		42 / 255.f,		1.f};
const ColorFA burlyWood				{222 / 255.f,	184 / 255.f,	135 / 255.f,	1.f};
const ColorFA cadetBlue				{95 / 255.f,	158 / 255.f,	160 / 255.f,	1.f};
const ColorFA chartreuse			{127 / 255.f,	255 / 255.f,	0 / 255.f,		1.f};
const ColorFA chocolate				{210 / 255.f,	105 / 255.f,	30 / 255.f,		1.f};
const ColorFA coral					{255 / 255.f,	127 / 255.f,	80 / 255.f,		1.f};
const ColorFA cornflowerBlue		{100 / 255.f,	149 / 255.f,	237 / 255.f,	1.f};
const ColorFA cornsilk				{255 / 255.f,	248 / 255.f,	220 / 255.f,	1.f};
const ColorFA crimson				{220 / 255.f,	20 / 255.f,		60 / 255.f,		1.f};
const ColorFA darkBlue				{0 / 255.f,		0 / 255.f,		139 / 255.f,	1.f};
const ColorFA darkCyan				{0 / 255.f,		139 / 255.f,	139 / 255.f,	1.f};
const ColorFA darkGoldenRod			{184 / 255.f,	134 / 255.f,	11 / 255.f,		1.f};
const ColorFA darkGrey				{169 / 255.f,	169 / 255.f,	169 / 255.f,	1.f};
const ColorFA darkGreen				{0 / 255.f,		100 / 255.f,	0 / 255.f,		1.f};
const ColorFA darkKhaki				{189 / 255.f,	183 / 255.f,	107 / 255.f,	1.f};
const ColorFA darkMagenta			{139 / 255.f,	0 / 255.f,		139 / 255.f,	1.f};
const ColorFA darkOliveGreen		{85 / 255.f,	107 / 255.f,	47 / 255.f,		1.f};
const ColorFA darkOrange			{255 / 255.f,	140 / 255.f,	0 / 255.f,		1.f};
const ColorFA darkOrchid			{153 / 255.f,	50 / 255.f,		204 / 255.f,	1.f};
const ColorFA darkRed				{139 / 255.f,	0 / 255.f,		0 / 255.f,		1.f};
const ColorFA darkSalmon			{233 / 255.f,	150 / 255.f,	122 / 255.f,	1.f};
const ColorFA darkSeaGreen			{143 / 255.f,	188 / 255.f,	143 / 255.f,	1.f};
const ColorFA darkSlateBlue			{72 / 255.f,	61 / 255.f,		139 / 255.f,	1.f};
const ColorFA darkSlateGrey			{47 / 255.f,	79 / 255.f,		79 / 255.f,		1.f};
const ColorFA darkTurquoise			{0 / 255.f,		206 / 255.f,	209 / 255.f,	1.f};
const ColorFA darkViolet			{148 / 255.f,	0 / 255.f,		211 / 255.f,	1.f};
const ColorFA deepPink				{255 / 255.f,	20 / 255.f,		147 / 255.f,	1.f};
const ColorFA deepSkyBlue			{0 / 255.f,		191 / 255.f,	255 / 255.f,	1.f};
const ColorFA dimGrey				{105 / 255.f,	105 / 255.f,	105 / 255.f,	1.f};
const ColorFA dodgerBlue			{30 / 255.f,	144 / 255.f,	255 / 255.f,	1.f};
const ColorFA fireBrick				{178 / 255.f,	34 / 255.f,		34 / 255.f,		1.f};
const ColorFA floralWhite			{255 / 255.f,	250 / 255.f,	240 / 255.f,	1.f};
const ColorFA forestGreen			{34 / 255.f,	139 / 255.f,	34 / 255.f,		1.f};
const ColorFA fuchsia				{255 / 255.f,	0 / 255.f,		255 / 255.f,	1.f};
const ColorFA gainsboro				{220 / 255.f,	220 / 255.f,	220 / 255.f,	1.f};
const ColorFA ghostWhite			{248 / 255.f,	248 / 255.f,	255 / 255.f,	1.f};
const ColorFA gold					{255 / 255.f,	215 / 255.f,	0 / 255.f,		1.f};
const ColorFA goldenRod				{218 / 255.f,	165 / 255.f,	32 / 255.f,		1.f};
const ColorFA grey					{128 / 255.f,	128 / 255.f,	128 / 255.f,	1.f};
const ColorFA green					{0 / 255.f,		128 / 255.f,	0 / 255.f,		1.f};
const ColorFA greenYellow			{173 / 255.f,	255 / 255.f,	47 / 255.f,		1.f};
const ColorFA honeyDew				{240 / 255.f,	255 / 255.f,	240 / 255.f,	1.f};
const ColorFA hotPink				{255 / 255.f,	105 / 255.f,	180 / 255.f,	1.f};
const ColorFA indianRed				{205 / 255.f,	92 / 255.f,		92 / 255.f,		1.f};
const ColorFA indigo				{75 / 255.f,	0 / 255.f,		130 / 255.f,	1.f};
const ColorFA ivory					{255 / 255.f,	255 / 255.f,	240 / 255.f,	1.f};
const ColorFA khaki					{240 / 255.f,	230 / 255.f,	140 / 255.f,	1.f};
const ColorFA lavender				{230 / 255.f,	230 / 255.f,	250 / 255.f,	1.f};
const ColorFA lavenderBlush			{255 / 255.f,	240 / 255.f,	245 / 255.f,	1.f};
const ColorFA lawnGreen				{124 / 255.f,	252 / 255.f,	0 / 255.f,		1.f};
const ColorFA lemonChiffon			{255 / 255.f,	250 / 255.f,	205 / 255.f,	1.f};
const ColorFA lightBlue				{173 / 255.f,	216 / 255.f,	230 / 255.f,	1.f};
const ColorFA lightCoral			{240 / 255.f,	128 / 255.f,	128 / 255.f,	1.f};
const ColorFA lightCyan				{224 / 255.f,	255 / 255.f,	255 / 255.f,	1.f};
const ColorFA lightGoldenRodYellow	{250 / 255.f,	250 / 255.f,	210 / 255.f,	1.f};
const ColorFA lightGrey				{211 / 255.f,	211 / 255.f,	211 / 255.f,	1.f};
const ColorFA lightGreen			{144 / 255.f,	238 / 255.f,	144 / 255.f,	1.f};
const ColorFA lightPink				{255 / 255.f,	182 / 255.f,	193 / 255.f,	1.f};
const ColorFA lightSalmon			{255 / 255.f,	160 / 255.f,	122 / 255.f,	1.f};
const ColorFA lightSeaGreen			{32 / 255.f,	178 / 255.f,	170 / 255.f,	1.f};
const ColorFA lightSkyBlue			{135 / 255.f,	206 / 255.f,	250 / 255.f,	1.f};
const ColorFA lightSlateGrey		{119 / 255.f,	136 / 255.f,	153 / 255.f,	1.f};
const ColorFA lightSteelBlue		{176 / 255.f,	196 / 255.f,	222 / 255.f,	1.f};
const ColorFA lightYellow			{255 / 255.f,	255 / 255.f,	224 / 255.f,	1.f};
const ColorFA limeGreen				{50 / 255.f,	205 / 255.f,	50 / 255.f,		1.f};
const ColorFA linen					{250 / 255.f,	240 / 255.f,	230 / 255.f,	1.f};
const ColorFA maroon				{128 / 255.f,	0 / 255.f,		0 / 255.f,		1.f};
const ColorFA mediumAquaMarine		{102 / 255.f,	205 / 255.f,	170 / 255.f,	1.f};
const ColorFA mediumBlue			{0 / 255.f,		0 / 255.f,		205 / 255.f,	1.f};
const ColorFA mediumOrchid			{186 / 255.f,	85 / 255.f,		211 / 255.f,	1.f};
const ColorFA mediumPurple			{147 / 255.f,	112 / 255.f,	219 / 255.f,	1.f};
const ColorFA mediumSeaGreen		{60 / 255.f,	179 / 255.f,	113 / 255.f,	1.f};
const ColorFA mediumSlateBlue		{123 / 255.f,	104 / 255.f,	238 / 255.f,	1.f};
const ColorFA mediumSpringGreen		{0 / 255.f,		250 / 255.f,	154 / 255.f,	1.f};
const ColorFA mediumTurquoise		{72 / 255.f,	209 / 255.f,	204 / 255.f,	1.f};
const ColorFA mediumVioletRed		{199 / 255.f,	21 / 255.f,		133 / 255.f,	1.f};
const ColorFA midnightBlue			{25 / 255.f,	25 / 255.f,		112 / 255.f,	1.f};
const ColorFA mintCream				{245 / 255.f,	255 / 255.f,	250 / 255.f,	1.f};
const ColorFA mistyRose				{255 / 255.f,	228 / 255.f,	225 / 255.f,	1.f};
const ColorFA moccasin				{255 / 255.f,	228 / 255.f,	181 / 255.f,	1.f};
const ColorFA navajoWhite			{255 / 255.f,	222 / 255.f,	173 / 255.f,	1.f};
const ColorFA navy					{0 / 255.f,		0 / 255.f,		128 / 255.f,	1.f};
const ColorFA oldLace				{253 / 255.f,	245 / 255.f,	230 / 255.f,	1.f};
const ColorFA olive					{128 / 255.f,	128 / 255.f,	0 / 255.f,		1.f};
const ColorFA oliveDrab				{107 / 255.f,	142 / 255.f,	35 / 255.f,		1.f};
const ColorFA orange				{255 / 255.f,	165 / 255.f,	0 / 255.f,		1.f};
const ColorFA orangeRed				{255 / 255.f,	69 / 255.f,		0 / 255.f,		1.f};
const ColorFA orchid				{218 / 255.f,	112 / 255.f,	214 / 255.f,	1.f};
const ColorFA paleGoldenRod			{238 / 255.f,	232 / 255.f,	170 / 255.f,	1.f};
const ColorFA paleGreen				{152 / 255.f,	251 / 255.f,	152 / 255.f,	1.f};
const ColorFA paleTurquoise			{175 / 255.f,	238 / 255.f,	238 / 255.f,	1.f};
const ColorFA paleVioletRed			{219 / 255.f,	112 / 255.f,	147 / 255.f,	1.f};
const ColorFA papayaWhip			{255 / 255.f,	239 / 255.f,	213 / 255.f,	1.f};
const ColorFA peachPuff				{255 / 255.f,	218 / 255.f,	185 / 255.f,	1.f};
const ColorFA peru					{205 / 255.f,	133 / 255.f,	63 / 255.f,		1.f};
const ColorFA pink					{255 / 255.f,	192 / 255.f,	203 / 255.f,	1.f};
const ColorFA plum					{221 / 255.f,	160 / 255.f,	221 / 255.f,	1.f};
const ColorFA powderBlue			{176 / 255.f,	224 / 255.f,	230 / 255.f,	1.f};
const ColorFA purple				{128 / 255.f,	0 / 255.f,		128 / 255.f,	1.f};
const ColorFA rebeccaPurple			{102 / 255.f,	51 / 255.f,		153 / 255.f,	1.f};
const ColorFA rosyBrown				{188 / 255.f,	143 / 255.f,	143 / 255.f,	1.f};
const ColorFA royalBlue				{65 / 255.f,	105 / 255.f,	225 / 255.f,	1.f};
const ColorFA saddleBrown			{139 / 255.f,	69 / 255.f,		19 / 255.f,		1.f};
const ColorFA salmon				{250 / 255.f,	128 / 255.f,	114 / 255.f,	1.f};
const ColorFA sandyBrown			{244 / 255.f,	164 / 255.f,	96 / 255.f,		1.f};
const ColorFA seaGreen				{46 / 255.f,	139 / 255.f,	87 / 255.f,		1.f};
const ColorFA seaShell				{255 / 255.f,	245 / 255.f,	238 / 255.f,	1.f};
const ColorFA sienna				{160 / 255.f,	82 / 255.f,		45 / 255.f,		1.f};
const ColorFA silver				{192 / 255.f,	192 / 255.f,	192 / 255.f,	1.f};
const ColorFA skyBlue				{135 / 255.f,	206 / 255.f,	235 / 255.f,	1.f};
const ColorFA slateBlue				{106 / 255.f,	90 / 255.f,		205 / 255.f,	1.f};
const ColorFA slateGrey				{112 / 255.f,	128 / 255.f,	144 / 255.f,	1.f};
const ColorFA snow					{255 / 255.f,	250 / 255.f,	250 / 255.f,	1.f};
const ColorFA springGreen			{0 / 255.f,		255 / 255.f,	127 / 255.f,	1.f};
const ColorFA steelBlue				{70 / 255.f,	130 / 255.f,	180 / 255.f,	1.f};
const ColorFA tan					{210 / 255.f,	180 / 255.f,	140 / 255.f,	1.f};
const ColorFA teal					{0 / 255.f,		128 / 255.f,	128 / 255.f,	1.f};
const ColorFA thistle				{216 / 255.f,	191 / 255.f,	216 / 255.f,	1.f};
const ColorFA tomato				{255 / 255.f,	99 / 255.f,		71 / 255.f,		1.f};
const ColorFA turquoise				{64 / 255.f,	224 / 255.f,	208 / 255.f,	1.f};
const ColorFA violet				{238 / 255.f,	130 / 255.f,	238 / 255.f,	1.f};
const ColorFA wheat					{245 / 255.f,	222 / 255.f,	179 / 255.f,	1.f};
const ColorFA whiteSmoke			{245 / 255.f,	245 / 255.f,	245 / 255.f,	1.f};
const ColorFA yellowGreen			{154 / 255.f,	205 / 255.f,	50 / 255.f,		1.f};

//  _______________
// | NAMESPACE END |	// colorFA
//  ***************
}

//=============================================================================
namespace colorRGB {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
const ColorRGB black				{0,		0,		0};
const ColorRGB white				{255,	255,	255};

const ColorRGB red					{255,	0,		0};
const ColorRGB lime					{0,		255,	0};
const ColorRGB blue					{0,		0,		255};

const ColorRGB yellow				{255,	255,	0};
const ColorRGB magenta				{255,	0,		255};
const ColorRGB cyan					{0,		255,	255};

//=============================================================================
const ColorRGB aliceBlue			{240,	248,	255};
const ColorRGB antiqueWhite			{250,	235,	215};
const ColorRGB aqua					{0,		255,	255};
const ColorRGB aquamarine			{127,	255,	212};
const ColorRGB azure				{240,	255,	255};
const ColorRGB beige				{245,	245,	220};
const ColorRGB bisque				{255,	228,	196};
const ColorRGB blanchedAlmond		{255,	235,	205};
const ColorRGB blueViolet			{138,	43,		226};
const ColorRGB brown				{165,	42,		42};
const ColorRGB burlyWood			{222,	184,	135};
const ColorRGB cadetBlue			{95,	158,	160};
const ColorRGB chartreuse			{127,	255,	0};
const ColorRGB chocolate			{210,	105,	30};
const ColorRGB coral				{255,	127,	80};
const ColorRGB cornflowerBlue		{100,	149,	237,};
const ColorRGB cornsilk				{255,	248,	220};
const ColorRGB crimson				{220,	20,		60};
const ColorRGB darkBlue				{0,		0,		139};
const ColorRGB darkCyan				{0,		139,	139};
const ColorRGB darkGoldenRod		{184,	134,	11};
const ColorRGB darkGrey				{169,	169,	169};
const ColorRGB darkGreen			{0,		100,	0};
const ColorRGB darkKhaki			{189,	183,	107};
const ColorRGB darkMagenta			{139,	0,		139};
const ColorRGB darkOliveGreen		{85,	107,	47};
const ColorRGB darkOrange			{255,	140,	0};
const ColorRGB darkOrchid			{153,	50,		204};
const ColorRGB darkRed				{139,	0,		0};
const ColorRGB darkSalmon			{233,	150,	122};
const ColorRGB darkSeaGreen			{143,	188,	143};
const ColorRGB darkSlateBlue		{72,	61,		139};
const ColorRGB darkSlateGrey		{47,	79,		79};
const ColorRGB darkTurquoise		{0,		206,	209};
const ColorRGB darkViolet			{148,	0,		211};
const ColorRGB deepPink				{255,	20,		147};
const ColorRGB deepSkyBlue			{0,		191,	255};
const ColorRGB dimGrey				{105,	105,	105};
const ColorRGB dodgerBlue			{30,	144,	255};
const ColorRGB fireBrick			{178,	34,		34};
const ColorRGB floralWhite			{255,	250,	240};
const ColorRGB forestGreen			{34,	139,	34};
const ColorRGB fuchsia				{255,	0,		255};
const ColorRGB gainsboro			{220,	220,	220};
const ColorRGB ghostWhite			{248,	248,	255};
const ColorRGB gold					{255,	215,	0};
const ColorRGB goldenRod			{218,	165,	32};
const ColorRGB grey					{128,	128,	128};
const ColorRGB green				{0,		128,	0};
const ColorRGB greenYellow			{173,	255,	47};
const ColorRGB honeyDew				{240,	255,	240};
const ColorRGB hotPink				{255,	105,	180};
const ColorRGB indianRed			{205,	92,		92};
const ColorRGB indigo				{75,	0,		130};
const ColorRGB ivory				{255,	255,	240};
const ColorRGB khaki				{240,	230,	140};
const ColorRGB lavender				{230,	230,	250};
const ColorRGB lavenderBlush		{255,	240,	245};
const ColorRGB lawnGreen			{124,	252,	0};
const ColorRGB lemonChiffon			{255,	250,	205};
const ColorRGB lightBlue			{173,	216,	230};
const ColorRGB lightCoral			{240,	128,	128};
const ColorRGB lightCyan			{224,	255,	255};
const ColorRGB lightGoldenRodYellow	{250,	250,	210};
const ColorRGB lightGrey			{211,	211,	211};
const ColorRGB lightGreen			{144,	238,	144};
const ColorRGB lightPink			{255,	182,	193};
const ColorRGB lightSalmon			{255,	160,	122};
const ColorRGB lightSeaGreen		{32,	178,	170};
const ColorRGB lightSkyBlue			{135,	206,	250};
const ColorRGB lightSlateGrey		{119,	136,	153};
const ColorRGB lightSteelBlue		{176,	196,	222};
const ColorRGB lightYellow			{255,	255,	224};
const ColorRGB limeGreen			{50,	205,	50};
const ColorRGB linen				{250,	240,	230};
const ColorRGB maroon				{128,	0,		0};
const ColorRGB mediumAquaMarine		{102,	205,	170};
const ColorRGB mediumBlue			{0,		0,		205};
const ColorRGB mediumOrchid			{186,	85,		211};
const ColorRGB mediumPurple			{147,	112,	219};
const ColorRGB mediumSeaGreen		{60,	179,	113};
const ColorRGB mediumSlateBlue		{123,	104,	238};
const ColorRGB mediumSpringGreen	{0,		250,	154};
const ColorRGB mediumTurquoise		{72,	209,	204};
const ColorRGB mediumVioletRed		{199,	21,		133};
const ColorRGB midnightBlue			{25,	25,		112};
const ColorRGB mintCream			{245,	255,	250};
const ColorRGB mistyRose			{255,	228,	225};
const ColorRGB moccasin				{255,	228,	181};
const ColorRGB navajoWhite			{255,	222,	173};
const ColorRGB navy					{0,		0,		128};
const ColorRGB oldLace				{253,	245,	230};
const ColorRGB olive				{128,	128,	0};
const ColorRGB oliveDrab			{107,	142,	35};
const ColorRGB orange				{255,	165,	0};
const ColorRGB orangeRed			{255,	69,		0};
const ColorRGB orchid				{218,	112,	214};
const ColorRGB paleGoldenRod		{238,	232,	170};
const ColorRGB paleGreen			{152,	251,	152};
const ColorRGB paleTurquoise		{175,	238,	238};
const ColorRGB paleVioletRed		{219,	112,	147};
const ColorRGB papayaWhip			{255,	239,	213};
const ColorRGB peachPuff			{255,	218,	185};
const ColorRGB peru					{205,	133,	63};
const ColorRGB pink					{255,	192,	203};
const ColorRGB plum					{221,	160,	221};
const ColorRGB powderBlue			{176,	224,	230};
const ColorRGB purple				{128,	0,		128};
const ColorRGB rebeccaPurple		{102,	51,		153};
const ColorRGB rosyBrown			{188,	143,	143};
const ColorRGB royalBlue			{65,	105,	225};
const ColorRGB saddleBrown			{139,	69,		19};
const ColorRGB salmon				{250,	128,	114};
const ColorRGB sandyBrown			{244,	164,	96};
const ColorRGB seaGreen				{46,	139,	87};
const ColorRGB seaShell				{255,	245,	238};
const ColorRGB sienna				{160,	82,		45};
const ColorRGB silver				{192,	192,	192};
const ColorRGB skyBlue				{135,	206,	235};
const ColorRGB slateBlue			{106,	90,		205};
const ColorRGB slateGrey			{112,	128,	144};
const ColorRGB snow					{255,	250,	250};
const ColorRGB springGreen			{0,		255,	127};
const ColorRGB steelBlue			{70,	130,	180};
const ColorRGB tan					{210,	180,	140};
const ColorRGB teal					{0,		128,	128};
const ColorRGB thistle				{216,	191,	216};
const ColorRGB tomato				{255,	99,		71};
const ColorRGB turquoise			{64,	224,	208};
const ColorRGB violet				{238,	130,	238};
const ColorRGB wheat				{245,	222,	179};
const ColorRGB whiteSmoke			{245,	245,	245};
const ColorRGB yellowGreen			{154,	205,	50};

//  _______________
// | NAMESPACE END |	// colorRGB
//  ***************
}

//=============================================================================
namespace colorRGBA {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
const ColorRGBA black					{0,		0,		0,		255};
const ColorRGBA white					{255,	255,	255,	255};

const ColorRGBA red						{255,	0,		0,		255};
const ColorRGBA lime					{0,		255,	0,		255};
const ColorRGBA blue					{0,		0,		255,	255};

const ColorRGBA yellow					{255,	255,	0,		255};
const ColorRGBA magenta					{255,	0,		255,	255};
const ColorRGBA cyan					{0,		255,	255,	255};

//=============================================================================
const ColorRGBA aliceBlue				{240,	248,	255,	255};
const ColorRGBA antiqueWhite			{250,	235,	215,	255};
const ColorRGBA aqua					{0,		255,	255,	255};
const ColorRGBA aquamarine				{127,	255,	212,	255};
const ColorRGBA azure					{240,	255,	255,	255};
const ColorRGBA beige					{245,	245,	220,	255};
const ColorRGBA bisque					{255,	228,	196,	255};
const ColorRGBA blanchedAlmond			{255,	235,	205,	255};
const ColorRGBA blueViolet				{138,	43,		226,	255};
const ColorRGBA brown					{165,	42,		42,		255};
const ColorRGBA burlyWood				{222,	184,	135,	255};
const ColorRGBA cadetBlue				{95,	158,	160,	255};
const ColorRGBA chartreuse				{127,	255,	0,		255};
const ColorRGBA chocolate				{210,	105,	30,		255};
const ColorRGBA coral					{255,	127,	80,		255};
const ColorRGBA cornflowerBlue			{100,	149,	237,	255};
const ColorRGBA cornsilk				{255,	248,	220,	255};
const ColorRGBA crimson					{220,	20,		60,		255};
const ColorRGBA darkBlue				{0,		0,		139,	255};
const ColorRGBA darkCyan				{0,		139,	139,	255};
const ColorRGBA darkGoldenRod			{184,	134,	11,		255};
const ColorRGBA darkGrey				{169,	169,	169,	255};
const ColorRGBA darkGreen				{0,		100,	0,		255};
const ColorRGBA darkKhaki				{189,	183,	107,	255};
const ColorRGBA darkMagenta				{139,	0,		139,	255};
const ColorRGBA darkOliveGreen			{85,	107,	47,		255};
const ColorRGBA darkOrange				{255,	140,	0,		255};
const ColorRGBA darkOrchid				{153,	50,		204,	255};
const ColorRGBA darkRed					{139,	0,		0,		255};
const ColorRGBA darkSalmon				{233,	150,	122,	255};
const ColorRGBA darkSeaGreen			{143,	188,	143,	255};
const ColorRGBA darkSlateBlue			{72,	61,		139,	255};
const ColorRGBA darkSlateGrey			{47,	79,		79,		255};
const ColorRGBA darkTurquoise			{0,		206,	209,	255};
const ColorRGBA darkViolet				{148,	0,		211,	255};
const ColorRGBA deepPink				{255,	20,		147,	255};
const ColorRGBA deepSkyBlue				{0,		191,	255,	255};
const ColorRGBA dimGrey					{105,	105,	105,	255};
const ColorRGBA dodgerBlue				{30,	144,	255,	255};
const ColorRGBA fireBrick				{178,	34,		34,		255};
const ColorRGBA floralWhite				{255,	250,	240,	255};
const ColorRGBA forestGreen				{34,	139,	34,		255};
const ColorRGBA fuchsia					{255,	0,		255,	255};
const ColorRGBA gainsboro				{220,	220,	220,	255};
const ColorRGBA ghostWhite				{248,	248,	255,	255};
const ColorRGBA gold					{255,	215,	0,		255};
const ColorRGBA goldenRod				{218,	165,	32,		255};
const ColorRGBA grey					{128,	128,	128,	255};
const ColorRGBA green					{0,		128,	0,		255};
const ColorRGBA greenYellow				{173,	255,	47,		255};
const ColorRGBA honeyDew				{240,	255,	240,	255};
const ColorRGBA hotPink					{255,	105,	180,	255};
const ColorRGBA indianRed				{205,	92,		92,		255};
const ColorRGBA indigo					{75,	0,		130,	255};
const ColorRGBA ivory					{255,	255,	240,	255};
const ColorRGBA khaki					{240,	230,	140,	255};
const ColorRGBA lavender				{230,	230,	250,	255};
const ColorRGBA lavenderBlush			{255,	240,	245,	255};
const ColorRGBA lawnGreen				{124,	252,	0,		255};
const ColorRGBA lemonChiffon			{255,	250,	205,	255};
const ColorRGBA lightBlue				{173,	216,	230,	255};
const ColorRGBA lightCoral				{240,	128,	128,	255};
const ColorRGBA lightCyan				{224,	255,	255,	255};
const ColorRGBA lightGoldenRodYellow	{250,	250,	210,	255};
const ColorRGBA lightGrey				{211,	211,	211,	255};
const ColorRGBA lightGreen				{144,	238,	144,	255};
const ColorRGBA lightPink				{255,	182,	193,	255};
const ColorRGBA lightSalmon				{255,	160,	122,	255};
const ColorRGBA lightSeaGreen			{32,	178,	170,	255};
const ColorRGBA lightSkyBlue			{135,	206,	250,	255};
const ColorRGBA lightSlateGrey			{119,	136,	153,	255};
const ColorRGBA lightSteelBlue			{176,	196,	222,	255};
const ColorRGBA lightYellow				{255,	255,	224,	255};
const ColorRGBA limeGreen				{50,	205,	50,		255};
const ColorRGBA linen					{250,	240,	230,	255};
const ColorRGBA maroon					{128,	0,		0,		255};
const ColorRGBA mediumAquaMarine		{102,	205,	170,	255};
const ColorRGBA mediumBlue				{0,		0,		205,	255};
const ColorRGBA mediumOrchid			{186,	85,		211,	255};
const ColorRGBA mediumPurple			{147,	112,	219,	255};
const ColorRGBA mediumSeaGreen			{60,	179,	113,	255};
const ColorRGBA mediumSlateBlue			{123,	104,	238,	255};
const ColorRGBA mediumSpringGreen		{0,		250,	154,	255};
const ColorRGBA mediumTurquoise			{72,	209,	204,	255};
const ColorRGBA mediumVioletRed			{199,	21,		133,	255};
const ColorRGBA midnightBlue			{25,	25,		112,	255};
const ColorRGBA mintCream				{245,	255,	250,	255};
const ColorRGBA mistyRose				{255,	228,	225,	255};
const ColorRGBA moccasin				{255,	228,	181,	255};
const ColorRGBA navajoWhite				{255,	222,	173,	255};
const ColorRGBA navy					{0,		0,		128,	255};
const ColorRGBA oldLace					{253,	245,	230,	255};
const ColorRGBA olive					{128,	128,	0,		255};
const ColorRGBA oliveDrab				{107,	142,	35,		255};
const ColorRGBA orange					{255,	165,	0,		255};
const ColorRGBA orangeRed				{255,	69,		0,		255};
const ColorRGBA orchid					{218,	112,	214,	255};
const ColorRGBA paleGoldenRod			{238,	232,	170,	255};
const ColorRGBA paleGreen				{152,	251,	152,	255};
const ColorRGBA paleTurquoise			{175,	238,	238,	255};
const ColorRGBA paleVioletRed			{219,	112,	147,	255};
const ColorRGBA papayaWhip				{255,	239,	213,	255};
const ColorRGBA peachPuff				{255,	218,	185,	255};
const ColorRGBA peru					{205,	133,	63,		255};
const ColorRGBA pink					{255,	192,	203,	255};
const ColorRGBA plum					{221,	160,	221,	255};
const ColorRGBA powderBlue				{176,	224,	230,	255};
const ColorRGBA purple					{128,	0,		128,	255};
const ColorRGBA rebeccaPurple			{102,	51,		153,	255};
const ColorRGBA rosyBrown				{188,	143,	143,	255};
const ColorRGBA royalBlue				{65,	105,	225,	255};
const ColorRGBA saddleBrown				{139,	69,		19,		255};
const ColorRGBA salmon					{250,	128,	114,	255};
const ColorRGBA sandyBrown				{244,	164,	96,		255};
const ColorRGBA seaGreen				{46,	139,	87,		255};
const ColorRGBA seaShell				{255,	245,	238,	255};
const ColorRGBA sienna					{160,	82,		45,		255};
const ColorRGBA silver					{192,	192,	192,	255};
const ColorRGBA skyBlue					{135,	206,	235,	255};
const ColorRGBA slateBlue				{106,	90,		205,	255};
const ColorRGBA slateGrey				{112,	128,	144,	255};
const ColorRGBA snow					{255,	250,	250,	255};
const ColorRGBA springGreen				{0,		255,	127,	255};
const ColorRGBA steelBlue				{70,	130,	180,	255};
const ColorRGBA tan						{210,	180,	140,	255};
const ColorRGBA teal					{0,		128,	128,	255};
const ColorRGBA thistle					{216,	191,	216,	255};
const ColorRGBA tomato					{255,	99,		71,		255};
const ColorRGBA turquoise				{64,	224,	208,	255};
const ColorRGBA violet					{238,	130,	238,	255};
const ColorRGBA wheat					{245,	222,	179,	255};
const ColorRGBA whiteSmoke				{245,	245,	245,	255};
const ColorRGBA yellowGreen				{154,	205,	50,		255};

//  _______________
// | NAMESPACE END |	// colorRGBA
//  ***************
}

//=============================================================================
namespace colorHex {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
const ColorHex black				{'0', '0', '0', '0', '0', '0'};		// #000000
const ColorHex white				{'F', 'F', 'F', 'F', 'F', 'F'};		// #FFFFFF

const ColorHex red					{'F', 'F', '0', '0', '0', '0'};		// #FF0000
const ColorHex lime					{'0', '0', 'F', 'F', '0', '0'};		// #00FF00
const ColorHex blue					{'0', '0', '0', '0', 'F', 'F'};		// #0000FF

const ColorHex yellow				{'F', 'F', 'F', 'F', '0', '0'};		// #FFFF00
const ColorHex magenta				{'F', 'F', '0', '0', 'F', 'F'};		// #FF00FF
const ColorHex cyan					{'0', '0', 'F', 'F', 'F', 'F'};		// #00FFFF

//=============================================================================
const ColorHex aliceBlue			{'F', '0', 'F', '8', 'F', 'F'};		// #F0F8FF
const ColorHex antiqueWhite			{'F', 'A', 'E', 'B', 'D', '7'};		// #FAEBD7
const ColorHex aqua					{'0', '0', 'F', 'F', 'F', 'F'};		// #00FFFF
const ColorHex aquamarine			{'7', 'F', 'F', 'F', 'D', '4'};		// #7FFFD4
const ColorHex azure				{'F', '0', 'F', 'F', 'F', 'F'};		// #F0FFFF
const ColorHex beige				{'F', '5', 'F', '5', 'D', 'C'};		// #F5F5DC
const ColorHex bisque				{'F', 'F', 'E', '4', 'C', '4'};		// #FFE4C4
const ColorHex blanchedAlmond		{'F', 'F', 'E', 'B', 'C', 'D'};		// #FFEBCD
const ColorHex blueViolet			{'8', 'A', '2', 'B', 'E', '2'};		// #8A2BE2
const ColorHex brown				{'A', '5', '2', 'A', '2', 'A'};		// #A52A2A
const ColorHex burlyWood			{'D', 'E', 'B', '8', '8', '7'};		// #DEB887
const ColorHex cadetBlue			{'5', 'F', '9', 'E', 'A', '0'};		// #5F9EA0
const ColorHex chartreuse			{'7', 'F', 'F', 'F', '0', '0'};		// #7FFF00
const ColorHex chocolate			{'D', '2', '6', '9', '1', 'E'};		// #D2691E
const ColorHex coral				{'F', 'F', '7', 'F', '5', '0'};		// #FF7F50
const ColorHex cornflowerBlue		{'6', '4', '9', '5', 'E', 'D'};		// #6495ED
const ColorHex cornsilk				{'F', 'F', 'F', '8', 'D', 'C'};		// #FFF8DC
const ColorHex crimson				{'D', 'C', '1', '4', '3', 'C'};		// #DC143C
const ColorHex darkBlue				{'0', '0', '0', '0', '8', 'B'};		// #00008B
const ColorHex darkCyan				{'0', '0', '8', 'B', '8', 'B'};		// #008B8B
const ColorHex darkGoldenRod		{'B', '8', '8', '6', '0', 'B'};		// #B8860B
const ColorHex darkGrey				{'A', '9', 'A', '9', 'A', '9'};		// #A9A9A9
const ColorHex darkGreen			{'0', '0', '6', '4', '0', '0'};		// #006400
const ColorHex darkKhaki			{'B', 'D', 'B', '7', '6', 'B'};		// #BDB76B
const ColorHex darkMagenta			{'8', 'B', '0', '0', '8', 'B'};		// #8B008B
const ColorHex darkOliveGreen		{'5', '5', '6', 'B', '2', 'F'};		// #556B2F
const ColorHex darkOrange			{'F', 'F', '8', 'C', '0', '0'};		// #FF8C00
const ColorHex darkOrchid			{'9', '9', '3', '2', 'C', 'C'};		// #9932CC
const ColorHex darkRed				{'8', 'B', '0', '0', '0', '0'};		// #8B0000
const ColorHex darkSalmon			{'E', '9', '9', '6', '7', 'A'};		// #E9967A
const ColorHex darkSeaGreen			{'8', 'F', 'B', 'C', '8', 'F'};		// #8FBC8F
const ColorHex darkSlateBlue		{'4', '8', '3', 'D', '8', 'B'};		// #483D8B
const ColorHex darkSlateGrey		{'2', 'F', '4', 'F', '4', 'F'};		// #2F4F4F
const ColorHex darkTurquoise		{'0', '0', 'C', 'E', 'D', '1'};		// #00CED1
const ColorHex darkViolet			{'9', '4', '0', '0', 'D', '3'};		// #9400D3
const ColorHex deepPink				{'F', 'F', '1', '4', '9', '3'};		// #FF1493
const ColorHex deepSkyBlue			{'0', '0', 'B', 'F', 'F', 'F'};		// #00BFFF
const ColorHex dimGrey				{'6', '9', '6', '9', '6', '9'};		// #696969
const ColorHex dodgerBlue			{'1', 'E', '9', '0', 'F', 'F'};		// #1E90FF
const ColorHex fireBrick			{'B', '2', '2', '2', '2', '2'};		// #B22222
const ColorHex floralWhite			{'F', 'F', 'F', 'A', 'F', '0'};		// #FFFAF0
const ColorHex forestGreen			{'2', '2', '8', 'B', '2', '2'};		// #228B22
const ColorHex fuchsia				{'F', 'F', '0', '0', 'F', 'F'};		// #FF00FF
const ColorHex gainsboro			{'D', 'C', 'D', 'C', 'D', 'C'};		// #DCDCDC
const ColorHex ghostWhite			{'F', '8', 'F', '8', 'F', 'F'};		// #F8F8FF
const ColorHex gold					{'F', 'F', 'D', '7', '0', '0'};		// #FFD700
const ColorHex goldenRod			{'D', 'A', 'A', '5', '2', '0'};		// #DAA520
const ColorHex grey					{'8', '0', '8', '0', '8', '0'};		// #808080
const ColorHex green				{'0', '0', '8', '0', '0', '0'};		// #008000
const ColorHex greenYellow			{'A', 'D', 'F', 'F', '2', 'F'};		// #ADFF2F
const ColorHex honeyDew				{'F', '0', 'F', 'F', 'F', '0'};		// #F0FFF0
const ColorHex hotPink				{'F', 'F', '6', '9', 'B', '4'};		// #FF69B4
const ColorHex indianRed			{'C', 'D', '5', 'C', '5', 'C'};		// #CD5C5C
const ColorHex indigo				{'4', 'B', '0', '0', '8', '2'};		// #4B0082
const ColorHex ivory				{'F', 'F', 'F', 'F', 'F', '0'};		// #FFFFF0
const ColorHex khaki				{'F', '0', 'E', '6', '8', 'C'};		// #F0E68C
const ColorHex lavender				{'E', '6', 'E', '6', 'F', 'A'};		// #E6E6FA
const ColorHex lavenderBlush		{'F', 'F', 'F', '0', 'F', '5'};		// #FFF0F5
const ColorHex lawnGreen			{'7', 'C', 'F', 'C', '0', '0'};		// #7CFC00
const ColorHex lemonChiffon			{'F', 'F', 'F', 'A', 'C', 'D'};		// #FFFACD
const ColorHex lightBlue			{'A', 'D', 'D', '8', 'E', '6'};		// #ADD8E6
const ColorHex lightCoral			{'F', '0', '8', '0', '8', '0'};		// #F08080
const ColorHex lightCyan			{'E', '0', 'F', 'F', 'F', 'F'};		// #E0FFFF
const ColorHex lightGoldenRodYellow	{'F', 'A', 'F', 'A', 'D', '2'};		// #FAFAD2
const ColorHex lightGrey			{'D', '3', 'D', '3', 'D', '3'};		// #D3D3D3
const ColorHex lightGreen			{'9', '0', 'E', 'E', '9', '0'};		// #90EE90
const ColorHex lightPink			{'F', 'F', 'B', '6', 'C', '1'};		// #FFB6C1
const ColorHex lightSalmon			{'F', 'F', 'A', '0', '7', 'A'};		// #FFA07A
const ColorHex lightSeaGreen		{'2', '0', 'B', '2', 'A', 'A'};		// #20B2AA
const ColorHex lightSkyBlue			{'8', '7', 'C', 'E', 'F', 'A'};		// #87CEFA
const ColorHex lightSlateGrey		{'7', '7', '8', '8', '9', '9'};		// #778899
const ColorHex lightSteelBlue		{'B', '0', 'C', '4', 'D', 'E'};		// #B0C4DE
const ColorHex lightYellow			{'F', 'F', 'F', 'F', 'E', '0'};		// #FFFFE0
const ColorHex limeGreen			{'3', '2', 'C', 'D', '3', '2'};		// #32CD32
const ColorHex linen				{'F', 'A', 'F', '0', 'E', '6'};		// #FAF0E6
const ColorHex maroon				{'8', '0', '0', '0', '0', '0'};		// #800000
const ColorHex mediumAquaMarine		{'6', '6', 'C', 'D', 'A', 'A'};		// #66CDAA
const ColorHex mediumBlue			{'0', '0', '0', '0', 'C', 'D'};		// #0000CD
const ColorHex mediumOrchid			{'B', 'A', '5', '5', 'D', '3'};		// #BA55D3
const ColorHex mediumPurple			{'9', '3', '7', '0', 'D', 'B'};		// #9370DB
const ColorHex mediumSeaGreen		{'3', 'C', 'B', '3', '7', '1'};		// #3CB371
const ColorHex mediumSlateBlue		{'7', 'B', '6', '8', 'E', 'E'};		// #7B68EE
const ColorHex mediumSpringGreen	{'0', '0', 'F', 'A', '9', 'A'};		// #00FA9A
const ColorHex mediumTurquoise		{'4', '8', 'D', '1', 'C', 'C'};		// #48D1CC
const ColorHex mediumVioletRed		{'C', '7', '1', '5', '8', '5'};		// #C71585
const ColorHex midnightBlue			{'1', '9', '1', '9', '7', '0'};		// #191970
const ColorHex mintCream			{'F', '5', 'F', 'F', 'F', 'A'};		// #F5FFFA
const ColorHex mistyRose			{'F', 'F', 'E', '4', 'E', '1'};		// #FFE4E1
const ColorHex moccasin				{'F', 'F', 'E', '4', 'B', '5'};		// #FFE4B5
const ColorHex navajoWhite			{'F', 'F', 'D', 'E', 'A', 'D'};		// #FFDEAD
const ColorHex navy					{'0', '0', '0', '0', '8', '0'};		// #000080
const ColorHex oldLace				{'F', 'D', 'F', '5', 'E', '6'};		// #FDF5E6
const ColorHex olive				{'8', '0', '8', '0', '0', '0'};		// #808000
const ColorHex oliveDrab			{'6', 'B', '8', 'E', '2', '3'};		// #6B8E23
const ColorHex orange				{'F', 'F', 'A', '5', '0', '0'};		// #FFA500
const ColorHex orangeRed			{'F', 'F', '4', '5', '0', '0'};		// #FF4500
const ColorHex orchid				{'D', 'A', '7', '0', 'D', '6'};		// #DA70D6
const ColorHex paleGoldenRod		{'E', 'E', 'E', '8', 'A', 'A'};		// #EEE8AA
const ColorHex paleGreen			{'9', '8', 'F', 'B', '9', '8'};		// #98FB98
const ColorHex paleTurquoise		{'A', 'F', 'E', 'E', 'E', 'E'};		// #AFEEEE
const ColorHex paleVioletRed		{'D', 'B', '7', '0', '9', '3'};		// #DB7093
const ColorHex papayaWhip			{'F', 'F', 'E', 'F', 'D', '5'};		// #FFEFD5
const ColorHex peachPuff			{'F', 'F', 'D', 'A', 'B', '9'};		// #FFDAB9
const ColorHex peru					{'C', 'D', '8', '5', '3', 'F'};		// #CD853F
const ColorHex pink					{'F', 'F', 'C', '0', 'C', 'B'};		// #FFC0CB
const ColorHex plum					{'D', 'D', 'A', '0', 'D', 'D'};		// #DDA0DD
const ColorHex powderBlue			{'B', '0', 'E', '0', 'E', '6'};		// #B0E0E6
const ColorHex purple				{'8', '0', '0', '0', '8', '0'};		// #800080
const ColorHex rebeccaPurple		{'6', '6', '3', '3', '9', '9'};		// #663399
const ColorHex rosyBrown			{'B', 'C', '8', 'F', '8', 'F'};		// #BC8F8F
const ColorHex royalBlue			{'4', '1', '6', '9', 'E', '1'};		// #4169E1
const ColorHex saddleBrown			{'8', 'B', '4', '5', '1', '3'};		// #8B4513
const ColorHex salmon				{'F', 'A', '8', '0', '7', '2'};		// #FA8072
const ColorHex sandyBrown			{'F', '4', 'A', '4', '6', '0'};		// #F4A460
const ColorHex seaGreen				{'2', 'E', '8', 'B', '5', '7'};		// #2E8B57
const ColorHex seaShell				{'F', 'F', 'F', '5', 'E', 'E'};		// #FFF5EE
const ColorHex sienna				{'A', '0', '5', '2', '2', 'D'};		// #A0522D
const ColorHex silver				{'C', '0', 'C', '0', 'C', '0'};		// #C0C0C0
const ColorHex skyBlue				{'8', '7', 'C', 'E', 'E', 'B'};		// #87CEEB
const ColorHex slateBlue			{'6', 'A', '5', 'A', 'C', 'D'};		// #6A5ACD
const ColorHex slateGrey			{'7', '0', '8', '0', '9', '0'};		// #708090
const ColorHex snow					{'F', 'F', 'F', 'A', 'F', 'A'};		// #FFFAFA
const ColorHex springGreen			{'0', '0', 'F', 'F', '7', 'F'};		// #00FF7F
const ColorHex steelBlue			{'4', '6', '8', '2', 'B', '4'};		// #4682B4
const ColorHex tan					{'D', '2', 'B', '4', '8', 'C'};		// #D2B48C
const ColorHex teal					{'0', '0', '8', '0', '8', '0'};		// #008080
const ColorHex thistle				{'D', '8', 'B', 'F', 'D', '8'};		// #D8BFD8
const ColorHex tomato				{'F', 'F', '6', '3', '4', '7'};		// #FF6347
const ColorHex turquoise			{'4', '0', 'E', '0', 'D', '0'};		// #40E0D0
const ColorHex violet				{'E', 'E', '8', '2', 'E', 'E'};		// #EE82EE
const ColorHex wheat				{'F', '5', 'D', 'E', 'B', '3'};		// #F5DEB3
const ColorHex whiteSmoke			{'F', '5', 'F', '5', 'F', '5'};		// #F5F5F5
const ColorHex yellowGreen			{'9', 'A', 'C', 'D', '3', '2'};		// #9ACD32

//  _______________
// | NAMESPACE END |	// colorHex
//  ***************
}

//  _______________
// | NAMESPACE END |	// color
//  ***************
}

//  _______________
// | NAMESPACE END |	// vGFX
//  ***************
}
