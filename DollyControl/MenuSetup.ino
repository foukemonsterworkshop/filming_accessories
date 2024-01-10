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
  return Button(circle, nav_label, NAVIGATE, return_menu);
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

  Button *array = new Button[6];

  DisplayShape stepperMotorArea = DisplayShape(border, xOffset, border, border+selectionHeight, LIGHTGREY);

  Label stepperLabel = Label("Motors Active",40,labelYOffset,2,GREEN, BLUE,1);
  Button stepperMotorState = Button(stepperMotorArea, stepperLabel, &steppersActive, UPDATE_VALUE);

  array[0] = stepperMotorState;

  DisplayShape homeMachineArea = DisplayShape(border,xOffset,((2*border)+selectionHeight),(2*(border+selectionHeight)), LIGHTGREY);

  Label homeLabel = Label("Home Machine",labelXOffset,labelYOffset+(selectionHeight+border),2,BLACK, BLUE,1);
  Button homeMachineButton = Button(homeMachineArea, homeLabel, NAVIGATE, HOME);

  array[1] = homeMachineButton;

  DisplayShape jogMachineArea = DisplayShape(border,xOffset,(3*border)+(2*selectionHeight),3*(border+selectionHeight), LIGHTGREY);

  Label jogLabel = Label("Jog Machine",labelXOffset,labelYOffset+(2*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button jogMachineButton = Button(jogMachineArea, jogLabel, NAVIGATE, JOG);

  array[2] = jogMachineButton;

  DisplayShape panMachineArea = DisplayShape(border,xOffset,(4*border)+(3*selectionHeight),4*(border+selectionHeight), LIGHTGREY);

  Label panLabel = Label("Pan Machine",labelXOffset,labelYOffset+(3*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button panMachineButton = Button(panMachineArea, panLabel, NAVIGATE, PAN);

  array[3] = panMachineButton;

  DisplayShape truckMachineArea = DisplayShape(border,xOffset,(5*border)+(4*selectionHeight),5*(border+selectionHeight), LIGHTGREY);

  Label truckLabel = Label("Truck Machine",labelXOffset,labelYOffset+(4*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button truckMachineButton = Button(truckMachineArea, truckLabel, NAVIGATE, TRUCK);

  array[4] = truckMachineButton;

  DisplayShape parallaxMachineArea = DisplayShape(border,xOffset,(6*border)+(5*selectionHeight),6*(border+selectionHeight), LIGHTGREY);

  Label parallaxLabel = Label("Parallax Machine",labelXOffset,labelYOffset+(5*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button parallaxMachineButton = Button(parallaxMachineArea, parallaxLabel, NAVIGATE, PARALLAX);

  array[5] = parallaxMachineButton;

  return Menu(array, "main");
}

Menu init_home_machine_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape homeMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Home Machine",40,10,2,GREEN, BLUE,1);
  Button test = Button(homeMachineArea, testLabel, UPDATE_VALUE);

  Button *array = new Button[2];
  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, "home");
}

Menu init_jog_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  Label testLabel = Label("Jog Machine",40,10,2,GREEN, BLUE,1);
  DisplayShape jogMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Button test = Button(jogMachineArea, testLabel, UPDATE_VALUE);

  Button *array = new Button[2];
  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  2, "jog");
}

Menu init_pan_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape panMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Pan",40,10,2,GREEN, BLUE,1);
  Button test = Button(panMachineArea, testLabel, UPDATE_VALUE);

  Button *array = new Button[2];
  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, 2, "pan");
}

Menu init_truck_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape truckMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Truck",40,10,2,GREEN, BLUE,1);
  Button test = Button(truckMachineArea, testLabel, UPDATE_VALUE);

  Button *array = new Button[2];
  array[0] = test;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array, 2, "truck");
}

Menu init_parallax_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape parallaxMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label parallax_label = Label("Parallax",40,10,2,GREEN, BLUE,1);
  Button parallax_button = Button(parallaxMachineArea, parallax_label, UPDATE_VALUE);

  Button *array = new Button[2];
  array[0] = parallax_button;
  array[1] = return_nav_button(MAIN, "Home");

  return Menu(array,  2, "parallax");
}

Menu data_entry_menu(Menu calling_menu){
  Serial.println(motion.speed);


}

