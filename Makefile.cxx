all: hw

OBJS = hw.o qwe.o
.SUFFIXES = .cpp .o

hw: $(OBJS)
        cc -o $@ $(OBJS)

.cpp.o:
        cc -o $@ $<
