class Panel {
  String type;
  color c;
  Button loadButton;
  float panelWidth = width/3*2;
  Cell parentCell;
  //------------
  Panel(String type_, Cell parentCell_) {
    type = type_;
    parentCell = parentCell_;
    if(type_ == "light"){
      c = color(242, 226, 5);
    }else if(type_ == "sound"){
      c = color(242, 5, 135);
    }else if(type_ == "video"){
     c = color(5, 175, 242);
    }else if(type_ == "other"){
     c = color(255, 255, 255); 
    }
    loadButton = new Button(c, "LOAD FILE", width/3 + 20, 20, 20, parentCell);
  }
  void update(boolean mouseClicked){
    pushMatrix();
    //translate(width/3,0);
    //----Sound Type----
    loadButton.update(mouseClicked);
    
    popMatrix();
  }
}