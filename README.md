guidev2
=======

Using an IDE other than QT Creator
==================================

If you want to use an IDE other than QT Creator you have to do some manual steps to get everything up and running. The xcode project file for Mac OS X is already setup and can be used without bothering with the following step. In other IDEs you need to add a script similiar to the following one running prior to compiling and linking. The script creates the moc file for the signal and slots before compiling. 

${HOME}/Qt5.0.1/5.0.1/clang_64/bin/moc ${INPUT_FILE_PATH} -f -o ${INPUT_FILE_DIR}/${INPUT_FILE_BASE}_moc.cpp

