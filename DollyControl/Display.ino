/*
void draw_triangle(DisplayShape triangle){
  //only draws equilateral upward?
  Serial.println("Drawing a triangle");
  int x1,x2,y1,y2;

      Serial.println("N");
      x1 = triangle.x-triangle.size;
      y1 = triangle.y+triangle.size;
      x2 = triangle.x+triangle.size;
      y2 = triangle.y+triangle.size;
     
  lcd.Set_Draw_color(triangle.bg_color);
  lcd.Draw_Triangle(triangle.x, triangle.y-triangle.size, x1, y1, x2, y2);
}
*/
void show_label(String content, int x, int y, int size, int16_t f_color, int16_t b_color, boolean mode){
    lcd.Set_Text_Mode(mode);
    lcd.Set_Text_Size(size);
    lcd.Set_Text_colour(f_color);
    lcd.Set_Text_Back_colour(b_color);
    lcd.Print_String(content, x, y);
}
