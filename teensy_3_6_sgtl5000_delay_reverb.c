#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=111,335
AudioEffectDelay         delay1;         //xy=263,161
AudioEffectDelay         delay2;         //xy=263,421
AudioMixer4              mixer2;         //xy=434,301
AudioMixer4              mixer1;         //xy=435,209
AudioEffectReverb        reverb2;        //xy=572,301
AudioEffectReverb        reverb1;        //xy=573,209
AudioOutputI2S           i2s2;           //xy=622,252
AudioConnection          patchCord1(i2s1, 0, delay1, 0);
AudioConnection          patchCord2(i2s1, 0, mixer1, 1);
AudioConnection          patchCord3(i2s1, 1, delay2, 0);
AudioConnection          patchCord4(i2s1, 1, mixer2, 0);
AudioConnection          patchCord5(delay1, 0, mixer1, 0);
AudioConnection          patchCord6(delay2, 0, mixer2, 1);
AudioConnection          patchCord7(mixer2, 0, i2s2, 1);
AudioConnection          patchCord8(mixer1, 0, i2s2, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=116,51
// GUItool: end automatically generated code

int max_mem = 0;

void setup() {
  Serial.begin(115200);
  AudioMemory(128);
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.volume(0.8);
  delay1.delay(0, 200);
  delay2.delay(0, 200);
  mixer1.gain(0, 1.0);
  mixer1.gain(1, 0.6);
  mixer2.gain(0, 1.0);
  mixer2.gain(1, 0.6);
  reverb1.reverbTime(2);
  reverb2.reverbTime(2);

  delay1.disable(1);
  delay1.disable(2);
  delay1.disable(3);
  delay1.disable(4);
  delay1.disable(5);
  delay1.disable(6);
  delay1.disable(7);

  delay2.disable(1);
  delay2.disable(2);
  delay2.disable(3);
  delay2.disable(4);
  delay2.disable(5);
  delay2.disable(6);
  delay2.disable(7);

  mixer1.gain(2, 0);
  mixer1.gain(3, 0);
  mixer2.gain(2, 0);
  mixer2.gain(3, 0);
}

void loop() {
  if (AudioMemoryUsageMax() > max_mem) {
    max_mem = AudioMemoryUsageMax();
    Serial.print("Max memory used: ");
    Serial.println(max_mem);
  }
}