ALLHPP:=$(shell find . -name "*.hpp")

SRC=main.cpp $(shell find Genotype/ -name "*.cpp")
PROJMAIN=main

GPP=g++

GPPFLAGS= -std=c++11 -I.

run: all
	./$(PROJMAIN)

all: $(PROJMAIN)

$(PROJMAIN): $(SRC) Allheaders.hpp
	$(GPP) $(GPPFLAGS) $^ -o $@

Allheaders.hpp: $(ALLHPP)
	@echo "#ifndef ALL_HEADER_HPP" > $@
	@echo "#define ALL_HEADER_HPP" >> $@
	for i in $^; do \
        echo "#include \"$$i\"" >> $@; \
  done
	@echo "#endif" >> $@
