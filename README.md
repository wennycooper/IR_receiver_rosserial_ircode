# IR_receiver_rosserial_ircode

IR receiver which only received NEC code 0x77E14050 and publish to ROS topic /irCode

# Note
You have to import follow library into sketchbook/libraries

rm -rf ~/Arduino/libraries/IRremote
git clone https://github.com/z3t0/Arduino-IRremote.git
mv Arduino-IRremote
cp -r IRremote Arduino/libraries

