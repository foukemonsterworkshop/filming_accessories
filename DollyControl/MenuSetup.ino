void initializeMenus(){
  initializeMain();

}

void initializeMain(){
  //main menu
  Serial.println("lcd info:");
  Serial.println(lcd.Get_Display_Width());
  Serial.println(lcd.Get_Width());
  Serial.println(lcd.Get_Height());

  int16_t border = 5;
  int16_t xOffset = lcd.Get_Display_Width()-(2*border);

  Serial.println(xOffset);

  Button stepperMotorState = Button(border,xOffset,border,30, &steppersActive);
  Label label = Label("Motors Active",50,11,2,GREEN, BLUE,1, "label created");

  MenuItem stepperMotorControl = MenuItem(5,xOffset,border,30, LIGHTGREY, label, stepperMotorState);

  Serial.println(label.extraData);
  Serial.println(stepperMotorControl.label.content);
  
  MenuItem *array;
  array = new MenuItem[6];
  array[0] = stepperMotorControl;

  mainMenu = Menu(array, 6);
  

  //Serial.println(getMenu(MAIN).item.label.content);
}