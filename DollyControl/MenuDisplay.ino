void show_label(String content, int x, int y, int size, int16_t f_color, int16_t b_color, boolean mode){
    lcd.Set_Text_Mode(mode);
    lcd.Set_Text_Size(size);
    lcd.Set_Text_colour(f_color);
    lcd.Set_Text_Back_colour(b_color);
    lcd.Print_String(content, x, y);
}

void draw_nav_button(String label_text){
  lcd.Set_Draw_color(CYAN);
  int x = lcd.Get_Width() - 30;
  int y = lcd.Get_Height() - 30;
  lcd.Fill_Circle(x, y, 25);

  int label_size = 1.5;
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
    case VALUE_ENTRY: 
      init_data_input();
      break;
    default:
      Serial.println("This is a bad state.");
  }
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
