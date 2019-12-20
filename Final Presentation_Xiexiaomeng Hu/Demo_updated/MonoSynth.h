#pragma once

#include "MIDI.h"
#include "Wavetable.h"
#include "Envelope.h"

#define kNoteDuration 1

typedef struct Delay {
  float *buffer;
  unsigned long size;
  unsigned long readPosition;
  unsigned long writePosition;
  float time;
  float feedback;
  float dryWet;
} Delay;

typedef struct Synth {
  Wavetable *wavetable;
  Envelope *envelope;
  MIDIStream *midiStream;
  MIDIEvent midiEvent;
  Delay *delay;
} Synth;

// Function Prototypes
int initSynth(Synth *synth);
void closeSynth(Synth *synth);