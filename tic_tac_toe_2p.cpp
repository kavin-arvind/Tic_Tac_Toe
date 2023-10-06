#include<simplecpp>
#define h 250
int a[9]={0};
void draw(int p);
void draw_outline(){
    Line l1 (0,0,3*h,0);l1.imprint();
    Line l2 (0,h,3*h,h);l2.imprint();
    Line l3 (0,2*h,3*h,2*h);l3.imprint();
    Line l4 (0,3*h,3*h,3*h);l4.imprint();
    Line m1 (0,0,0,3*h);m1.imprint();
    Line m2 (h,0,h,3*h);m2.imprint();
    Line m3 (2*h,0,2*h,3*h);m3.imprint();
    Line m4 (3*h,0,3*h,3*h);m4.imprint();
    }//draws the outline of 9 boxes
int identify_index(){
    int cPos = getClick(); // ask the user to click on a point
    double x = cPos/65536.0; // x coordinate of the point
    double y = cPos%65536; // the point's y coordinate
    for(int i=1;i<=3;i++){
        if((i-1)*h<x && x<(i)*h){
            for(int j=1;j<=3;j++){
                if((j-1)*h<y && y<(j)*h){
                    return (i-1)+(j-1)*3;
                    }
                }
            }
        }
        /* box is like  [0 1 2
                        3 4 5
                        6 7 8]*/
    }//returns the box number
void draw_x(int index,int p){
    if(a[index]==0){
    a[index]=1;
    int i=index%3+1;
    int j=index/3+1;
    int x1=(i-1)*h+0.25*h;
    int x2=(i-1)*h+0.75*h;
    int y1=(j-1)*h+0.25*h;
    int y2=(j-1)*h+0.75*h;
    Line x (x1,y1,x2,y2);x.imprint();
    Line y (x1,y2,x2,y1);y.imprint();
    }
    else{draw(p);}
    }
void draw_o(int index,int p){
    if(a[index]==0){
    a[index]=2;
    int i=index%3+1;
    int j=index/3+1;
    int x=(i-1)*h+0.5*h;
    int y=(j-1)*h+0.5*h;
    Circle c(x,y,h/4);c.imprint();
    }
    else{draw(p);}
    }
void draw(int p){//p is the player number. 1-x,2-o
    if(p==1){draw_x(identify_index(),p);}
    else{draw_o(identify_index(),p);}
    }
bool check(){

    for(int i=0;i<=2;i++){if(a[i]==a[i+3] && a[i+3]==a[i+6] && a[i]!=0){
        Turtle t;t.penUp();t.moveTo(i*h+h/2,0.25*h);t.right(90);t.penDown();t.forward(2.5*h);t.imprint();
        return 1;}}
    for(int i=0;i<=6;i=i+3){if(a[i]==a[i+1] && a[i+1]==a[i+2] && a[i]!=0) {
        Turtle t;t.penUp();t.moveTo(0.25*h,(i/3)*h+h/2);t.penDown();t.forward(2.5*h);t.imprint();
        return 1;}}
    if(a[0]==a[4] && a[4]==a[8] && a[0]!=0) {
    Turtle t;t.penUp();t.moveTo(0.25*h,0.25*h);t.right(45);t.penDown();t.forward(3.54*h);t.imprint();//3.54=2.5*root(2)
    return 1;}
    if(a[2]==a[4] && a[4]==a[6] && a[2]!=0) {
    Turtle t;t.penUp();t.moveTo(2.75*h,0.25*h);t.right(135);t.penDown();t.forward(3.54*h);t.imprint();//3.54=2.5*root(2)
    return 1;}
    return 0;
    }
main_program{

initCanvas ("Tic Tac Toe",3*h,3*h); //To create a new window
draw_outline();

int p=1;
while(1){

    draw(p);

    if(check())break;
        bool flag=0;
        for(int i=0;i<=8;i++){if(a[i]==0) flag=1;}
        if(!flag){p=3;break;}
    if(p==1){p=2;}
    else{p=1;}
    }
cout<<"completed";
if(p==3){cout<<endl<<"draw match!! try again :)";}
else{cout<<endl<<"player "<<p<<" is the winner!";}

wait(5);


}
