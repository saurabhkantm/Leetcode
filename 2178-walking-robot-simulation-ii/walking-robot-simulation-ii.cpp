class Robot {
public:
    int width;
    int height;
    string directions[4] = {"East","West","North","South"};
    int direction;
    int x = 0;
    int y = 0;
    Robot(int width, int height) {

        this->direction = 0;
        this->width = width;
        this->height = height; 

    }
    
    void step(int num) {

        int perimeter = 2 * (width + height - 2);
        int original = num;

        num %= perimeter;

        if (num == 0) {
            num = perimeter;
        }

        while(num){

            if(direction==0){
                int take = min(width-1-x,num);
                num = num - take;
                x = x + take;
            }
            else if(direction==1){
                int take = min(x,num);
                num = num - take;
                x = x - take;
            }
            else if(direction==2){
                int take = min(height-1-y,num);
                num = num - take;
                y = y + take; 
            }
            else{
                int take = min(y,num);
                num = num - take;
                y = y - take;
            }

            if(num>0){

                if(direction==0) direction = 2;
                else if(direction==2) direction = 1;
                else if(direction == 1) direction = 3;
                else direction = 0; 

            }

        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return directions[direction];
    }
};



