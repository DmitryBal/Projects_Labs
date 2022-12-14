all: hw
.PHONY: all clean

OBJS = hw.o qwe.o

hw: $(OBJS)
        cc -o $@ $(OBJS)

.c.o:
        cc -c -o $@ $<

clean:
        rm -f $(OBJS) hw
