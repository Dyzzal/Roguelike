/*
all the commented code except for the last bit was for testing
*/
#include <iostream>
#include <cassert>

using namespace std;

enum room_type{
    CHEST = 1,
    MONSTER_3 = 2,
    MONSTER_5 = 3,
    SHOP = 4,
    START = 5,
    END = 6,
};

enum direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Room{
public:
    Room(){
        
    };
    
    bool dir[4] = {false};
    int x, y;
    int type = 0;
    bool cleared = false;
};

class Dungeon{
    int width_ = 0, height_ = 0;
    int roomCount_ = 0;
    Room *start_;
    Room *end_;
    Room *shop_;
    Room **rooms_;
public:
    Dungeon(){
        
    };
    
    int width = width_;
    int height = height_;
    int roomCount = roomCount_;
    Room *start = start_;
    Room *end = end_;
    Room *shop = shop_;
    Room **rooms = rooms_;

    void Create(int w, int h, int min, int max){
        srand(time(0));
        width_ = w; height_ = h;
        assert(max >= min);
        assert(max <= w*h);
        rooms_ = new Room*[w];
        for(int i=0;i<w;i++)
            rooms_[i] = new Room[h];
        roomCount_ = rand()%((max - min) + 1) + min;
        int startX = rand()%((w - 0) + 1) + 0;
        int startY = rand()%((h - 0) + 1) + 0;
        int x = startX;
        int y = startY;
        
        cout<<roomCount_<<endl;
        for(int i=0;i<roomCount_;i++){//This is the broken for loop
            int pDir;
            int dir = rand()%((3 - 0) + 1) + 0;
            if(x==0 && dir == 3){
                do{
                    dir = rand()%((3 - 0) + 1) + 0;
                }while(dir==3);
            }
            if(x==w && dir == 4){
                do{
                    dir = rand()%((3 - 0) + 1) + 0;
                }while(dir==4);
            }
            if(y==0 && dir == 1){
                do{
                    dir = rand()%((3 - 0) + 1) + 0;
                }while(dir==1);
            }
            if(y==h && dir == 0){
                do{
                    dir = rand()%((3 - 0) + 1) + 0;
                }while(dir==0);
            }
            if(i==0){
                rooms_[x][y].x = x;
                rooms_[x][y].y = y;
                rooms_[x][y].type = START;
                rooms_[x][y].dir[dir] = true;
                start_ = &rooms_[startX][startY];
                //cout<<rooms_[x][y].type<<" "<<x<<" "<<y<<" "<<i<<endl;
                if(dir == 0){
                    y++;
                }else if(dir == 1){
                    y--;
                }else if(dir == 2){
                    x--;
                }else if(dir == 3){
                    x++;
                }
            }else if(i==(roomCount_ - 1)){
                rooms_[x][y].x = x;
                rooms_[x][y].y = y;
                rooms_[x][y].type = END;
                //cout<<rooms_[x][y].type<<" "<<x<<" "<<y<<" "<<i<<endl;
                end_ = &rooms_[x][y];
                if(pDir == 0){
                    rooms_[x][y].dir[1] = true;
                }else if(pDir == 1){
                    rooms_[x][y].dir[0] = true;
                }else if(pDir == 2){
                    rooms_[x][y].dir[3] = true;
                }else if(pDir == 3){
                    rooms_[x][y].dir[2] = true;
                }
            }else if(rooms_[x][y].type == 0){
                rooms_[x][y].x = x;
                rooms_[x][y].y = y;
                rooms_[x][y].type = rand()%((3 - 1) + 1) + 1; 
                //cout<<rooms_[x][y].type<<" "<<x<<" "<<y<<" "<<i<<endl;
                if(pDir == 0){
                    rooms_[x][y].dir[1] = true;
                }else if(pDir == 1){
                    rooms_[x][y].dir[0] = true;
                }else if(pDir == 2){
                    rooms_[x][y].dir[3] = true;
                }else if(pDir == 3){
                    rooms_[x][y].dir[2] = true;
                }
                rooms_[x][y].dir[dir] = true;
                if(dir == 0){
                    y++;
                }else if(dir == 1){
                    y--;
                }else if(dir == 2){
                    x--;
                }else if(dir == 3){
                    x++;
                }
            }else{
                //cout<<"dupe "<<rooms_[x][y].type<<" "<<x<<" "<<y<<" "<<i<<endl;
                if(pDir == 0){
                    rooms_[x][y].dir[1] = true;
                }else if(pDir == 1){
                    rooms_[x][y].dir[0] = true;
                }else if(pDir == 2){
                    rooms_[x][y].dir[3] = true;
                }else if(pDir == 3){
                    rooms_[x][y].dir[2] = true;
                }
                rooms_[x][y].dir[dir] = true;
                if(dir == 0){
                    y++;
                }else if(dir == 1){
                    y--;
                }else if(dir == 2){
                    x--;
                }else if(dir == 3){
                    x++;
                }
                i--;
            }
            //cout<<i<<endl;
            //cout<<roomCount_<<endl;
            pDir = dir;
        }
        
        width = width_;
        height = height_;
        roomCount = roomCount_;
        start = start_;
        end = end_;
        shop = shop_;
        rooms = rooms_;
    }
};

int main()
{
    Dungeon d;
    d.Create(5,5,5,20);
    /*for(int i=0;i<5;i++){
        for(int b=0;b<5;b++){
            cout<<d.rooms[i][b].type<<" ";
        }
        cout<<endl;
    }*/

    return 0;
}
