CROSS_CC_PREFIX = /djgpp/bin/i586-pc-msdosdjgpp-
CC = $(CROSS_CC_PREFIX)gcc
MKDIR = mkdir -p
OBJS :=

# Common
OBJS += \
	SRC/TOWN.o \
	SRC/MAINOUT.o \
	SRC/DUNGEON.o \
	SRC/INTRO.o \
	SRC/NPC.o \
	SRC/COMBAT.o \
	SRC/BLCKTHRN.o \
	SRC/LOOKOBJ.o \
	SRC/DNGLOOK.o \
	SRC/OUTSUBS.o \
	SRC/SHOPPES.o \
	SRC/ENDGAME.o \
	SRC/SJOG.o \
	SRC/CMDS.o \
	SRC/CAST.o \
	SRC/TALK.o \
	SRC/CAST2.o \
	SRC/ZSTATS.o \
	SRC/COMSUBS.o \
	SRC/SHOPPES2.o \
	SRC/SHOPPES3.o \
	SRC/FONT.o \
	SRC/VARS.o \
	SRC/FILE.o \
	SRC/ULTIMA.o \
	SRC/GRAP.o \
	SRC/GRAP_DRV.o \
	SRC/0000.o \
	SRC/1000.o \
	SRC/2000.o \
	SRC/3000.o \
	SRC/4000.o \
	SRC/5000.o \
	SRC/6000.o \
	SRC/7000.o \
	SRC/GRAP_VGA.o \
	SRC/LZW.o \
	SRC/DEBUG.o \
	SRC/KEY_DOS.o \
	SRC/PCTIMER.o

SRCS = $(OBJS:.o=.C)
TARGET = ultima5.exe

DEPDIR := .deps
MODULE_DIRS := ./ ./src/
DEPDIRS := $(addsuffix $(DEPDIR),$(MODULE_DIRS))

INCLUDE_PATH := 
LIB_PATH := 

C_FLAGS :=
LD_FLAGS :=

#C_FLAGS += -I$(INCLUDE_PATH)
#LD_FLAGS += -L$(LIB_PATH)

S_FLAGS +=
C_FLAGS += -DDOS
C_FLAGS += -O2 -s

C_UPDATE_DEP_FLAG = -Wp,-MMD,"$(*D)/$(DEPDIR)/$(*F).d"

.SUFFIXES: .C .o

$(shell $(MKDIR) $(DEPDIRS))

%.o: %.C
	$(CC) $(C_UPDATE_DEP_FLAG) $(C_FLAGS) -x c -c $(<) -o $*.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LD_FLAGS)

-include $(wildcard $(addsuffix /*.d,$(DEPDIRS)))

clean:
	rm -f $(OBJS) $(TARGET)
