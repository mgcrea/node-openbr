https://github.com/nodejs/node-addon-examples/
https://nodejs.org/api/addons.html
https://github.com/nodejs/nan/tree/master/examples/async_pi_estimate

docker run --name test_openbr -it --rm mgcrea/node-openbr:1.1.0 /bin/bash

https://github.com/biometrics/openbr/blob/master/app/examples/age_estimation.cpp


### All build flags

```
app/br/CMakeFiles/br.dir/flags.make:CXX_FLAGS =  -Wall -Wextra -Wno-strict-overflow -Wno-comment -Wno-unknown-pragmas -fvisibility=hidden -fno-omit-frame-pointer -O3 -DNDEBUG -fPIE
-I"/usr/local/openbr/."
-I"/usr/local/include/opencv"
-I"/usr/local/include"
-I"/usr/local/openbr/3rdparty/alphanum"
-I"/usr/local/openbr/3rdparty/RandomLib-1.9/include"
-isystem "/usr/include/x86_64-linux-gnu/qt5",
-isystem "/usr/include/x86_64-linux-gnu/qt5/QtConcurrent",
-isystem "/usr/include/x86_64-linux-gnu/qt5/QtCore",
-isystem "/usr/include/x86_64-linux-gnu/qt5/QtGui",
-isystem "/usr/include/x86_64-linux-gnu/qt5/QtNetwork",
-isystem "/usr/include/x86_64-linux-gnu/qt5/QtSql",
-isystem "/usr/include/x86_64-linux-gnu/qt5/QtWidgets",
-isystem "/usr/include/x86_64-linux-gnu/qt5/QtXml  ",
-isystem /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64
app/br/CMakeFiles/br.dir/DependInfo.cmake:  "/usr/local/include/opencv"
```
