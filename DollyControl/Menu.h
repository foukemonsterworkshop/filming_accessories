//#include <unordered_map>

enum MenuState {MAIN, HOME, JOG, PAN, TRUCK, PARALLAX} currentState;

class Rectangle{
  public:
    int16_t minX;
    int16_t maxX;
    int16_t minY;
    int16_t maxY;
    boolean contains(int16_t px, int16_t py){
      return px > minX && px < maxX && py > minY && py < maxY;
    }
};

class Button{
  public:
    MenuState toNavigate;
};

class MenuItem{
  public:
    int16_t xSize;
    int16_t ySize;
    String title;
    Button interaction;



};

class Menu{
  public:
    Menu(){}
    //placeholder size
    MenuItem menuItems[15];

};