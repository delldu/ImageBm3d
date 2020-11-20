#/************************************************************************************
#***
#***	Copyright 2020 Dell(18588220928g@163.com), All Rights Reserved.
#***
#***	File Author: Dell, 2020-11-20 16:48:15
#***
#************************************************************************************/
#
INSTALL_DIR := /usr/local

LIB_NAME := libbm3d

CUDA_INCLUDE :=/usr/local/cuda/include
CUDA_FLAGS= -arch=sm_35

SOURCE :=  \
	bm3d.cpp

DEFINES := 
CXXFLAGS := -O2 -fPIC -Wall -Wextra --std=c++11

#****************************************************************************
# Makefile code common to all platforms
#****************************************************************************
CXXFLAGS := ${CXXFLAGS} ${DEFINES}
OBJECTS := $(addsuffix .o,$(basename ${SOURCE}))

#****************************************************************************
# Compile block
#****************************************************************************
all: staticlib

staticlib:$(OBJECTS)
	$(AR) $(ARFLAGS) $(LIB_NAME).a $(OBJECTS)

#****************************************************************************
# Depend block
#****************************************************************************
bm3d.o: bm3d.cpp bm3d_implement.cpp
	${CXX} ${CXXFLAGS} ${INCS} -c $< -o $@

filtering.o: filtering.cu params.hpp
	@nvcc $(addprefix -I,$(CUDA_INCLUDE)) -m64 -c $(CUDA_FLAGS) $< -o $@

blockmatching.o: blockmatching.cu params.hpp
	@nvcc $(addprefix -I,$(CUDA_INCLUDE)) -m64 -c --std=c++11 $(CUDA_FLAGS) $< -o $@

dct8x8.o: dct8x8.cu
	@nvcc $(addprefix -I,$(CUDA_INCLUDE)) -m64 -c $(CUDA_FLAGS) $< -o $@

install:
	sudo cp $(LIB_NAME).a ${INSTALL_DIR}/lib
	sudo cp bm3d.h ${INSTALL_DIR}/include

clean:
	rm -rf *.a *.so *.o $(OBJECTS)

