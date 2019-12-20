# EP-353: Audio Programming in C (Fall 2019)

Final Project: Building a synthesizer with basic audio effects using PortAudio and PortMIDI in C.

As I mentioned in the readme file, due to my limited syntex knowledge in C. This project is heavily based on the template provide from class. So the design document basically is my review of the course materials.

The digital synthesizer include several c files: Audio, MIDI, Envelope, Wavetable, Synth, and Main function. Here is my understanding of those files:

The audio.c configures all the port audio input and output streaming setups; as well as open port audio straming on the computer, so that the user can hear what's coming out from the synthesizer.

The MIDI.c recoginize all the port MIDI devices available and hold each MIDI events happened durling the synth process. It also initialize port MIDI to receive MIDI input and and send MIDI output.

The Wavetable.c contains the basic waveforms that can be generated from the synthesizer, it records all the nessasary parameters of the waveforms such as amplitude, frequency, sampling rate, ktablesize,etc. It determines the orginal raw sound that first comes out from the digital synthesizer. 

The Envelope.c determines the how the generated waveform will be outputed as audio signal, following the basic ADSR format, how fast will the signal reach to the peak level, and how fast does it decay to the sustain level, and how fast does the signal amplitude reach to zero. One thing I'm not too sure about is the duration of the envelope, since I know sustain level is more of a status and can have varies time period.

The Monosynth.c basically contains a typedef struct that receive parameters from the wavetable.c, MIDI.c and Envelope.C file, it basically initialize and close the synthesizer part of the code when the code is running and received a MIDI message. 

Main.c integrate every single part of the synthesizer, starting from initizalizing the synthesizer, detecting portAudio devices, open audio stream, receive MIDI inputs, set frequency, triggering synthesizer, and follows the envelope. 

The Makefile basically serves as a fast compiler of audio.c MIDI.c wavetable.c, envolope.c monosynth.c and main.c, so that user don't have to manually compiler every section for several times. 