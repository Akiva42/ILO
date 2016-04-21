class Cell {
  float x;
  float y;
  float yOffset;
  float size;
  color c;
  int checked = 0;
  String type;
  boolean selected = false;
  Panel myPanel;
  String fileName;
  public PApplet parent;
  public AudioPlayer audioPlayer;
  //-----------------
  Cell(float x_, float y_, float size_, String type_, PApplet parent_) {
    x = x_;
    yOffset = y_;
    size = size_;
    type = type_;
    myPanel = new Panel(type, this);
    if (type_ == "light") {
      c = color(242, 226, 5);
    } else if (type_ == "sound") {
      c = color(242, 5, 135);
    } else if (type_ == "video") {
      c = color(5, 175, 242);
    } else if (type_ == "other") {
      c = color(255, 255, 255);
    }
    parent = parent_;
  }
  //-----------------
  void update(float scroll, boolean mouseClicked) {
    y = map(scroll, 0, height, 0, -height) + yOffset;
    pushStyle();
    if (selected) {
      pushStyle();
      noFill();
      strokeWeight(6);
      stroke(128);
      rect(x, y, size, size);
      popStyle();
      myPanel.update(mouseClicked);
    }
    stroke(c);
    if (checked == 0) {
      noFill();
    }
    if (checked == 1) {
      noFill();
      line(x, y, x+size, y+size);
      line(x, y+size, x+size, y);
    }
    if (checked == 2) {
      fill(c);
    }
    rect(x, y, size, size);
    popStyle();
  }
  //-----------------
  void setChecked(int v) {
    checked = v;
  }
  //-----------------
  int getChecked() {
    return checked;
  }
  //-----------------
  boolean over(float x_, float y_) {
    if (x_ > x && x_ < x+size && y_ > y && y_ < y+size) {
      return true;
    } else {
      return false;
    }
  }
  //----------------
  String getType() {
    return type;
  }
  //---------------
  void setType(String type_) {
    type = type_;
  }
  //---------------
  void setSelected(boolean selected_) {
    selected = selected_;
  }
  boolean getSelected() {
    return selected;
  }
  //----------------
  void setFileName(String fileName_) {
    fileName = fileName_;
  }
  //----------------
  String getFileName() {
    return fileName;
  }
  //----------------
  void trigger() {
    if (fileName != null) {
      println(type + " : " + fileName);
    } else {
      println(type);
    }
    if (type == "sound") {
      if (audioPlayer != null) {
        audioPlayer.play();
      }
    }
    if (type == "video") {
      playMovie();
    }
    if (type == "other") {
      if (fileName != null) {
        sendOsc(fileName);
      }
    }
  }
}