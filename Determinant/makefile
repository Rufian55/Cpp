#########################################################
# Author: Chris Kearns
# Date: 01/09/2016
# File: Makefile
# Description: makefile for CS162-400 (W2016).
# Edit the variables under "USER SECTION" as needed.
# To execute the makefile on unix-y systems, type 'make'.
# If that doesn't work, try 'make -f makefile'.
#########################################################

# #'s are line-comments 

# CXX is a standard variable name used for the compiler. 
CXX = g++

# CXXFLAGS is a standard variable name for compile flags.
# -std=c++0x specifies to use the latest language version.
CXXFLAGS = -std=c++0x

# -Wall turns on all warnings
CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files (.cpp). 
# Edit as needed.
SRC1 = ReadMatrix.cpp
SRC2 = Determinant.cpp
SRC3 = Main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

# HEADERS is a standard name for the header files (.hpp). 
# Edit as needed.
HEADER1 = ReadMatrix.hpp
HEADER2 = Determinant.hpp
# HEADER3 = 
HEADERS = ${HEADER1} ${HEADER2}

# Your executable files. 
# Edit as needed.
PROG1 = matrix
# PROG2 = 
# PROG3 = 
PROGS = ${PROG1}

# This is the name of your document(s). 
# Edit as needed.
# DOC = my_writeup.pdf

# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
TAR = cs162_Lab1_kearnsc.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build available.
# In this case, default.
default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
# Note: ${DOC} removed for this makefile.
# tar modifiers: c = create new archive, v = verbosely list each file as its compressed/extracted, j = read/write using the bzip2 compressor, f = use archive file ARCHIVE.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
# rm means remove file.
# -f means --force or you don't need access privelege to the file, only the parent directory and no "confirm remove" is offered.
# ${PROGS} means remove the executable file(s) specified above.
# *.o means remove the object files created by the compile process for linking.
# *~ means remove temp files. 
clean: 
	rm -f ${PROGS} *.o *~
