void draw_menu(Menu menu){
  Serial.println("Drawing menu: " + menu.name);
  Button* bPtr = menu.buttons;
  Label* lPtr = menu.labels; 
  Serial.println("Attempting Drawing button");
  Serial.println("Initialized: ");
  Serial.println(bPtr->initialized);

  Serial.println(menu.button_size);

  for(int i = 0; i < menu.button_size; i++){
    Serial.println("Attempting Drawing button");
    Serial.println("Initialized: ");
    Serial.println(bPtr->initialized);
    if(bPtr->initialized){
      draw_shape(bPtr->area);
      show_label(bPtr->label);
      Serial.println("Drawn button: " + bPtr->label.content);
    }
    bPtr++;
  }
  Serial.println("Finished drawing menu: " + menu.name);
}

void draw_buttons(Button *buttons, int size){
  for(int j = 0; j < size; j++){
    
    buttons++;
  }
}

void draw_shape(DisplayShape shape){
  switch(shape.display_type){
    case RECTANGLE:
      Serial.println("Drawing Rectangle");
      draw_rectangle(shape, shape.bgColor);
      break;
    case CIRCLE:
      Serial.println("Drawing Circle");
      draw_circle(shape, shape.bgColor);
      break;
  }
}

void draw_rectangle(DisplayShape rectangle, int16_t color){
  lcd.Fill_Rect(rectangle.x, rectangle.y, rectangle.width, rectangle.height, color);
}

void draw_circle(DisplayShape circle, int16_t color){
    lcd.Set_Draw_color(color);
    lcd.Fill_Circle(circle.x, circle.y, circle.radius);
}

void show_label(Label label){
    lcd.Set_Text_Mode(label.mode);
    lcd.Set_Text_Size(label.textSize);
    lcd.Set_Text_colour(label.textColor);
    lcd.Set_Text_Back_colour(label.bgTextColor);
    lcd.Print_String(label.content, label.x, label.y);
}