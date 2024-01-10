class DisplayShape{
  public:
    int x,x2,y,y2;

    DisplayType display_type;

    int width,height,radius,size,tail_length;

    int16_t bg_color;

    //shape specific logical values;
    TriangleDirection direction;
    boolean rounded = false;

    void set_color(int bg_color){
      this->bg_color= bg_color;
    }

    virtual String print_type(){
      return "Called parent function";
    }

    virtual boolean is_pressed(int px, int py){
      return false;
    }
};

class Rectangle : public DisplayShape{
  public:
  //boolean is_pressed(int px, int py) override;
    Rectangle(int x,int x2,int y,int y2, boolean rounded, int16_t bg_color) : DisplayShape(){

      this->display_type = RECTANGLE;

      this->x=x;
      this->x2=x2;
      this->y=y;
      this->y2=y2;
      this->width = (x2-x);
      this->height = (y2-y);
      this->rounded = rounded;
      this->bg_color = bg_color;
    }

    boolean is_pressed(int px, int py){
      return px > x && px < x2 && py > y && py < y2;
    }

    String print_type(){
      return "Rectangle";
    }
};

class Circle : public DisplayShape{
  public:
    Circle(int x, int y, int radius, int16_t bg_color) : DisplayShape(){

      this->display_type = CIRCLE;

      this->x = x;
      this->y = y;
      this->radius = radius;
      this->bg_color = bg_color;
    }

    boolean is_pressed(int px,int py) {
      return (px > x-radius && px < x+radius) && (py > y-radius && py < y+radius);
    }

    String print_type(){
      return "Circle";
    }
};

class Triangle : public DisplayShape{
  public:
    Triangle(int x, int y, int size, TriangleDirection direction, int16_t bg_color) : DisplayShape(){

        this->display_type = TRIANGLE;
        this->direction = direction;

        this->x = x;
        this->y = y;
        this->size = size;
        this->bg_color = bg_color;
      }

    String print_type(){
      return "Triangle";
    }
};

class Arrow : public DisplayShape{
  public:
    Arrow(int x, int y, int size, int tail_length, TriangleDirection direction, int16_t bg_color) : DisplayShape(){

      this->display_type = ARROW;
      this->direction = direction;

      this->x = x;
      this->y = y;
      this->size = size;
      this->tail_length = tail_length;
      this->bg_color = bg_color;
    }

    String print_type(){
      return "Arrow";
    }
};