MenuItem home_nav_button(){
  int x = lcd.Get_Width() - 15;
  int y = lcd.Get_Height() - 15;
  DisplayShape circle = DisplayShape(x,y,25, DARKGREY);
  String label = "Home";
  int label_size = 1;
  Label home_label = Label(label, 
      circle.x-label.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
  Button home_button = Button(circle, home_label, NAVIGATE, MAIN);

  MenuItem home_nav_button = MenuItem(circle, &home_button, "home_nav");
  Serial.print("Home button created");
  Serial.print(home_button.navigateTarget);

  return home_nav_button;
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

  MenuItem *array = new MenuItem[6];

  DisplayShape stepperMotorArea = DisplayShape(border, xOffset, border, border+selectionHeight, LIGHTGREY);

  Label stepperLabel = Label("Motors Active",40,labelYOffset,2,GREEN, BLUE,1);
  Button stepperMotorState = Button(stepperMotorArea, stepperLabel, &steppersActive, UPDATE_VALUE);
  MenuItem stepperMotorControl = MenuItem(stepperMotorArea, &stepperMotorState, "stepper");

  array[0] = stepperMotorControl;

  DisplayShape homeMachineArea = DisplayShape(border,xOffset,((2*border)+selectionHeight),(2*(border+selectionHeight)), LIGHTGREY);

  Label homeLabel = Label("Home Machine",labelXOffset,labelYOffset+(selectionHeight+border),2,BLACK, BLUE,1);
  Button homeMachineButton = Button(homeMachineArea, homeLabel, NAVIGATE, HOME);
  MenuItem homeMachineSelection = MenuItem(homeMachineArea, &homeMachineButton, "home");

  array[1] = homeMachineSelection;

  DisplayShape jogMachineArea = DisplayShape(border,xOffset,(3*border)+(2*selectionHeight),3*(border+selectionHeight), LIGHTGREY);

  Label jogLabel = Label("Jog Machine",labelXOffset,labelYOffset+(2*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button jogMachineButton = Button(jogMachineArea, jogLabel, NAVIGATE, JOG);
  MenuItem jogMachineSelection = MenuItem(jogMachineArea, &jogMachineButton, "jog");

  array[2] = jogMachineSelection;

  DisplayShape panMachineArea = DisplayShape(border,xOffset,(4*border)+(3*selectionHeight),4*(border+selectionHeight), LIGHTGREY);

  Label panLabel = Label("Pan Machine",labelXOffset,labelYOffset+(3*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button panMachineButton = Button(panMachineArea, panLabel, NAVIGATE, PAN);
  MenuItem panMachineSelection = MenuItem(panMachineArea, &panMachineButton, "pan");

  array[3] = panMachineSelection;

  DisplayShape truckMachineArea = DisplayShape(border,xOffset,(5*border)+(4*selectionHeight),5*(border+selectionHeight), LIGHTGREY);

  Label truckLabel = Label("Truck Machine",labelXOffset,labelYOffset+(4*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button truckMachineButton = Button(truckMachineArea, truckLabel, NAVIGATE, TRUCK);
  MenuItem truckMachineSelection = MenuItem(truckMachineArea, &truckMachineButton, "truck");

  array[4] = truckMachineSelection;

  DisplayShape parallaxMachineArea = DisplayShape(border,xOffset,(6*border)+(5*selectionHeight),6*(border+selectionHeight), LIGHTGREY);

  Label parallaxLabel = Label("Parallax Machine",labelXOffset,labelYOffset+(5*(selectionHeight+border)),2,BLACK, BLUE,1);
  Button parallaxMachineButton = Button(parallaxMachineArea, parallaxLabel, NAVIGATE, PARALLAX);
  MenuItem paralaxMachineSelection = MenuItem(parallaxMachineArea, &parallaxMachineButton, "parallax");

  array[5] = paralaxMachineSelection;

  return Menu(array,  6, "main");
}

Menu init_home_machine_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape homeMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Home Machine",40,10,2,GREEN, BLUE,1);
  Button test = Button(homeMachineArea, testLabel, UPDATE_VALUE);

  MenuItem homeControl = MenuItem(homeMachineArea, &test, "test");

  MenuItem *array = new MenuItem[2];
  array[0] = homeControl;
  array[1] = home_nav_button();

  return Menu(array,  6, "home");
}

Menu init_jog_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  Label testLabel = Label("Jog Machine",40,10,2,GREEN, BLUE,1);
  DisplayShape jogMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Button test = Button(jogMachineArea, testLabel, UPDATE_VALUE);

  MenuItem jogControl = MenuItem(jogMachineArea, &test, "test");

  MenuItem *array = new MenuItem[2];
  array[0] = jogControl;
  array[1] = home_nav_button();

  return Menu(array,  2, "jog");
}

Menu init_pan_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape panMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Pan",40,10,2,GREEN, BLUE,1);
  Button test = Button(panMachineArea, testLabel, UPDATE_VALUE);
  
  MenuItem panControl = MenuItem(panMachineArea, &test, "test");

  MenuItem *array = new MenuItem[2];
  array[0] = panControl;
  array[1] = home_nav_button();

  return Menu(array, 2, "pan");
}

Menu init_truck_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape truckMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label testLabel = Label("Truck",40,10,2,GREEN, BLUE,1);
  Button test = Button(truckMachineArea, testLabel, UPDATE_VALUE);

  MenuItem truckControl = MenuItem(truckMachineArea, &test, "test");

  MenuItem *array = new MenuItem[2];
  array[0] = truckControl;
  array[1] = home_nav_button();

  return Menu(array, 2, "truck");
}

Menu init_parallax_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape parallaxMachineArea = DisplayShape(border,xOffset,border,30, LIGHTGREY);
  Label parallax_label = Label("Parallax",40,10,2,GREEN, BLUE,1);
  Button parallax_button = Button(parallaxMachineArea, parallax_label, UPDATE_VALUE);

  MenuItem parallaxControl = MenuItem(parallaxMachineArea, &parallax_button, "test");

  MenuItem *array = new MenuItem[2];
  array[0] = parallaxControl;
  array[1] = home_nav_button();

  return Menu(array,  2, "parallax");
}

