#pragma once

//=============================================================================
namespace vMIDI {
//  _________________
// | NAMESPACE BEGIN |
//  *****************

//=============================================================================
enum class Type
{
	None,

	MIDI,
	SysEx,
	Meta
};

enum class SpecificType
{
	None,

	// MIDI
	NoteOff,
	NoteOn,
	PolyphonicPressure,
	Controller,
	ProgramChange,
	ChannelPressure,
	PitchBend,

	// SysEx
	SingleSysEx,
	EscapeSequence,

	// Meta
	SequenceNumber,
	Text,
	Copyright,
	TrackName,
	InstrumentName,
	Lyric,
	Marker,
	CuePoint,
	ProgramName,
	DeviceName,
	MidiChannelPrefix,
	MidiPort,
	EndOfTrack,
	Tempo,
	SMPTEOffset,
	TimeSignature,
	KeySignature,
	SequencerSpecificEvent
};

//  _______________
// | NAMESPACE END |
//  ***************
}