# build.sw
# custom build system
libs = -lraylib -Limgui -Iimgui -limgui @sfml-all

run g++ main.cpp -o main $libs -Wfatal-errors
echo done
