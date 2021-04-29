PROJ_NAME = Emb_project

BUILD_DIR = Build

# All Source code files
SRC =src/activity1.c\
src/activity2.c\
src/activity3.c\
src/activity4.c
INC = -I inc
MAIN=seatheatingapp.c

# All header file paths
HFLAGS = -j .text -j .data -O ihex
# Find out the OS and configure the variables accordingly
ifdef OS	# All configurations for Windwos OS
# Correct the path based on OS
   FixPath = $(subst /,\,$1)
# Name of the compiler used
   CC = avr-gcc.exe
# Name of the elf to hex file converter used
   AVR_OBJ_CPY = avr-objcopy.exe
else #All configurations for Linux OS
   ifeq ($(shell uname), Linux)
# Correct the path based on OS
      FixPath = $1
# Name of the compiler used
	  CC = avr-gcc
# Name of the elf to hex file converter used
	  AVR_OBJ_CPY = avr-objcopy
   endif
endif

# Command to make to consider these names as targets and not as file names in folder
.PHONY:all analysis clean doc

all:$(BUILD_DIR)
# Compile the code and generate the ELF file
	$(CC) -g -Wall -Os -mmcu=atmega328 $(INC) $(SRC) $(MAIN) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

hex:$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)
	$(AVR_OBJ_CPY) $(HFLAGS) $< $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).hex)
$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)

analysis: $(SRC)
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^

doc:
# Build the code code documentation using Doxygen command line utility
	make -C documentation

clean:
# Remove all the build files and generated document files
	rm -rf $(call FixPath,$(BUILD_DIR)/*)
	make -C documentation clean
