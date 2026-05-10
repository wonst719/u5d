CROSS_CC_PREFIX = /djgpp/bin/i586-pc-msdosdjgpp-
CC = $(CROSS_CC_PREFIX)gcc
MKDIR = mkdir -p
OBJS :=

# Common
OBJS += \
	src/town.o \
	src/mainout.o \
	src/dungeon.o \
	src/intro.o \
	src/npc.o \
	src/combat.o \
	src/blckthrn.o \
	src/lookobj.o \
	src/dnglook.o \
	src/outsubs.o \
	src/shoppes.o \
	src/endgame.o \
	src/sjog.o \
	src/cmds.o \
	src/cast.o \
	src/talk.o \
	src/cast2.o \
	src/zstats.o \
	src/comsubs.o \
	src/shoppes2.o \
	src/shoppes3.o \
	src/font.o \
	src/vars.o \
	src/common/file.o \
	src/ultima.o \
	src/0000.o \
	src/1000.o \
	src/2000.o \
	src/3000.o \
	src/4000.o \
	src/5000.o \
	src/6000.o \
	src/7000.o \
	src/savegame.o \
	src/grap_drv.o \
	src/audio/audio.o \
	src/audio/aud_spk.o \
	src/audio/aud_sfx.o \
	src/backend/backend.o \
	src/event/evt_dos.o \
	src/graphics/grap_buf.o \
	src/graphics/grap_vga.o \
	src/graphics/grap.o \
	src/graphics/reveal.o \
	src/common/lzw.o \
	src/common/debug.o \
	src/key/key_dos.o \
	src/time/time_dos.o \
	src/time/pctimer.o

SRCS = $(OBJS:.o=.c)
TARGET = ultima5.exe

DEPDIR := .deps
MODULE_DIRS := ./ ./src/ ./src/audio/ ./src/backend/ ./src/common/ ./src/event/ ./src/graphics/ ./src/key/ ./src/time/
DEPDIRS := $(addsuffix $(DEPDIR),$(MODULE_DIRS))

INCLUDE_PATH := ./src/
LIB_PATH := 

C_FLAGS :=
LD_FLAGS :=

C_FLAGS += -I$(INCLUDE_PATH)
#LD_FLAGS += -L$(LIB_PATH)

S_FLAGS +=
C_FLAGS += -DDOS
C_FLAGS += -O2 -s

C_UPDATE_DEP_FLAG = -Wp,-MMD,"$(*D)/$(DEPDIR)/$(*F).d"

.SUFFIXES: .c .o

$(shell $(MKDIR) $(DEPDIRS))

%.o: %.c
	$(CC) $(C_UPDATE_DEP_FLAG) $(C_FLAGS) -c $(<) -o $*.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LD_FLAGS)

-include $(wildcard $(addsuffix /*.d,$(DEPDIRS)))

clean:
	rm -f $(OBJS) $(TARGET)
