from pocketsphinx import LiveSpeech
import serial


arduinoData = serial.Serial('com6',9600)
speech = LiveSpeech(lm=False, keyphrase='shot', kws_threshold=1e-10)

for phrase in speech:

	arduinoData.write(b'1')
	print(phrase.segments(detailed=True))