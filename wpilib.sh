sudo apt-add-repository ppa:wpilib/toolchain
sudo apt update
sudo apt-get install cmake build-essential git doxygen frc-toolchain unzip


cd ~
mkdir wpilib_process
cd wpilib_process
wget http://first.wpi.edu/FRC/roborio/release/eclipse/plugins/edu.wpi.first.wpilib.plugins.cpp_0.1.0.201603020231.jar
mv edu.wpi.first.wpilib.plugins.cpp_0.1.0.201603020231.jar plugins.jar
# Update jarfile when nessecary
unzip plugins.jar
mv resources/cpp.zip cpp.zip
mkdir ~/wpilib
mkdir ~/wpilib/cpp
mkdir ~/wpilib/cpp/current
cd ~/wpilib/cpp/current
unzip ~/wpilib_process/cpp.zip

rm -rf ~/wpilib_process
