# IR_receiver_rosserial_ircode

IR receiver which accept only RC5 code 0x43 and publish to ROS topic /irCode

# Note
You have to import follow library into sketchbook/libraries

rm -rf ~/Arduino/libraries/IRremote
git clone https://github.com/Neco777/Arduino-IRremote.git
mv Arduino-IRremote
cp -r IRremote Arduino/libraries

