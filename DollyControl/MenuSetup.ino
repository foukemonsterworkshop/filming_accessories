Button return_nav_button(MenuState return_menu, String label_text){
  int x = lcd.Get_Width() - 15;
  int y = lcd.Get_Height() - 15;
  Circle circle = Circle(x,y,25, DARKGREY);
  int label_size = 1;
  Label nav_label = Label(label_text, 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  return Button(&circle, nav_label, NAVIGATE, return_menu);
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
  Button *array = new Button[button_size];

  int offsetIndex = 1;
  int selectionIndex = 0;

  Rectangle stepperMotorArea = Rectangle(border, 
                                          xOffset, 
                                          (offsetIndex*border)+(selectionIndex*selectionHeight),
                                          (offsetIndex*(border+selectionHeight)), true, GREEN);

  String active_text = "Motors Active";
  String inactive_text = "Motors Inactive";
  Label stepperLabel = Label(active_text,labelXOffset,labelYOffset,2,BLACK, BLACK,1);
  Button stepperMotorState = Button(&stepperMotorArea, stepperLabel, &steppersActive, UPDATE_VALUE, active_text, inactive_text);

  array[0] = stepperMotorState;

  offsetIndex++;
  selectionIndex++;

  Rectangle homeMachineArea = Rectangle(border,
                                        xOffset,
                                        (offsetIndex*border)+(selectionIndex*selectionHeight),
                                        (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  Label homeLabel = Label("Home Machine",labelXOffset,labelYOffset+selectionIndex*(selectionHeight+border),2,BLACK, BLACK,1);
  Button homeMachineButton = Button(&homeMachineArea, homeLabel, NAVIGATE, HOME);

  array[1] = homeMachineButton;

  offsetIndex++;
  selectionIndex++;

  Rectangle jogMachineArea = Rectangle(border,
                                        xOffset,
                                        (offsetIndex*border)+(selectionIndex*selectionHeight),
                                        (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  Label jogLabel = Label("Jog Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button jogMachineButton = Button(&jogMachineArea, jogLabel, NAVIGATE, JOG);

  array[2] = jogMachineButton;

  offsetIndex++;
  selectionIndex++;

  Rectangle panMachineArea = Rectangle(border,
                                        xOffset,
                                        (offsetIndex*border)+(selectionIndex*selectionHeight),
                                        (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  Label panLabel = Label("Pan Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button panMachineButton = Button(&panMachineArea, panLabel, NAVIGATE, PAN);

  array[3] = panMachineButton;

  offsetIndex++;
  selectionIndex++;
/*
  Rectangle truckMachineArea = Rectangle(border,
                                          xOffset,
                                          (offsetIndex*border)+(selectionIndex*selectionHeight),
                                          (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  Label truckLabel = Label("Truck Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button truckMachineButton = Button(&truckMachineArea, truckLabel, NAVIGATE, TRUCK);

  array[4] = truckMachineButton;
*/
  offsetIndex++;
  selectionIndex++;

  Serial.println(offsetIndex);
  Serial.println(selectionIndex);

  Rectangle parallaxMachineArea = Rectangle(border,
                                            xOffset,
                                            (offsetIndex*border)+(selectionIndex*selectionHeight),
                                            (offsetIndex*(border+selectionHeight)), false, LIGHTGREY);

  Label parallaxLabel = Label("Parallax Machine",labelXOffset,labelYOffset+(selectionIndex*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button parallaxMachineButton = Button(&parallaxMachineArea, parallaxLabel, NAVIGATE, PARALLAX);

  array[5] = parallaxMachineButton;

  return Menu(array, button_size, "main");
}

Menu init_home_machine_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  Triangle homeMachineArea = Triangle(lcd.Get_Width()/2, lcd.Get_Height()/2, 30, NERP, BLUE);
  Label testLabel = Label("Home Machine",40,10,2,GREEN, BLUE,1);
  Button test = Button(&homeMachineArea, testLabel, UPDATE_VALUE);

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
  Rectangle jogMachineArea = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Button test = Button(&jogMachineArea, testLabel, UPDATE_VALUE);

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

  Rectangle panMachineArea = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Label testLabel = Label("Pan",40,10,2,GREEN, BLUE,1);
  Button test = Button(&panMachineArea, testLabel, UPDATE_VALUE);

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

  Rectangle truckMachineArea = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Label testLabel = Label("Truck",40,10,2,GREEN, BLUE,1);
  Button test = Button(&truckMachineArea, testLabel, UPDATE_VALUE);

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

  Rectangle parallaxMachineArea = Rectangle(border,xOffset,border,30, false, LIGHTGREY);
  Label parallax_label = Label("Parallax",40,10,2,GREEN, BLUE,1);
  Button parallax_button = Button(&parallaxMachineArea, parallax_label, UPDATE_VALUE);

  array[0] = parallax_button;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  button_size, "parallax");
}