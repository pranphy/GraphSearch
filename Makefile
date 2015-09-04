#CC = /usr/bin/i586-mingw32msvc-g++


WXVERSION =2.8
WXFLAGS  = `wx-config --version=$(WXVERSION) --cxxflags`
WXLINKER = `wx-config --version=$(WXVERSION) --libs all --gl-libs`

INCLUDEDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin


CC = g++

FLAGS= -Wall -g -Os -std=c++11  -Iinclude -I/home/pranphy/MyRoot/lib $(WXFLAGS)
LINKER = $(WXLINKER) -lglut -lGLU -lGL


HEADERS = $(shell find . -name '*.h')
SOURCE =  $(shell find ./src -name '*.cpp')

OBJECTS = $(shell echo $(SOURCE) | sed s/$(SRCDIR)/$(OBJDIR)/g | sed s/.cpp/.o/g)

EXECUTEABLE = $(BINDIR)/Debug/GraphSearch


$(EXECUTEABLE):$(OBJECTS)
	-mkdir $(BINDIR)
	-mkdir $(BINDIR)/Debug
	$(CC) -o $(EXECUTEABLE) $(OBJECTS) $(LINKER)

.ONESHELL:
$(OBJECTS): $(SOURCE) $(HEADERS)
	-mkdir $(OBJDIR)
	for File in $(SOURCE)
	do
		$(CC) $(FLAGS) $(INCLUDE) -c $$File -o `echo $$File | sed s/.cpp/.o/g | sed s/$(SRCDIR)/$(OBJDIR)/g`
	done


clean:
	-rm $(OBJECTS) $(EXECUTEABLE)
