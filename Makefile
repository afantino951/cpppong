# Directories
S_DIR = source
B_DIR = build
I_DIR = include/

#OBJS specifies which files to compile as part of the project
OBJS = source/main.cpp source/ball.cpp

# Files
#   Need to get this to add all files in the source dir
S_FILES = $(S_DIR)/

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = $(B_DIR)/pong

# DEPS specifies the dependencies of our OBJ files
_DEPS = ball.h utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#CXX specifies which compiler we're using
CXX = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall -g -I ./include

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 `sdl2-config --cflags --libs`


#This is the target that compiles our executable
all : $(OBJS)
	$(CXX) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -rf $(B_DIR)/*

# # Build settings
# CC = g++
# CFLAGS = -g 
# # SDL options
# CC_SDL = -lSDL `sdl2-config --cflags --libs`


# all: Build

# Build:
# 	$(CC) $(CFLAGS) $(S_FILES) -o $(EXEC) $(CC_SDL)

# build_run: Build
# 	$(EXEC)


