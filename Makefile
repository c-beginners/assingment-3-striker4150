CPP = g++
CPPFLAGS = -g
PROGS = matrix.exe

# Cross-OS clean
ifdef OS
	RM = del /Q
else
	RM = rm -f
endif

.PHONY: all clean

all: $(PROGS)

matrix.exe: matrix.cpp
	$(CPP) $(CPPFLAGS) -o matrix.exe matrix.cpp

clean:
	$(RM) $(PROGS)