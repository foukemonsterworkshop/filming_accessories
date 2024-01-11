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

  int button_size = 6;
  Button *array = new Button[button_size];

  DisplayShape stepperMotordisplay = DisplayShape(border, xOffset, border, border+selectionHeight, GREEN);

  String active_text = "Motors Active";
  String inactive_text = "Motors Inactive";
  Label stepperLabel = Label(active_text,40,labelYOffset,2,BLACK, BLACK,1);
  Button stepperMotorState = Button(stepperMotordisplay, stepperLabel, &steppersActive, active_text, inactive_text);

  array[0] = stepperMotorState;

  DisplayShape homeMachinedisplay = DisplayShape(border,xOffset,((2*border)+selectionHeight),(2*(border+selectionHeight)), LIGHTGREY);

  Label homeLabel = Label("Home Machine",labelXOffset,labelYOffset+(selectionHeight+border),2,BLACK, BLACK,1);
  Button homeMachineButton = Button(homeMachinedisplay, homeLabel, HOME);

  array[1] = homeMachineButton;

  DisplayShape jogMachinedisplay = DisplayShape(border,xOffset,(3*border)+(2*selectionHeight),3*(border+selectionHeight), LIGHTGREY);

  Label jogLabel = Label("Jog Machine",labelXOffset,labelYOffset+(2*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button jogMachineButton = Button(jogMachinedisplay, jogLabel, JOG);

  array[2] = jogMachineButton;

  DisplayShape panMachinedisplay = DisplayShape(border,xOffset,(4*border)+(3*selectionHeight),4*(border+selectionHeight), LIGHTGREY);

  Label panLabel = Label("Pan Machine",labelXOffset,labelYOffset+(3*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button panMachineButton = Button(panMachinedisplay, panLabel, PAN);

  array[3] = panMachineButton;

  DisplayShape truckMachinedisplay = DisplayShape(border,xOffset,(5*border)+(4*selectionHeight),5*(border+selectionHeight), LIGHTGREY);

  Label truckLabel = Label("Truck Machine",labelXOffset,labelYOffset+(4*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button truckMachineButton = Button(truckMachinedisplay, truckLabel, TRUCK);

  array[4] = truckMachineButton;

  DisplayShape parallaxMachinedisplay = DisplayShape(border,xOffset,(6*border)+(5*selectionHeight),6*(border+selectionHeight), LIGHTGREY);

  Label parallaxLabel = Label("Parallax Machine",labelXOffset,labelYOffset+(5*(selectionHeight+border)),2,BLACK, BLACK,1);
  Button parallaxMachineButton = Button(parallaxMachinedisplay, parallaxLabel, PARALLAX);

  array[5] = parallaxMachineButton;

  return Menu(array, button_size, "main");
}

Menu init_home_machine_menu(){
  int border = 5;
  int selectionHeight = 30;
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
  int selectionHeight = 30;
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
  int selectionHeight = 30;
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
  int selectionHeight = 30;
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
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  int button_size = 2;
  Button *array = new Button[button_size];

  DisplayShape parallaxMachinedisplay = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label parallax_label = Label("Parallax",40,10,2,GREEN, BLUE,1);
  Button parallax_button = Button(parallaxMachinedisplay, parallax_label, UPDATE_VALUE);

  array[0] = parallax_button;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  button_size, "parallax");
}

Menu data_entry_menu(Menu calling_menu){
  Serial.println(motion.speed);


}

