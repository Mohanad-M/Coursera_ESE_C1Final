#------------------------------------------------------------------------------
# [FILENAME]:		Makefile
# [BRIEF]:		_ Makefile for Coursera ESE Course.1 Week.2 Assessment.
# 			_ File used to build a system with support of 2 target
# 			_ platforms and their specific compilers (HOST &
# 			_ MSP432).
# [AUTHOR]:		Mohanad M. Marzouk
# [CREATED ON]:		Dec. 5, 2019
#
# [USE]:		make [TARGET] [OVERRIDES] [VERBOSE] [COURSE]
# [BUILD TARGETS]:
# 	<FILE>.o _ builds <FILE>.o object file.
# 	<FILE>.asm _ builds <FILE>.asm assembler output file.
# 	<FILE>.i _ builds <FILE>.i preprocessor output file.
# 	build _ builds and links all source files.
# 	all _ same as build.
# 	clean _ removes all generated files.
# [OVERRIDES]:
# 	MSP432 _ cross compilation for MSP432 platform.
# 	HOST _ native compilation to be tested on HOST platform.
# -----------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
VERBOSE = DISABLE
COURSE = COURSE

ifeq ($(VERBOSE),ENABLE)
CPPFLAGS += -DVERBOSE
endif

ifeq ($(COURSE),COURSE1)
CPPFLAGS += -DCOURSE1
endif

# Compiler Flags & Defines

#------------------------------------------------------------------------------
# Compiler Flags Description:
# 	-Wall: Enable all warning messages.
# 	-Werror: Treat all warnings as errors.
# 	-g: generate debugging information in executable.
# Linker Flags Description:
# 	-O0: disable linker optimizations.
# 	-std=c99: use c99 standard.
#------------------------------------------------------------------------------

COMCFLAGS = -Wall -Werror -g -O0 -std=c99
TARGET = c1final

# Platform Conditional Execution
ifeq ($(PLATFORM),HOST)
  CC = gcc
  CFLAGS = $(CO_CFLAGS)
  CPPFLAGS += -DHOST $(INCLUDES)
  LDFLAGS = -Wl,-Map=$(TARGET).map 	
  
  SIZE = size -Ad
endif

ifeq ($(PLATFORM), MSP)
	LINKER_FILE = -T msp432p401r.lds
	LINKER_PATH = -L ../
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	ARCHFLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	
	# architecture specific flags and includes
	SOURCES += src/interrupts_msp432p401r_gcc.c \
		   src/startup_msp432p401r_gcc.c \
		   src/system_msp432p401r_gcc.c

	CC = arm-none-eabi-gcc
	CPPFLAGS = -DMSP432 $(INCLUDES)
	CFLAGS = $(COMCFLAGS) $(ARCHFLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_PATH) $(LINKER_FILE)
	SIZE = arm-none-eabi-size -Ad

endif

# build target variables
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.s)
PRES = $(SOURCES:.c=.i)

# pattern matching

# object file output _ using -c flag to stop before linking
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

# dependency file output _ using -E -M flags to generate dependency file
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# assembly file output _ using -S flag to generate assembly file
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

# preprocessor file output _ using -E flag to generate preprocessor file
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

# Make targets

.PHONY: all
all: $(OBJS)

.PHONY: build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map

# End of file
