class Button {
  color c;
  String buttonText;
  PVector pos;
  float textHeight;
  String fileName;
  Cell parentCell;
  //--------------
  Button(color c_, String text_, float x_, float y_, float textHeight_, Cell parentCell_) {
    c = c_;
    buttonText = text_;
    pos = new PVector(x_, y_);
    textHeight = textHeight_;
    parentCell = parentCell_;
  }
  //----------------
  void update(boolean mouseClicked) {
    pushMatrix();
    translate(pos.x, pos.y);
    pushStyle();
    textSize(textHeight);
    fill(c);
    stroke(c);
    textAlign(LEFT, TOP);
    text(buttonText, 0, 0);
    noFill();
    rect(0, 0, textWidth(buttonText), textHeight);
    if (mouseClicked && over(mouseX, mouseY)) {
      loadingFileFor = this;
      selectInput("Select a file:", "fileSelected");
    }
    popStyle();
    popMatrix();
  }
  //--------------
  boolean over(float x_, float y_) {
    if (x_ > pos.x && x_ < pos.x+textWidth(buttonText) && y_ > pos.y && y_ < pos.y+textHeight) {
      return true;
    } else {
      return false;
    }
  }
  void setFileName(String fileName_) {
    fileName = fileName_;
    parentCell.setFileName(fileName);
    if (parentCell.getType() == "sound") {
      parentCell.audioPlayer = minim.loadFile(fileName);
    }
    if (parentCell.getType() == "video") {
      loadMovie(fileName);
    }
    buttonText = fileName;
  }
}