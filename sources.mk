#------------------------------------------------------------------------------
# [FILENAME]:		sources.mk
# [DESCRIPTION]:	_ make include file for recursively expanded variables.
# [AUTHOR]:		Mohanad M. Marzouk
# [CREATED ON]:		Dec. 5, 2019
#------------------------------------------------------------------------------

SOURCES = src/main.c \
	  src/memory.c \
	  src/course1.c \
	  src/data.c \
	  src/stats.c

INCLUDES = -Iinclude/CMSIS \
	   -Iinclude/common \
	   -Iinclude/msp432

# End of file
