MenuItem home_nav_button(){
  int x = lcd.Get_Width() - 15;
  int y = lcd.Get_Height() - 15;
  DisplayShape circle = DisplayShape(x,y,25, DARKGREY);
  Button home_button = Button(circle, NAVIGATE, MAIN);

  String label = "Home";
  int label_size = 1;
  Label home_label = Label(label, 
      circle.x-label.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );

  MenuItem home_nav_button = MenuItem(circle, home_label, home_button, "home_nav");
  Serial.print("Home button created");
  Serial.print(home_button.navigateTarget);

  return home_nav_button;
}

Menu init_main_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;
  int labelXOffset = 2*border;
  int labelYOffset = 12;

  MenuItem *array = new MenuItem[6];

  DisplayShape stepperMotorArea = DisplayShape(border, xOffset, border, border+selectionHeight);
  Button stepperMotorState = Button(stepperMotorArea, &steppersActive, UPDATE_VALUE, false);
  Label stepperLabel = Label("Motors Active",40,labelYOffset,2,GREEN, BLUE,1);
  MenuItem stepperMotorControl = MenuItem(stepperMotorArea, stepperLabel, stepperMotorState, "stepper");

  array[0] = stepperMotorControl;

  DisplayShape homeMachineArea = DisplayShape(border,xOffset,(2*border)+selectionHeight,2*(border+selectionHeight));
  Button homeMachineButton = Button(homeMachineArea, NAVIGATE, false, HOME);
  Label homeLabel = Label("Home Machine",labelXOffset,labelYOffset+(selectionHeight+border),2,BLACK, BLUE,1);
  MenuItem homeMachineSelection = MenuItem(homeMachineArea, homeLabel, homeMachineButton, "home");

  array[1] = homeMachineSelection;

  DisplayShape jogMachineArea = DisplayShape(border,xOffset,(3*border)+(2*selectionHeight),3*(border+selectionHeight));
  Button jogMachineButton = Button(jogMachineArea, NAVIGATE, false, JOG);
  Label jogLabel = Label("Jog Machine",labelXOffset,labelYOffset+(2*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem jogMachineSelection = MenuItem(jogMachineArea, jogLabel, jogMachineButton, "jog");

  array[2] = jogMachineSelection;

  DisplayShape panMachineArea = DisplayShape(border,xOffset,(4*border)+(3*selectionHeight),4*(border+selectionHeight));
  Button panMachineButton = Button(panMachineArea, NAVIGATE, false, PAN);
  Label panLabel = Label("Pan Machine",labelXOffset,labelYOffset+(3*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem panMachineSelection = MenuItem(panMachineArea, panLabel, panMachineButton, "pan");

  array[3] = panMachineSelection;

  DisplayShape truckMachineArea = DisplayShape(border,xOffset,(5*border)+(4*selectionHeight),5*(border+selectionHeight));
  Button truckMachineButton = Button(truckMachineArea, NAVIGATE, false, TRUCK);
  Label truckLabel = Label("Truck Machine",labelXOffset,labelYOffset+(4*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem truckMachineSelection = MenuItem(truckMachineArea, truckLabel, truckMachineButton, "truck");

  array[4] = truckMachineSelection;

  DisplayShape parallaxMachineArea = DisplayShape(border,xOffset,(6*border)+(5*selectionHeight),6*(border+selectionHeight));
  Button parallaxMachineButton = Button(parallaxMachineArea, NAVIGATE, false, PARALLAX);
  Label parallaxLabel = Label("Parallax Machine",labelXOffset,labelYOffset+(5*(selectionHeight+border)),2,BLACK, BLUE,1);
  MenuItem paralaxMachineSelection = MenuItem(parallaxMachineArea, parallaxLabel, parallaxMachineButton, "parallax");

  array[5] = paralaxMachineSelection;

  return Menu(array,  6, "main");
}

Menu init_home_machine_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape homeMachineArea = DisplayShape(border,xOffset,border,30);
  Button test = Button(homeMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Home Machine",40,10,2,GREEN, BLUE,1);
  MenuItem homeControl = MenuItem(homeMachineArea, testLabel, test, "test");



  MenuItem *array = new MenuItem[2];
  array[0] = homeControl;

  return Menu(array,  6, "home");
}

Menu init_jog_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape jogMachineArea = DisplayShape(border,xOffset,border,30);
  Button test = Button(jogMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Jog Machine",40,10,2,GREEN, BLUE,1);
  MenuItem jogControl = MenuItem(jogMachineArea, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = jogControl;

  return Menu(array,  6, "jog");
}

Menu init_pan_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape panMachineArea = DisplayShape(border,xOffset,border,30);
  Button test = Button(panMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Pan",40,10,2,GREEN, BLUE,1);
  MenuItem panControl = MenuItem(panMachineArea, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = panControl;

  return Menu(array,  6, "pan");
}

Menu inti_truck_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape truckMachineArea = DisplayShape(border,xOffset,border,30);
  Button test = Button(truckMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Truck",40,10,2,GREEN, BLUE,1);
  MenuItem truckControl = MenuItem(truckMachineArea, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = truckControl;

  return Menu(array,  6, "truck");
}

Menu init_parallax_menu(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayShape parallaxMachineArea = DisplayShape(border,xOffset,border,30);
  Button parallax_button = Button(parallaxMachineArea, UPDATE_VALUE, false);

  Label parallax_label = Label("Parallax",40,10,2,GREEN, BLUE,1);
  MenuItem parallaxControl = MenuItem(parallaxMachineArea, parallax_label, parallax_button, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = parallaxControl;

  return Menu(array,  6, "parallax");
}