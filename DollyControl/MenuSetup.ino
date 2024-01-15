Button return_nav_button(MenuState return_menu, String label_text){
  DisplayShape circle = DisplayShape(lcd.Get_Width() - 30, lcd.Get_Height() - 30, 15, BLUE);
  Button button = Button(circle, return_menu, "general nav");
  draw_shape(circle);
  int label_size = 2;
  show_label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1);

  return button;
}


Button init_rectangle_nav_button(int x, int y, int x1, int y1, int16_t color, MenuState nav_target, char* name){
  DisplayShape rectangle = DisplayShape(x,y,x1,y1, color);
  return Button(rectangle, nav_target, name);
}

Button init_rectangle_state_button(int x, int y, int x1, int y1, int16_t color, boolean *target, char* name){
  DisplayShape rectangle = DisplayShape(x,y,x1,y1, color);
  return Button(rectangle, target, name);
}

Button init_circle_nav_button(int x, int y, int radius, int16_t color, MenuState nav_target, char* name){
  DisplayShape circle = DisplayShape(x, y, radius, color);
  return Button(circle, nav_target, name);
}

Button init_circle_state_button(int x, int y, int radius, int16_t color, boolean *target, char* name){
  DisplayShape circle = DisplayShape(x, y, radius, color);
  return Button(circle, target, name);
}

Button * init_menu(MenuState state){
  switch(state){
    case MAIN: return init_main_menu();
    case HOME: return init_home_machine_menu();
    case JOG: return init_jog_menu();
    case PAN: return init_pan_menu();
    case TRUCK: return init_truck_menu();
    case PARALLAX: return init_parallax_menu();
    //case VALUE_ENTRY: return data_entry_menu();
  }
}

void debug_print(Button button, int* press_array, DisplayShape shape){
  Serial.println(button.name);
  Serial.print("configured press area-> x: ");
  Serial.print(press_array[0]);
  Serial.print(" y: ");
  Serial.print(press_array[1]);
  Serial.print(" x1: ");
  Serial.print(press_array[2]);
  Serial.print(" y1: ");
  Serial.println(press_array[3]);

  Serial.print(shape.x);
  Serial.print(", ");
  Serial.print(shape.y);
  Serial.print(", ");
  Serial.print(shape.y1);
  Serial.print(", ");
  Serial.println(shape.x1);
}

Button * init_main_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 6;
  Button *array = new Button[button_size];
  //Button* array = (Button *) malloc (button_size * sizeof(Button));

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  DisplayShape rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), GREEN);
  array[0] = Button(rectangle, &steppersActive, "stepper");
  draw_shape(rectangle);
  show_label("Stepper Motors",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  position++;
  offset++;

  rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  Button button = Button(rectangle, HOME, "home");

  int *press_array = rectangle.press_area();
  button.x = press_array[0];
  button.y = press_array[1];
  button.x1 = press_array[2];
  button.y1 = press_array[3];

  debug_print(button, press_array, rectangle);

  delete(press_array);

  array[1] = button;

  draw_shape(rectangle);
  show_label("Home Machine",labelXOffset,labelYOffset+(selection_height+border),2,BLACK, BLACK,1);

  position++;
  offset++;

  rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  button = Button(rectangle, JOG, "jog");
  
  *press_array = rectangle.press_area();
  button.x = press_array[0];
  button.y = press_array[1];
  button.x1 = press_array[2];
  button.y1 = press_array[3];

  debug_print(button, press_array, rectangle);

  delete(press_array);

  array[2] = button;
  draw_shape(rectangle);
  show_label("Jog Machine",labelXOffset,labelYOffset+(2*(selection_height+border)),2,BLACK, BLACK,1);

  position++;
  offset++;

  rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  button = Button(rectangle, PAN, "pan");

  *press_array = rectangle.press_area();
  button.x = press_array[0];
  button.y = press_array[1];
  button.x1 = press_array[2];
  button.y1 = press_array[3];

  debug_print(button, press_array, rectangle);

  delete(press_array);

  array[3] = button;

  draw_shape(rectangle);
  show_label("Pan Machine",labelXOffset,labelYOffset+(3*(selection_height+border)),2,BLACK, BLACK,1);

  position++;
  offset++;

  rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  button = Button(rectangle, TRUCK, "truck");

  *press_array = rectangle.press_area();
  button.x = press_array[0];
  button.y = press_array[1];
  button.x1 = press_array[2];
  button.y1 = press_array[3];

  debug_print(button, press_array, rectangle);

  delete(press_array);

  array[4] = button;
  draw_shape(rectangle);
  show_label("Truck Machine",labelXOffset,labelYOffset+(4*(selection_height+border)),2,BLACK, BLACK,1);

  position++;
  offset++;

  rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  button = Button(rectangle, PARALLAX, "parallax");

  *press_array = rectangle.press_area();
  button.x = press_array[0];
  button.y = press_array[1];
  button.x1 = press_array[2];
  button.y1 = press_array[3];

  debug_print(button, press_array, rectangle);

  delete(press_array);

  array[5] = button;
  draw_shape(rectangle);
  show_label("Parallax Machine",labelXOffset,labelYOffset+(5*(selection_height+border)),2,BLACK, BLACK,1);

  delete(&rectangle);

  return array;
}

Button * init_home_machine_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  array[0] = Button (rectangle, MAIN, "return from home m");
  draw_shape(rectangle);
  show_label("Main From Home",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  array[1] = return_nav_button(MAIN, "Home");

  delete(&rectangle);

  return array;
}

Button * init_jog_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  array[0] = Button(rectangle, MAIN, "return from jog");
  draw_shape(rectangle);
  show_label("Main From Jog",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  array[1] = return_nav_button(MAIN, "Home");

  delete(&rectangle);

  return array;
}

Button * init_pan_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  array[0] = Button(rectangle, MAIN, "return from pan");
  draw_shape(rectangle);
  show_label("Main From Pan",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  array[1] = return_nav_button(MAIN, "Home");

  delete(&rectangle);

  return array;
}

Button * init_truck_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  array[0] = Button(rectangle, MAIN, "return from truck");
  draw_shape(rectangle);
  show_label("Main From Truck",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  array[1] = return_nav_button(MAIN, "Home");

  return array;
}

Button * init_parallax_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape rectangle = DisplayShape(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  array[0] = Button(rectangle, MAIN, "return from parallax");
  draw_shape(rectangle);
  show_label("Main From Parallax",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  array[1] = return_nav_button(MAIN, "Home");

  return array;
}
/*
Button * data_entry_menu(){
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
  return array;
}*/
