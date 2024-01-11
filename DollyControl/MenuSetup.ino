Button return_nav_button(MenuState return_menu, char label_text[]){
  int x = lcd.Get_Width() - 15;
  int y = lcd.Get_Height() - 15;
  Circle circle = Circle(x,y,25, DARKGREY);
  int label_size = 1;
  Label nav_label = Label(label_text, 
      circle.x-sizeof(label_text)*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  return Button(&circle, nav_label, return_menu);
}

Menu init_menu(MenuState state){
  switch(state){
    case MAIN: return init_main_menu();
    case HOME: return init_home_machine_menu();
    case JOG: return init_jog_menu();
    case PAN: return init_pan_menu();
    case TRUCK: return init_truck_menu();
    case PARALLAX: return init_parallax_menu();
  }
}

Menu init_main_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;
  int labelXOffset = 2*border;
  int labelYOffset = 12;

  Serial.println("Initializing Main Menu");

  int button_size = 6;
  Button array[button_size];

  int offsetIndex = 1;
  int selectionIndex = 0;

  Rectangle stepperMotordisplay = Rectangle(border, 
                                          xOffset, 
                                          (offsetIndex*border)+(selectionIndex*selectionHeight),
                                          (offsetIndex*(border+selectionHeight)), true, GREEN);

  DisplayShape *shapePtr = &stepperMotordisplay;

  char active_text[] = "Motors Active";
  char inactive_text[] = "Motors Inactive";
  Label stepperLabel = Label("Motors Active",labelXOffset,labelYOffset,2,BLACK, BLACK,1);
  Button stepperMotorState = Button(shapePtr, stepperLabel, &steppersActive, active_text, inactive_text);

  array[0] = stepperMotorState;

  offsetIndex++;
  selectionIndex++;

  Rectangle homeMachinedisplay = Rectangle(border,
                                        xOffset,
                                        (offsetIndex*border)+(selectionIndex*selectionHeight),
                                        (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  DisplayShape *homemPtr = &homeMachinedisplay;

  Label homeLabel = Label("Home Machine",labelXOffset,labelYOffset+selectionIndex*(selectionHeight+border),2,BLACK, BLACK,1);
  Button homeMachineButton = Button(homemPtr, homeLabel, HOME);

  array[1] = homeMachineButton;

  offsetIndex++;
  selectionIndex++;

  Rectangle jogMachinedisplay = Rectangle(border,
                                        xOffset,
                                        (offsetIndex*border)+(selectionIndex*selectionHeight),
                                        (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  DisplayShape *jogPtr = &jogMachinedisplay;

  Label jogLabel = Label("Jog Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button jogMachineButton = Button(jogPtr, jogLabel, JOG);

  array[2] = jogMachineButton;

  offsetIndex++;
  selectionIndex++;

  Rectangle panMachinedisplay = Rectangle(border,
                                        xOffset,
                                        (offsetIndex*border)+(selectionIndex*selectionHeight),
                                        (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  DisplayShape *panPtr = &panMachinedisplay;

  Label panLabel = Label("Pan Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button panMachineButton = Button(panPtr, panLabel, PAN);

  array[3] = panMachineButton;

  offsetIndex++;
  selectionIndex++;

  Rectangle truckMachinedisplay = Rectangle(border,
                                            xOffset,
                                            (offsetIndex*border)+(selectionIndex*selectionHeight),
                                            (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  DisplayShape *truckPtr = &truckMachinedisplay;

  Label truckLabel = Label("Truck Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button truckMachineButton = Button(truckPtr, truckLabel, TRUCK);

  array[4] = truckMachineButton;

  offsetIndex++;
  selectionIndex++;

  Serial.println(offsetIndex);
  Serial.println(selectionIndex);

  Rectangle parallaxMachinedisplay = Rectangle(border,
                                            xOffset,
                                            (offsetIndex*border)+(selectionIndex*selectionHeight),
                                            (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  DisplayShape *parallaxPtr = &parallaxMachinedisplay;

  Label parallaxLabel = Label("Parallax Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button parallaxMachineButton = Button(parallaxPtr, parallaxLabel, PARALLAX);

  array[5] = parallaxMachineButton;

  Menu val = Menu(array, button_size, "main");
  delete(array);
  return val;
}

Menu init_home_machine_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  Triangle homeMachinedisplay = Triangle(lcd.Get_Width()/2, lcd.Get_Height()/2, 30, NERP, BLUE);
  Label testLabel = Label("Home Machine",40,10,2,GREEN, BLUE,1);
  Button test = Button(&homeMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, button_size, "home");
}

Menu init_jog_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  Label testLabel = Label("Jog Machine",40,10,2,GREEN, BLUE,1);
  Rectangle jogMachinedisplay = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Button test = Button(&jogMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  button_size, "jog");
}

Menu init_pan_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  Rectangle panMachinedisplay = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Label testLabel = Label("Pan",40,10,2,GREEN, BLUE,1);
  Button test = Button(&panMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, button_size, "pan");
}

Menu init_truck_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  Rectangle truckMachinedisplay = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Label testLabel = Label("Truck",40,10,2,GREEN, BLUE,1);
  Button test = Button(&truckMachinedisplay, testLabel, UPDATE_VALUE);

  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, button_size, "truck");
}

Menu init_parallax_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  Rectangle parallaxMachinedisplay = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Label parallax_label = Label("Parallax",40,10,2,GREEN, BLUE,1);
  Button parallax_button = Button(&parallaxMachinedisplay, parallax_label, UPDATE_VALUE);

  array[0] = parallax_button;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  button_size, "parallax");
}