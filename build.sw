# build.sw
# custom build system
libs = -lraylib -Limgui -Iimgui @sfml-all -limgui

run g++ main.cpp -o main $libs -Wfatal-errors
echo done
