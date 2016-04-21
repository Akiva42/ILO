//ILO was created by Akiva Krauthamer
//www.akivadesign.com
//www.akiva@cmu.edu

//Icons by:
//Pham Thi Dieu Linh
//Castor & Pollux
//Veronika Krpciarova
//Tom J Hume

import ddf.minim.*;
import processing.video.*;
import netP5.*;
import oscP5.*;
import java.awt.Component;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;

ChildApplet child;
PApplet parent = this;
public int numberOfScreens;
boolean firstFrame = true;
public Minim minim;
public Movie moviePlayer;
OscP5 oscP5;
NetAddress myRemoteLocation;
Cell[][] cells;
ScrollBar scrollBar = new ScrollBar(0, 0, 20, 50, color (255));
float cellSize = 40;
PShape lightIcon;
PShape soundIcon;
PShape videoIcon;
PShape otherIcon;
boolean mouseClicked = false;
public Button loadingFileFor;
int selectedRow;
//-----------------
void settings() {
  size(900, 600);
  smooth();
}
//----------------
void setup() {
  GraphicsEnvironment env = GraphicsEnvironment.getLocalGraphicsEnvironment();
  GraphicsDevice[] devices = env.getScreenDevices();
  numberOfScreens = devices.length;
  println("____ " + numberOfScreens + " _____");
  surface.setTitle("ILO");
  minim = new Minim(this);
  oscP5 = new OscP5(this, 12121);
  myRemoteLocation = new NetAddress("127.0.0.1", 12120);
  smooth();
  lightIcon = loadShape("light.svg");
  soundIcon = loadShape("sound.svg");
  videoIcon = loadShape("video.svg");
  otherIcon = loadShape("other.svg");
  strokeWeight(2);
  background(25);
  cells = new Cell[4][9];
  child = new ChildApplet();
  for (int x = 0; x < cells.length; x++) {
    for (int y = 0; y < cells[x].length; y++) {
      String tempType = "";
      if (x==0) {
        tempType = "light";
      }
      if (x==1) {
        tempType = "sound";
      }
      if (x==2) {
        tempType = "video";
      }
      if (x==3) {
        tempType = "other";
      }
      cells[x][y] = new Cell(50 + cellSize*1.5*x, 50+ cellSize*1.5*y, cellSize, tempType, child);
    }
  }
}
//-----------------
void draw() {
  if (firstFrame) {
    surface.setLocation(50, displayHeight/2 - height/2);
  }
  background(25);
  shape(lightIcon, 50, 5, cellSize, cellSize);
  shape(soundIcon, 50+cellSize*1.5, 5, cellSize, cellSize);
  shape(videoIcon, 50+cellSize*3, 5, cellSize, cellSize);
  shape(otherIcon, 50+cellSize*4.5, 5, cellSize, cellSize);
  stroke(255);
  line(width/3, 0, width/3, height);
  scrollBar.update(mouseY);
  for (int x = 0; x < cells.length; x++) {
    for (int y = 0; y < cells[x].length; y++) {
      cells[x][y].update(scrollBar.getY(), mouseClicked);
    }
  }
  mouseClicked = false;
}
//-----------------
void mouseClicked() {
  mouseClicked = true;
  if (mouseX < width/3) {
    for (int x = 0; x < cells.length; x++) {
      for (int y = 0; y < cells[x].length; y++) {
        if (cells[x][y].over(mouseX, mouseY)) {
          cells[x][y].setSelected(true);
          selectedRow = y;
        } else {
          cells[x][y].setSelected(false);
        }
      }
    }
  }
}
//-----------------
void mousePressed() {
  if (scrollBar.over(mouseX, mouseY)) {
    scrollBar.setDragging(true, mouseY);
  }
}
//-----------------
void mouseReleased() {
  scrollBar.setDragging(false, mouseY);
}
//-----------------
void mouseWheel(MouseEvent event) {
  if (event.getCount() > 0) {
    scrollBar.setY(scrollBar.getY()+ height/50);
  }
  if (event.getCount() < 0) {
    scrollBar.setY(scrollBar.getY()- height/50);
  }
}
//----------------
void fileSelected(File selection) {
  if (selection == null) {
    println("Window was closed or the user hit cancel.");
  } else {
    loadingFileFor.setFileName(selection.getAbsolutePath());
  }
  loadingFileFor = null;
}
//----------------
void keyPressed() {
  if (key == ' ') {
    for (int i = 0; i < cells.length; i++) {
      cells[i][selectedRow].trigger();
    }
    selectedRow +=1;
  }

  //-----stop playing everyting--------
  if (key == ESC) {
    key=0;
    for (int x = 0; x < cells.length; x++) {
      for (int y = 0; y < cells[x].length; y++) {
        if (cells[x][y].audioPlayer != null) {
          cells[x][y].audioPlayer.rewind();
          cells[x][y].audioPlayer.pause();
        }
      }
    }
  }
}
//---------------
void sendOsc(String string_) {
  OscMessage myMessage = new OscMessage("/ILO");
  myMessage.add(string_);
  oscP5.send(myMessage, myRemoteLocation);
}
//----
void sendOsc(int int_) {
  OscMessage myMessage = new OscMessage("/ILO");
  myMessage.add(int_);
  oscP5.send(myMessage, myRemoteLocation);
}
//----
void sendOsc(float float_) {
  OscMessage myMessage = new OscMessage("/ILO");
  myMessage.add(float_);
  oscP5.send(myMessage, myRemoteLocation);
}
//---------------
void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  println(" typetag: "+theOscMessage.typetag());
}
//---------------
void loadMovie(String fileName_) {
  moviePlayer = new Movie(this, fileName_);
}
//---------------
void playMovie() {
  moviePlayer.play();
}
//---------------
void movieEvent(Movie m) {
  m.read();
}
//---------------
//---------------
//---------------
class ChildApplet extends PApplet {
  public ChildApplet() {
    super();
    PApplet.runSketch(new String[]{this.getClass().getName()}, this);
  }
  //--------
  public void settings() {
    if (numberOfScreens > 1) {
      fullScreen(2);
    } else {
      size(600, 600);
    }
    smooth();
  }
  //--------
  public void setup() { 
    surface.setTitle("VIDEO");
  }
  //--------
  public void draw() {
    if (firstFrame) {
      if (numberOfScreens < 2) {
        surface.setLocation(50 + parent.width + 50, displayHeight/2-height/2);
      }
      firstFrame = false;
    }
    background(0);
    if (moviePlayer != null) {
      image(moviePlayer, 0, 0, width, height);
    }
  }
}