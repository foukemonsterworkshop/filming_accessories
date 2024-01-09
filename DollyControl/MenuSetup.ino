HomeButton home_button(){
  int x = lcd.Get_Width() - 15;
  int y = lcd.Get_Height() - 15;
  DisplayCircle circle = DisplayCircle(x,y,25, DARKGREY);
  HomeButton test = HomeButton(circle, NAVIGATE, MAIN);

  Serial.print("Home button created");
  Serial.print(test.navigateTarget);

  return test;

}

Menu init_main_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;
  int labelXOffset = 2*border;
  int labelYOffset = 12;

  MenuItem *array = new MenuItem[6];

  DisplayRectangle stepperMotorArea = DisplayRectangle(border, xOffset, border, border+selectionHeight);
  Button stepperMotorState = Button(stepperMotorArea, &steppersActive, UPDATE_VALUE, false);
  Label stepperLabel = Label("Motors Active",40,labelYOffset,2,GREEN, BLUE,1);
  MenuItem stepperMotorControl = MenuItem(stepperMotorArea, GREEN, stepperLabel, stepperMotorState, "stepper");

  array[0] = stepperMotorControl;

  DisplayRectangle homeMachineArea = DisplayRectangle(border,xOffset,(2*border)+selectionHeight,2*(border+selectionHeight));
  Button homeMachineButton = Button(homeMachineArea, NAVIGATE, false, HOME);
  Label homeLabel = Label("Home Machine",labelXOffset,labelYOffset+(selectionHeight+border),2,BLACK, BLUE,1);
  MenuItem homeMachineSelection = MenuItem(homeMachineArea, LIGHTGREY, homeLabel, homeMachineButton, "home");

  array[1] = homeMachineSelection;

  DisplayRectangle jogMachineArea = DisplayRectangle(border,xOffset,(3*border)+(2*selectionHeight),3*(border+selectionHeight));
  Button jogMachineButton = Button(jogMachineArea, NAVIGATE, false, JOG);
  Label jogLabel = Label("Jog Machine",labelXOffset,labelYOffset+(2*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem jogMachineSelection = MenuItem(jogMachineArea, LIGHTGREY, jogLabel, jogMachineButton, "jog");

  array[2] = jogMachineSelection;

  DisplayRectangle panMachineArea = DisplayRectangle(border,xOffset,(4*border)+(3*selectionHeight),4*(border+selectionHeight));
  Button panMachineButton = Button(panMachineArea, NAVIGATE, false, PAN);
  Label panLabel = Label("Pan Machine",labelXOffset,labelYOffset+(3*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem panMachineSelection = MenuItem(panMachineArea, LIGHTGREY, panLabel, panMachineButton, "pan");

  array[3] = panMachineSelection;

  DisplayRectangle truckMachineArea = DisplayRectangle(border,xOffset,(5*border)+(4*selectionHeight),5*(border+selectionHeight));
  Button truckMachineButton = Button(truckMachineArea, NAVIGATE, false, TRUCK);
  Label truckLabel = Label("Truck Machine",labelXOffset,labelYOffset+(4*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem truckMachineSelection = MenuItem(truckMachineArea, LIGHTGREY, truckLabel, truckMachineButton, "truck");

  array[4] = truckMachineSelection;

  DisplayRectangle parallaxMachineArea = DisplayRectangle(border,xOffset,(6*border)+(5*selectionHeight),6*(border+selectionHeight));
  Button parallaxMachineButton = Button(parallaxMachineArea, NAVIGATE, false, PARALLAX);
  Label parallaxLabel = Label("Parallax Machine",labelXOffset,labelYOffset+(5*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem paralaxMachineSelection = MenuItem(parallaxMachineArea, LIGHTGREY, parallaxLabel, parallaxMachineButton, "parallax");

  array[5] = paralaxMachineSelection;

  return Menu(array,  6, "main");
}

Menu init_home_machine_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayRectangle homeMachineArea = DisplayRectangle(border,xOffset,border,30);
  Button test = Button(homeMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Home Machine",40,10,2,GREEN, BLUE,1);
  MenuItem homeControl = MenuItem(homeMachineArea, LIGHTGREY, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = homeControl;

  return Menu(array,  6, "home", home_button());
}

Menu init_jog_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayRectangle jogMachineArea = DisplayRectangle(border,xOffset,border,30);
  Button test = Button(jogMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Jog Machine",40,10,2,GREEN, BLUE,1);
  MenuItem jogControl = MenuItem(jogMachineArea, LIGHTGREY, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = jogControl;

  return Menu(array,  6, "jog", home_button());
}

Menu init_pan_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayRectangle panMachineArea = DisplayRectangle(border,xOffset,border,30);
  Button test = Button(panMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Pan",40,10,2,GREEN, BLUE,1);
  MenuItem panControl = MenuItem(panMachineArea, LIGHTGREY, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = panControl;

  return Menu(array,  6, "pan", home_button());
}

Menu inti_truck_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayRectangle truckMachineArea = DisplayRectangle(border,xOffset,border,30);
  Button test = Button(truckMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Truck",40,10,2,GREEN, BLUE,1);
  MenuItem truckControl = MenuItem(truckMachineArea, LIGHTGREY, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = truckControl;

  return Menu(array,  6, "truck", home_button());
}

Menu init_parallax_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayRectangle parallaxMachineArea = DisplayRectangle(border,xOffset,border,30);
  Button test = Button(parallaxMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Parallax",40,10,2,GREEN, BLUE,1);
  MenuItem parallaxControl = MenuItem(parallaxMachineArea, LIGHTGREY, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = parallaxControl;

  return Menu(array,  6, "parallax", home_button());
}