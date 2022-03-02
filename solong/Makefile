all: open window
open:
	gcc -lmlx openwin.c -framework OpenGL -framework AppKit -o $@
window:
	gcc -lmlx window.c -framework OpenGL -framework AppKit -o $@
clean:
	rm -rf a.out open window
re: clean all