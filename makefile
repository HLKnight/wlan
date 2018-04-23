OBJ = main.o wifi.o screen.o graph.o text.o
APPNAME = WLAN.a
TAR = WLAN.tar

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)

archive :
	tar cf $(TAR) *
