void initializeMenus(){
  initializeMain();
  initializeHomeMachine();
}

void initializeMain(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayRectangle stepperMotorArea = DisplayRectangle(border,xOffset,border,30);
  Button stepperMotorState = Button(stepperMotorArea, &steppersActive, UPDATE_VALUE, false);

  Label stepperLabel = Label("Motors Active",40,10,2,GREEN, BLUE,1);
  MenuItem stepperMotorControl = MenuItem(stepperMotorArea, LIGHTGREY, stepperLabel, stepperMotorState, "stepper");

  DisplayRectangle homeMachineArea = DisplayRectangle(border,xOffset,(2*border)+selectionHeight,(2*border)+(2*selectionHeight));
  Button homeMachineButton = Button(homeMachineArea, NAVIGATE, false, HOME);
  Label hmLabel = Label("Home Machine",40,50,2,BLACK, BLUE,1);

  MenuItem homeMachineSelection = MenuItem(homeMachineArea, LIGHTGREY, hmLabel, homeMachineButton, "home");
  MenuItem *array = new MenuItem[6];
  array[0] = stepperMotorControl;
  array[1] = homeMachineSelection;

  mainMenu = Menu(array,  6, "main");
}

void initializeHomeMachine(){
  int border = 5;
  int selectionHeight = 30;
  int xOffset = lcd.Get_Display_Width()-border;

  DisplayRectangle homeMachineArea = DisplayRectangle(border,xOffset,border,30);
  Button test = Button(homeMachineArea, UPDATE_VALUE, false);

  Label testLabel = Label("Woah it happened",40,10,2,GREEN, BLUE,1);
  MenuItem stepperMotorControl = MenuItem(homeMachineArea, LIGHTGREY, testLabel, test, "test");

  MenuItem *array = new MenuItem[6];
  array[0] = stepperMotorControl;

  homeMenu = Menu(array,  6, "home");
}