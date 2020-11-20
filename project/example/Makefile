#/************************************************************************************
#***
#***	Copyright 2020 Dell(18588220928g@163.com), All Rights Reserved.
#***
#***	File Author: Dell, 2020-11-20 16:51:50
#***
#************************************************************************************/
#
INSTALL_DIR := /usr/local/bin

TARGET := bm3d

SOURCE :=  \
	main.c

INCS	:= -I..
	#  -I$(BUILD_DIR)/include
LIBS	:= -L.. -lbm3d -L/usr/local/cuda/lib64 -lcufft -lcudart -lnimage -ljpeg -lpng -lm
	#-L$(BUILD_DIR)/lib -lstd... -lstdc++

DEFINES :=

# CFLAGS := -O2 -fPIC -Wall -Wextra
CXXFLAGS := -O2 -fPIC -Wall -Wextra --std=c++11
LDFLAGS := -fPIC

#****************************************************************************
# Makefile code common to all platforms
#****************************************************************************
CFLAGS   := ${CFLAGS} ${DEFINES}
CXXFLAGS := ${CXXFLAGS} ${DEFINES}

OBJECT := $(addsuffix .o,$(basename ${SOURCE}))

#****************************************************************************
# Compile block
#****************************************************************************
all: ${TARGET}

${TARGET}: ${OBJECT}
	${CXX} ${LDFLAGS} -o ${TARGET} ${OBJECT} ${LIBS}

main.o: main.c
	${CXX} ${CXXFLAGS} ${INCS} -c $< -o $@

install:
	install -m 755 ${TARGET} ${INSTALL_DIR}/bin



#****************************************************************************
# Depend block
#****************************************************************************
depend:

clean:
	rm -f core ${OBJECT} ${TARGET}
