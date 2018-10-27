# Generic Makefile for compiling an executable, with pkg-config dependencies.
# https://gist.github.com/alkavan/5461441

CC := g++
PKGS :=
SRCDIR := src
BUILDDIR := build
CFLAGS := -std=c++17 -g -Wall # `pkg-config --cflags $(PKGS)`
# CFLAGS := -std=c++17 -g -Wall
LIBS := `pkg-config --libs $(PKGS)`
TARGET := i2c.out

SRCEXT = cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)

$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $^ -o $(TARGET) # $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(shell dirname $@)
	@echo " CC $<"; $(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<

clean:
	@echo " Cleaning..."; $(RM) -r $(BUILDDIR) $(TARGET) $(RESOURCE_TARGET) $(shell find src/ -type f -name "*.o")

-include $(DEPS)

.PHONY: clean
