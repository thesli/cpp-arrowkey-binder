#include "main.h"


XKeyEvent createKeyEvent(Display *display,Window &win,Window &winRoot
	,bool pressed,int keycode,int modifiers){
	XKeyEvent event;
	event.display = display;
	event.window = win;
	event.root = winRoot;
	event.x = 1;
	event.y = 1;
	event.x_root = 1;
	event.y_root = 1;
	event.same_screen = True;
	event.keycode = XKeysymToKeycode(display,keycode);
	event.state = modifiers;
	event.type = pressed ? KeyPress : KeyRelease;
	return event;
}

void sendKeyEvent(std::string keycodeStr,std::string modifiersStr){	
	int keycode = 0;
	int modifiers = 0;

	if(keycodeStr.compare("Up")==0)		{keycode = XK_Up;}
	if(keycodeStr.compare("Down")==0)	{keycode = XK_Down;}
	if(keycodeStr.compare("Left")==0)	{keycode = XK_Left;}
	if(keycodeStr.compare("Right")==0)	{keycode = XK_Right;}
	if(keycodeStr.compare("Home")==0)	{keycode = XK_Home;}
	if(keycodeStr.compare("End")==0)	{keycode = XK_End;}
	if(keycodeStr.compare("Menu")==0)	{keycode = XK_Menu;}
	if(keycodeStr.compare("H")==0)	{keycode = XK_H;};

	if(modifiersStr.compare("none")==0)			{modifiers = 0;}
	if(modifiersStr.compare("Ctrl")==0)			{modifiers = ControlMask;}
	if(modifiersStr.compare("Shift")==0)		{modifiers = ShiftMask;}
	if(modifiersStr.compare("CtrlShift")==0)	{modifiers = ControlMask | ShiftMask;}

	// std::cout << keycode << modifiers << std::endl;

	Display *display = XOpenDisplay(0);
	if(display==NULL){return ;}

	Window winRoot = XDefaultRootWindow(display);
	Window winFocus;
	int revert;
	XGetInputFocus(display,&winFocus,&revert);

	XKeyEvent event = createKeyEvent(display,winFocus,winRoot,true,keycode,modifiers);
	XSendEvent(event.display,event.window,True,KeyPressMask,(XEvent*)&event);
	event = createKeyEvent(display,winFocus,winRoot,false,keycode,modifiers);
	XSendEvent(event.display,event.window,True,KeyPressMask,(XEvent*)&event);
	XCloseDisplay(display);	
}

void handler(const char *keyStr,void *user_data){	
	std::string keycode(keyStr);
	sendKeyEvent("Up","ABC");
	// keybinder_unbind(keyStr,handler);
	// gtk_main_quit();
}

int main(int argc, char *argv[])
{
	// gtk_init(&argc,&argv);
	// keybinder_init();	
	// keybinder_bind("<Alt>i",handler,NULL);
	// keybinder_bind("<Alt>j",handler,NULL);
	// keybinder_bind("<Alt>k",handler,NULL);
	// keybinder_bind("<Alt>l",handler,NULL);
	// keybinder_bind("<Alt><Shift_L>I",handler,NULL);
	// gtk_main();	
	// temp solution just use the native shortcut from the thingy

	sendKeyEvent(argv[1],argv[2]);

	return 0;
}
