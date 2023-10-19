~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WINDOWS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

cmake --preset NinjaMC-Msvc -D BUILD_SHARED_LIBS=ON
cmake --build --preset NinjaMC-Msvc --config Debug --target run install
cmake --build --preset NinjaMC-Msvc --config Release --target run install
cmake --build --preset NinjaMC-Msvc --config RelWithDebInfo --target run install

cmake --preset NinjaMC-Msvc -D BUILD_SHARED_LIBS=OFF
cmake --build --preset NinjaMC-Msvc --config Debug --target run install
cmake --build --preset NinjaMC-Msvc --config Release --target run install
cmake --build --preset NinjaMC-Msvc --config RelWithDebInfo --target run install

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
LINUX
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

cmake --preset NinjaMC-Gnu -D BUILD_SHARED_LIBS=ON
cmake --build --preset NinjaMC-Gnu --config Debug --target run install
cmake --build --preset NinjaMC-Gnu --config Release --target run install
cmake --build --preset NinjaMC-Gnu --config RelWithDebInfo --target run install

cmake --preset NinjaMC-Gnu -D BUILD_SHARED_LIBS=OFF
cmake --build --preset NinjaMC-Gnu --config Debug --target run install
cmake --build --preset NinjaMC-Gnu --config Release --target run install
cmake --build --preset NinjaMC-Gnu --config RelWithDebInfo --target run install

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MAC
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

cmake --preset NinjaMC-Clang -D BUILD_SHARED_LIBS=ON
cmake --build --preset NinjaMC-Clang --config Debug --target run install
cmake --build --preset NinjaMC-Clang --config Release --target run install
cmake --build --preset NinjaMC-Clang --config RelWithDebInfo --target run install

cmake --preset NinjaMC-Clang -D BUILD_SHARED_LIBS=OFF
cmake --build --preset NinjaMC-Clang --config Debug --target run install
cmake --build --preset NinjaMC-Clang --config Release --target run install
cmake --build --preset NinjaMC-Clang --config RelWithDebInfo --target run install
