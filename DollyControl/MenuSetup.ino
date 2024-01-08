void initializeMenus(){
  initializeMain();

}

void initializeMain(){

  Serial.println("lcd info:");
  Serial.println(lcd.Get_Display_Width());
  Serial.println(lcd.Get_Width());
  Serial.println(lcd.Get_Height());

  int16_t border = 5;
  int16_t xOffset = lcd.Get_Display_Width()-(2*border);

  Serial.println(xOffset);

  DisplayRectangle stepperMotorArea = DisplayRectangle(border,xOffset,border,30);

  Button stepperMotorState = Button(stepperMotorArea, &steppersActive, UPDATE_VALUE);
  Label label = Label("Motors Active",40,10,2,GREEN, BLUE,1, "label created");

  MenuItem stepperMotorControl = MenuItem(stepperMotorArea, LIGHTGREY, label, stepperMotorState);

  Serial.println(label.extraData);
  Serial.println(stepperMotorControl.label.content);
  

  MenuItem *array = new MenuItem[6];
  array[0] = stepperMotorControl;

  mainMenu = Menu(array,  6);
  
}