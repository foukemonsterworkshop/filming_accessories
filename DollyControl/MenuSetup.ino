/*
Button return_nav_button(MenuState return_menu, String label_text){
  int x = lcd.Get_Width() - 15;
  int y = lcd.Get_Height() - 15;
  DisplayShape circle = DisplayShape(x,y,25, DARKGREY);
  int label_size = 1;
  Label nav_label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  return Button(circle, nav_label, return_menu);
}
*/

Button init_rectangle_nav_button(int x, int y, int x1, int y1, int16_t color, MenuState nav_target){
  DisplayShape rectangle = DisplayShape(x,y,x1,y1, color);
  return Button(rectangle, nav_target);
}

Button init_rectangle_state_button(int x, int y, int x1, int y1, int16_t color, boolean *target){
  DisplayShape rectangle = DisplayShape(x,y,x1,y1, color);
  return Button(rectangle, target);
}

Button init_circle_nav_button(int x, int y, int radius, int16_t color, MenuState nav_target){
  DisplayShape circle = DisplayShape(x, y, radius, color);
  return Button(circle, nav_target);
}

Button init_circle_state_button(int x, int y, int radius, int16_t color, boolean *target){
  DisplayShape circle = DisplayShape(x, y, radius, color);
  return Button(circle, target);
}

Button * init_menu(MenuState state){
  switch(state){
    case MAIN: return init_main_menu();
    /*case HOME: return init_home_machine_menu();
    case JOG: return init_jog_menu();
    case PAN: return init_pan_menu();
    case TRUCK: return init_truck_menu();
    case PARALLAX: return init_parallax_menu();
    case VALUE_ENTRY: return data_entry_menu();*/
  }
}

Button * init_main_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 6;
  Button *array = new Button[button_size];

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  array[0] = init_rectangle_state_button(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), GREEN, &steppersActive);
  draw_button(array[0]);
  show_label("Stepper Motors",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  position++;
  offset++;

  array[1] = init_rectangle_nav_button(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY, HOME);
  draw_button(array[1]);
  show_label("Home Machine",labelXOffset,labelYOffset+(selection_height+border),2,BLACK, BLACK,1);

  position++;
  offset++;

  array[2] = init_rectangle_nav_button(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY, JOG);
  draw_button(array[2]);
  show_label("Jog Machine",labelXOffset,labelYOffset+(2*(selection_height+border)),2,BLACK, BLACK,1);

  position++;
  offset++;

  array[3] = init_rectangle_nav_button(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY, PAN);
  draw_button(array[3]);
  show_label("Pan Machine",labelXOffset,labelYOffset+(3*(selection_height+border)),2,BLACK, BLACK,1);

  position++;
  offset++;

  array[4] = init_rectangle_nav_button(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY, TRUCK);
  draw_button(array[4]);
  show_label("Truck Machine",labelXOffset,labelYOffset+(4*(selection_height+border)),2,BLACK, BLACK,1);

  position++;
  offset++;

  array[5] = init_rectangle_nav_button(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY, PARALLAX);
  draw_button(array[5]);
  show_label("Parallax Machine",labelXOffset,labelYOffset+(5*(selection_height+border)),2,BLACK, BLACK,1);

  position++;
  offset++;
  return array;
}
/*
Menu init_home_machine_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape homeMachinedisplay = DisplayShape(lcd.Get_Width()/2, lcd.Get_Height()/2, 30, NERP, BLUE);
  Label testLabel = Label("Home Machine",40,10,2,GREEN, BLUE,1);
  Button test = Button(homeMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, button_size, "home");
}

Menu init_jog_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  Label testLabel = Label("Jog Machine",40,10,2,GREEN, BLUE,1);
  DisplayShape jogMachinedisplay = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Button test = Button(jogMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  button_size, "jog");
}

Menu init_pan_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape panMachinedisplay = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Pan",40,10,2,GREEN, BLUE,1);
  Button test = Button(panMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, button_size, "pan");
}

Menu init_truck_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape truckMachinedisplay = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Truck",40,10,2,GREEN, BLUE,1);
  Button test = Button(truckMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, button_size, "truck");
}

Menu init_parallax_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape parallaxMachinedisplay = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label parallax_label = Label("Parallax",40,10,2,GREEN, BLUE,1);
  Button parallax_button = Button(parallaxMachinedisplay, parallax_label, VALUE_ENTRY);

  array[0] = parallax_button;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  button_size, "parallax");
}

Menu data_entry_menu(){
  Serial.println("Drawing Data Entry Menu");
  int index = 1;
  Serial.print("Starting button: ");
  Serial.println(index++);
  int button_size = 12;
  Button *array = new Button[button_size];

  int radius = 15;
  int xOrigin = radius+5;
  int x = radius+5;
  int y = (2*radius)+5;
  int label_size = 2;

  String label_text = "1";

  DisplayShape circle = DisplayShape(x, y, radius, LIGHTGREY);
  Label label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[0] = Button(circle, label, MODIFY_INPUT);

  x+=(2*radius)+5;
  label_text = "2";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[1] = Button(circle, label, MODIFY_INPUT);

  x+=(2*radius)+5;
  label_text = "3";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[2] =  Button(circle, label, MODIFY_INPUT);

  x=xOrigin;
  y+=(2*radius)+5;
  label_text = "4";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[3] = Button(circle, label, MODIFY_INPUT);

  x+=(2*radius)+5;
  label_text = "5";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[4] = Button(circle, label, MODIFY_INPUT);
  
  x+=(2*radius)+5;
  label_text = "6";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[5] = Button(circle, label, MODIFY_INPUT);
  
  x=xOrigin;
  y+=(2*radius)+5;
  label_text = "7";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[6] = Button(circle, label, MODIFY_INPUT);
  
  x+=(2*radius)+5;
  label_text = "8";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[7] = Button(circle, label, MODIFY_INPUT);
  
  x+=(2*radius)+5;
  label_text = "9";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[8] = Button(circle, label, MODIFY_INPUT);
  
  x=xOrigin;
  y+=(2*radius)+5;
  label_text = ".";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[9] = Button(circle, label, MODIFY_INPUT);
  
  x+=(2*radius)+5;
  label_text = "0";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[10] = Button(circle, label, MODIFY_INPUT);
  
  x+=(2*radius)+5;
  label_text = "-";

  Serial.print("Starting button: ");
  Serial.println(index++);

  circle = DisplayShape(x, y, radius, LIGHTGREY);
  label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  array[11] = Button(circle, label, MODIFY_INPUT);
  
  delete(&label_text);  
  return Menu(array, button_size, "data_entry");
}

*/