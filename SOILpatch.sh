# DO NOT RUN THIS FILE 
# The Makefile will run it if needed

if [ -a /usr/include/SOIL/SOIL.h ]; then
	patch -i SOIL.patch
fi

