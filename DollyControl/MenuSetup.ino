void draw_nav_button(String label_text){
  lcd.Set_Draw_color(CYAN);
  int x = lcd.Get_Width() - 30;
  int y = lcd.Get_Height() - 30;
  lcd.Fill_Circle(x, y, 30);

  int label_size = 2;
  show_label(label_text, 
      x-label_text.length()*label_size*6/2+label_size/2+1,
      y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1);
}

void init_menu(MenuState state){
  Serial.print("Loading new menu: ");
  Serial.println(state);
  switch(state){
    case MAIN: 
      init_main_menu();
      break;
    case HOME: 
      init_home_machine_menu();
      break;
    case JOG:
      init_jog_menu();
      break;
    case PAN: 
      init_pan_menu();
      break;
    case TRUCK: 
      init_truck_menu();
      break;
    case PARALLAX: 
      init_parallax_menu();
      break;
    default:
      Serial.println("This is a bad state.");
    //case VALUE_ENTRY: return data_entry_menu();
  }
}

void init_main_menu(){
  int border = 5;
  int selection_height = 30;
  int width = lcd.Get_Display_Width()-(2*border);

  int list_position = 0;
  int display_position = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), GREEN);
  show_label("Motors Active",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Home Machine",labelXOffset,labelYOffset+(selection_height+border),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Jog Machine",labelXOffset,labelYOffset+(2*(selection_height+border)),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Pan Machine",labelXOffset,labelYOffset+(3*(selection_height+border)),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Truck Machine",labelXOffset,labelYOffset+(4*(selection_height+border)),2,BLACK, BLACK,1);

  list_position++;
  display_position++;

  lcd.Fill_Rect(border, (display_position*border)+(list_position*selection_height), width, display_position*(border+selection_height)-((display_position*border)+(list_position*selection_height)), LIGHTGREY);
  show_label("Parallax Machine",labelXOffset,labelYOffset+(5*(selection_height+border)),2,BLACK, BLACK,1);

}

void init_home_machine_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  show_label("Main From Home",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  draw_nav_button("Home");
}

void init_jog_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  show_label("Main From Jog",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  draw_nav_button("Home");
}

void init_pan_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  show_label("Main From Pan",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  draw_nav_button("Home");
}

void init_truck_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  show_label("Main From Truck",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  draw_nav_button("Home");
}

void init_parallax_menu(){
  int border = 5;
  int selection_height = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int position = 0;
  int offset = 1;

  int labelXOffset = 2*border;
  int labelYOffset = 12;

  lcd.Fill_Rect(border, (offset*border)+(position*selection_height), xOffset, offset*(border+selection_height), LIGHTGREY);
  show_label("Main From Parallax",labelXOffset,labelYOffset,2,BLACK, BLACK,1);

  draw_nav_button("Home");
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
  
  free(&label_text);  
  return array;
}*/
