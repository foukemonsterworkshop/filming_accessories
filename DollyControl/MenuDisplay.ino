/*
void draw_menu(Menu menu){
  Serial.println("Drawing menu: " + menu.name);
  Button* bPtr = menu.buttons;
  Serial.println("Attempting Drawing button");
  Serial.println("Initialized: ");
  Serial.println(bPtr->initialized);

  Serial.println(menu.button_size);

  for(int i = 0; i < menu.button_size; i++){
    Serial.println("Attempting Drawing button");
    Serial.println("Initialized: ");
    Serial.println(bPtr->initialized);
    if(bPtr->initialized){
      draw_button(*bPtr);
      Serial.println("Drawn button: " + bPtr->label.content);
    }
    bPtr++;
  }
  Serial.println("Finished drawing menu: " + menu.name);
}
*/

void draw_shape(DisplayShape shape){
  switch(shape.display_type){
    case RECTANGLE:
      Serial.println("Drawing Rectangle");
      draw_rectangle(shape);
      break;
    case CIRCLE:
      Serial.println("Drawing Circle");
      draw_circle(shape);
      break;
    case TRIANGLE:
      Serial.println("Drawing Circle");
      draw_triangle(shape);
      break;
    case ARROW:
      Serial.println("Drawing Circle");
      draw_circle(shape);
      break;
  }
}

void draw_rectangle(DisplayShape rectangle){
  lcd.Fill_Rect(rectangle.x, rectangle.y, rectangle.width, rectangle.height, rectangle.bg_color);
}

void draw_circle(DisplayShape circle){
    lcd.Set_Draw_color(circle.bg_color);
    lcd.Fill_Circle(circle.x, circle.y, circle.radius);
}

void draw_triangle(DisplayShape triangle){
  Serial.println("Drawing a triangle");
  int x1,x2,y1,y2;
  switch(triangle.direction){
    case NERP:
      Serial.println("N");
      x1 = triangle.x-triangle.size;
      y1 = triangle.y+triangle.size;
      x2 = triangle.x+triangle.size;
      y2 = triangle.y+triangle.size;
      break;
    case EAMST:
      Serial.println("E");
      x1 = triangle.x-triangle.size;
      y1 = triangle.y+triangle.size;
      x2 = triangle.x+triangle.size;
      y2 = triangle.y+triangle.size;
      break;
    case SORTH:
      Serial.println("S");
      x1 = triangle.x-triangle.size;
      y1 = triangle.y+triangle.size;
      x2 = triangle.x+triangle.size;
      y2 = triangle.y+triangle.size;
      break;
    case WIBBLES:
      Serial.println("W");
      x1 = triangle.x-triangle.size;
      y1 = triangle.y+triangle.size;
      x2 = triangle.x+triangle.size;
      y2 = triangle.y+triangle.size;
      break;
  }
  lcd.Set_Draw_color(triangle.bg_color);
  lcd.Draw_Triangle(triangle.x, triangle.y-triangle.size, x1, y1, x2, y2);
}

void show_label(String content, int x, int y, int size, int16_t f_color, int16_t b_color, boolean mode){
    lcd.Set_Text_Mode(mode);
    lcd.Set_Text_Size(size);
    lcd.Set_Text_colour(f_color);
    lcd.Set_Text_Back_colour(b_color);
    lcd.Print_String(content, x, y);
}
