#pragma once

#include <string>
#include <array>

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
// Notes are numbered from 0 (0x00) to 127 (0x7F)
enum class Note
{
	None,

	Cn2, Cs_Dbn2, Dn2, Ds_Ebn2, En2, Fn2,
	Fs_Gbn2, Gn2, Gs_Abn2, An2, As_Bbn2, Bn2,

	Cn1, Cs_Dbn1, Dn1, Ds_Ebn1, En1, Fn1,
	Fs_Gbn1, Gn1, Gs_Abn1, An1, As_Bbn1, Bn1,

	C0, Cs_Db0, D0, Ds_Eb0, E0, F0,
	Fs_Gb0, G0, Gs_Ab0, A0, As_Bb0, B0,

	C1, Cs_Db1, D1, Ds_Eb1, E1, F1,
	Fs_Gb1, G1, Gs_Ab1, A1, As_Bb1, B1,

	C2, Cs_Db2, D2, Ds_Eb2, E2, F2,
	Fs_Gb2, G2, Gs_Ab2, A2, As_Bb2, B2,

	C3, Cs_Db3, D3, Ds_Eb3, E3, F3,
	Fs_Gb3, G3, Gs_Ab3, A3, As_Bb3, B3,

	C4, Cs_Db4, D4, Ds_Eb4, E4, F4,
	Fs_Gb4, G4, Gs_Ab4, A4, As_Bb4, B4,

	C5, Cs_Db5, D5, Ds_Eb5, E5, F5,
	Fs_Gb5, G5, Gs_Ab5, A5, As_Bb5, B5,

	C6, Cs_Db6, D6, Ds_Eb6, E6, F6,
	Fs_Gb6, G6, Gs_Ab6, A6, As_Bb6, B6,

	C7, Cs_Db7, D7, Ds_Eb7, E7, F7,
	Fs_Gb7, G7, Gs_Ab7, A7, As_Bb7, B7,

	C8, Cs_Db8, D8, Ds_Eb8, E8, F8,
	Fs_Gb8, G8
};

const std::array<std::string, 128> noteNames
{
	"C-2", "C#/Db-2", "D-2", "D#/Eb-2", "E-2", "F-2",
	"F#/Gb-2", "G-2", "G#/Ab-2", "A-2", "A#/Bb-2", "B-2",

	"C-1", "C#/Db-1", "D-1", "D#/Eb-1", "E-1", "F-1",
	"F#/Gb-1", "G-1", "G#/Ab-1", "A-1", "A#/Bb-1", "B-1",

	"C0", "C#/Db0", "D0", "D#/Eb0", "E0", "F0",
	"F#/Gb0", "G0", "G#/Ab0", "A0", "A#/Bb0", "B0",

	"C1", "C#/Db1", "D1", "D#/Eb1", "E1", "F1",
	"F#/Gb1", "G1", "G#/Ab1", "A1", "A#/Bb1", "B1",

	"C2", "C#/Db2", "D2", "D#/Eb2", "E2", "F2",
	"F#/Gb2", "G2", "G#/Ab2", "A2", "A#/Bb2", "B2",

	"C3", "C#/Db3", "D3", "D#/Eb3", "E3", "F3",
	"F#/Gb3", "G3", "G#/Ab3", "A3", "A#/Bb3", "B3",

	"C4", "C#/Db4", "D4", "D#/Eb4", "E4", "F4",
	"F#/Gb4", "G4", "G#/Ab4", "A4", "A#/Bb4", "B4",

	"C5", "C#/Db5", "D5", "D#/Eb5", "E5", "F5",
	"F#/Gb5", "G5", "G#/Ab5", "A5", "A#/Bb5", "B5",

	"C6", "C#/Db6", "D6", "D#/Eb6", "E6", "F6",
	"F#/Gb6", "G6", "G#/Ab6", "A6", "A#/Bb6", "B6",

	"C7", "C#/Db7", "D7", "D#/Eb7", "E7", "F7",
	"F#/Gb7", "G7", "G#/Ab7", "A7", "A#/Bb7", "B7",

	"C8", "C#/Db8", "D8", "D#/Eb8", "E8", "F8",
	"F#/Gb8", "G8"
};

//  _______________
// | NAMESPACE END |	// vMIDI
//  ***************
}