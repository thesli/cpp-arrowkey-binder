#include <iostream>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <gtk/gtk.h>
#include <keybinder.h>

XKeyEvent createKeyEvent(Display *display,Window &win,Window &winRoot
	,bool pressed,int keycode,int modifiers);
int main(int argc, char *argv[]);