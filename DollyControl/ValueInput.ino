void init_data_input(){
  Serial.println("Drawing Data Entry Menu");
  int index = 1;
  Serial.print("Starting button: ");
  Serial.println(index++);
  int button_size = 12;

  int radius = 15;
  int xOrigin = radius+5;
  int x = radius+5;
  int y = (2*radius)+5;
  int label_size = 2;

  String label_text = "1";
/*
  DisplayShape circle = DisplayShape(x, y, radius, LIGHTGREY);
  show_label("label_text", 
      circle.x-label_text.length()*label_size*6/2+label_size/2+1,
      circle.y-label_size*8/2+label_size/2+1,
      label_size,
      BLACK, BLACK, 1
  );
*/
  x+=(2*radius)+5;
  label_text = "2";

  Serial.print("Starting button: ");
  Serial.println(index++);
}