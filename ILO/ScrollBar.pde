class ScrollBar {
  float x;
  float y;
  float w;
  float h;
  color c;
  boolean dragging = false;
  float dragOffset = 0;
  ScrollBar(float x_, float y_, float w_, float h_, color c_) {
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    c = c_;
  }
  //-----------------
  void update(float newY) {
    if (dragging) {
      y = newY + dragOffset;
    }
    if(y < 0){
     y = 0; 
    }
    if(y + h > height){
     y = height - h; 
    }
    pushStyle();
    noStroke();
    fill(c);
    rect(x, y, w, h);
    popStyle();
  }
  //-----------------
  boolean over(float x_, float y_) {
    if (x_ > x && x_ < x+w && y_ > y && y_ < y+h) {
      return true;
    } else {
      return false;
    }
  }
  //-----------------
  void setDragging(boolean v, float newY) {
    dragging = v;
    dragOffset = y - newY;
  }
  //-----------------
  float getY(){
   return y; 
  }
  //-----------------
  void setY(float v){
    y = v;
  }
}